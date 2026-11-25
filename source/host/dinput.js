// DirectInput for rcskspel.dat: only the system mouse. 0x431780 creates it (DirectInputCreateA version 0x500,
// CreateDevice(GUID_SysMouse), c_dfDIMouse, exclusive foreground, Acquire, GetCapabilities); every frame
// 0x4318a0 reads a 16-byte DIMOUSESTATE with GetDeviceState and re-acquires on DIERR_INPUTLOST. The keyboard
// goes through GetAsyncKeyState (0x4b3830), not DirectInput. Devices are told apart by the first dword of
// their GUID, as in the Spookkasteel host (source/host/dinput.js there).
//   host.input.takeMouseDelta() -> { dx, dy, dz }, host.input.mouseButtons (bit 0 left, bit 1 right)

const S_OK = 0;
const DIERR_UNSUPPORTED = 0x80004001 | 0;
const REGDB_E_CLASSNOTREG = 0x80040154 | 0;

function slots(count, entries) {
  const out = new Array(count).fill(null);
  for (const [k, name, n, fn] of entries) out[k] = [name, n, fn];
  return out;
}

export function installDinput(m, host) {
  const { u8, u32, i32 } = m;
  const noop = () => S_OK;
  const release = (self) => Math.max(--self.refs, 0);
  const KEYBOARD = 0x6F1D2B61, MOUSE = 0x6F1D2B60;
  const devices = { [KEYBOARD]: { kind: 'keyboard' }, [MOUSE]: { kind: 'mouse' } };
  const DEV = 'IDirectInputDeviceA';

  m.defineInterface(DEV, slots(18, [
    [0, 'QueryInterface', 2, (self, riid, pOut) => { self.refs++; u32[pOut >> 2] = self.addr; return S_OK; }],
    [1, 'AddRef', 0, (self) => ++self.refs],
    [2, 'Release', 0, release],
    [3, 'GetCapabilities', 1, (self, p) => {
      const size = u32[p >> 2];
      u8.fill(0, p + 4, p + size);
      u32[(p + 4) >> 2] = 1;                                   // DIDC_ATTACHED
      if (self.kind === 'mouse') { u32[(p + 8) >> 2] = 0x0112; u32[(p + 12) >> 2] = 3; u32[(p + 16) >> 2] = 3; }
      else { u32[(p + 8) >> 2] = 0x0403; u32[(p + 16) >> 2] = 101; }
      return S_OK;
    }],
    [5, 'GetProperty', 2, () => DIERR_UNSUPPORTED],
    [6, 'SetProperty', 2, noop],
    [7, 'Acquire', 0, (self) => { self.acquired = true; return S_OK; }],
    [8, 'Unacquire', 0, (self) => { self.acquired = false; return S_OK; }],
    [9, 'GetDeviceState', 2, (self, size, p) => {
      u8.fill(0, p, p + size);
      const input = host.input;
      if (self.kind === 'mouse' && input) {
        const d = input.takeMouseDelta ? input.takeMouseDelta() : null;
        if (d) { i32[p >> 2] = d.dx | 0; i32[(p + 4) >> 2] = d.dy | 0; i32[(p + 8) >> 2] = d.dz | 0; }
        const b = input.mouseButtons | 0;
        if (size >= 16) { u8[p + 12] = b & 1 ? 0x80 : 0; u8[p + 13] = b & 2 ? 0x80 : 0; u8[p + 14] = b & 4 ? 0x80 : 0; }
      }
      return S_OK;
    }],
    [10, 'GetDeviceData', 4, (self, cb, pData, pCount) => { if (pCount) u32[pCount >> 2] = 0; return S_OK; }],
    [11, 'SetDataFormat', 1, noop],
    [12, 'SetEventNotification', 1, noop],
    [13, 'SetCooperativeLevel', 2, noop],
  ]));
  m.defineInterface('IDirectInputA', slots(8, [
    [0, 'QueryInterface', 2, (self, riid, pOut) => { self.refs++; u32[pOut >> 2] = self.addr; return S_OK; }],
    [1, 'AddRef', 0, (self) => ++self.refs],
    [2, 'Release', 0, release],
    [3, 'CreateDevice', 3, (self, guid, pOut) => {
      const d = devices[u32[guid >> 2]];
      if (!d) { u32[pOut >> 2] = 0; return REGDB_E_CLASSNOTREG; }
      if (!d.addr) m.newObject(DEV, d); else d.refs++;
      u32[pOut >> 2] = d.addr;
      return S_OK;
    }],
    [4, 'EnumDevices', 4, noop],
  ]));
  host.dinput = {};
  m.newObject('IDirectInputA', host.dinput);
  m.api('DINPUT.DLL!DirectInputCreateA', 4, (hinst, ver, pOut) => {
    host.dinput.refs++;
    u32[pOut >> 2] = host.dinput.addr;
    return S_OK;
  });
}
