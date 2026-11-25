// Can this browser run the recompiled race? Asked once when the page opens (source/main.js), so the visitor is told at
// once, not after choosing a race. What the race needs (RedCat Spookkasteel's game.js unsupportedReason, for this port):
//   isolation  shared memory between the page, the game worker and the render worker (SharedArrayBuffer, Atomics.wait):
//              only on a cross-origin isolated page, which the server makes with Cross-Origin-Opener-Policy: same-origin
//              and Cross-Origin-Embedder-Policy: require-corp (docs/hosting.md)
//   canvas     the race draws in the render worker on the page's canvas (canvas.transferControlToOffscreen)
//   webgl2     WebGL 2 on an OffscreenCanvas (source/render/gl-renderer.js)
//   wasm       the module's WebAssembly features: sign extension (i32.extend8_s/16_s), bulk memory (memory.copy, fill;
//              a DataCount section) and exported mutable globals (the registers g_*; tools/recomp/wasmgen.py), checked by
//              validating a module of a few bytes that uses each
// unsupported() is null or { reason, detail } (detail: a sentence in English for the console, for whoever runs the site).
const PROBE = new Uint8Array([
  0x00, 0x61, 0x73, 0x6d, 0x01, 0x00, 0x00, 0x00,
  0x01, 0x04, 0x01, 0x60, 0x00, 0x00,                         // type: () -> ()
  0x03, 0x02, 0x01, 0x00,                                     // one function
  0x05, 0x03, 0x01, 0x00, 0x01,                               // memory, 1 page
  0x06, 0x06, 0x01, 0x7f, 0x01, 0x41, 0x00, 0x0b,             // a mutable i32 global ...
  0x07, 0x05, 0x01, 0x01, 0x67, 0x03, 0x00,                   // ... exported
  0x0c, 0x01, 0x00,                                           // DataCount
  0x0a, 0x1b, 0x01, 0x19, 0x00,
  0x41, 0x00, 0xc0, 0x1a,                                     // i32.extend8_s
  0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0xfc, 0x0a, 0x00, 0x00, // memory.copy
  0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0xfc, 0x0b, 0x00,       // memory.fill
  0x0b,
]);

let known;
export function unsupported() {
  if (known !== undefined) return known;
  let reason = null, detail = '';
  if (!(self.crossOriginIsolated && typeof SharedArrayBuffer === 'function' && typeof Atomics === 'object')) {
    reason = 'isolation';
    detail = 'The page is not cross-origin isolated, so it cannot share memory with the game worker. The server has to send Cross-Origin-Opener-Policy: same-origin and Cross-Origin-Embedder-Policy: require-corp on every answer (node tools/serve.mjs does; docs/hosting.md).';
  } else if (typeof WebAssembly !== 'object' || !WebAssembly.validate(PROBE)) {
    reason = 'wasm';
    detail = 'This browser\'s WebAssembly lacks sign extension, bulk memory or exported mutable globals, which the recompiled race uses.';
  } else if (typeof HTMLCanvasElement === 'undefined' || typeof HTMLCanvasElement.prototype.transferControlToOffscreen !== 'function' || typeof OffscreenCanvas !== 'function') {
    reason = 'canvas';
    detail = 'This browser cannot hand a canvas to a worker (no transferControlToOffscreen or OffscreenCanvas), which is where the race draws.';
  } else {
    let gl = null;
    try { gl = new OffscreenCanvas(1, 1).getContext('webgl2'); } catch (e) { gl = null; }
    if (!gl) {
      reason = 'webgl2';
      let page = false;
      try { page = !!document.createElement('canvas').getContext('webgl2'); } catch (e) { page = false; }
      detail = page ? 'WebGL 2 works on the page but not on an OffscreenCanvas, which is where the race draws. The page is cross-origin isolated; the server is not the cause.'
        : 'This browser gives no WebGL 2 context at all (the graphics chip is blocked or WebGL is switched off). The page is cross-origin isolated; the server is not the cause.';
    } else {
      const lose = gl.getExtension('WEBGL_lose_context');
      if (lose) lose.loseContext();
    }
  }
  known = reason ? { reason, detail } : null;
  return known;
}

/** The old version beside this one (classic/, the JavaScript port), when the server has it: its address, else null. */
export async function classicAddress() {
  try {
    const url = new URL('classic/', document.baseURI);
    const r = await fetch(new URL('index.html', url), { method: 'HEAD', cache: 'no-store' });
    return r.ok ? url.href : null;
  } catch (e) { return null; }
}
