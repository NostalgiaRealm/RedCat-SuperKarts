// Scratch check (read-only research): what rcskspel.dat's wheel path makes of a virtual joystick.
// 0x4ba5e0: centre = first joyGetPosEx reading, min/max = joyGetDevCapsA (winmm.js: 0..65535).
// 0x4bac90(1, 100, 100): +-0.1 (double at 0x502060) of the centre snaps to half; else integer X / ((max-c)/half).
// 0x42ef90 clamps 0..100; 0x4341d0 (stuur_model 0): steering = x*2-100, throttle/brake from y.
// Compared with the JS reconstruction's nativeAnalogFromNormalized (source/simulation/native-input.js).
const K = 0.1, MIN = 0, MAX = 65535;
function axis(v, c, half) {
  if (v <= c * K + c) {
    if (c - c * K <= v) return half;
    return Math.floor(v / Math.trunc((c - MIN) / half));
  }
  return Math.floor(v / Math.trunc((MAX - c) / half));
}
function original(s, d, centre = { x: 32767, y: 32767 }) {
  const X = Math.round((s + 1) * 32767), Y = Math.round((1 - d) * 32767);
  let x = axis(X, centre.x, 50), yRaw = axis(Y, centre.y, 50);
  let y = (yRaw === 50) ? 50 : 100 - yRaw;   // the Y branches return 2*half - Y/step
  x = Math.max(0, Math.min(100, x)); y = Math.max(0, Math.min(100, y));
  return { steering: x * 2 - 100, throttle: y < 50 ? 0 : y * 2 - 100, brake: y < 50 ? (50 - y) * 2 : 0 };
}
function jsPort(s, d) {
  const x = Math.round((s + 1) * 50), y = Math.round((d + 1) * 50);
  return { steering: x * 2 - 100, throttle: y < 50 ? 0 : y * 2 - 100, brake: y < 50 ? (50 - y) * 2 : 0 };
}
const out = [];
out.push('steer  original-steering  js-port-steering');
for (const s of [-1, -0.75, -0.5, -0.25, -0.12, -0.1, -0.08, -0.04, 0, 0.04, 0.08, 0.1, 0.12, 0.25, 0.5, 0.75, 1])
  out.push(`${String(s).padStart(5)}  ${String(original(s, 0).steering).padStart(17)}  ${String(jsPort(s, 0).steering).padStart(16)}`);
out.push('', 'drive  original-throttle/brake  js-port-throttle/brake');
for (const d of [-1, -0.5, -0.1, -0.05, 0, 0.05, 0.1, 0.15, 0.5, 1]) {
  const o = original(0, d), j = jsPort(0, d);
  out.push(`${String(d).padStart(5)}  ${String(o.throttle + '/' + o.brake).padStart(23)}  ${String(j.throttle + '/' + j.brake).padStart(22)}`);
}
out.push('', 'calibrated while a finger held steer=+0.5 (centre X=49151), then released (X=32767) and full left/right:');
const held = { x: Math.round(1.5 * 32767), y: 32767 };
for (const s of [-1, 0, 0.5, 1]) out.push(`  steer ${s}: original steering ${original(s, 0, held).steering}`);
console.log(out.join('\n'));
