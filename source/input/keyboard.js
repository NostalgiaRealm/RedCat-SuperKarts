// Browser keys -> Windows virtual-key codes, for GetAsyncKeyState (the race's only keyboard path, 0x4b3830).

const CODE_TO_VK = {
  ArrowLeft: 0x25, ArrowUp: 0x26, ArrowRight: 0x27, ArrowDown: 0x28,
  ControlLeft: 0x11, ControlRight: 0x11, AltLeft: 0x12, AltRight: 0x12, ShiftLeft: 0x10, ShiftRight: 0x10,
  Space: 0x20, Enter: 0x0D, NumpadEnter: 0x0D, Escape: 0x1B, Backspace: 0x08, Tab: 0x09,
  Home: 0x24, End: 0x23, PageUp: 0x21, PageDown: 0x22, Insert: 0x2D, Delete: 0x2E, NumLock: 0x90,
  NumpadMultiply: 0x6A, NumpadAdd: 0x6B, NumpadSubtract: 0x6D, NumpadDecimal: 0x6E, NumpadDivide: 0x6F,
};
for (let k = 0; k < 10; k++) { CODE_TO_VK['Digit' + k] = 0x30 + k; CODE_TO_VK['Numpad' + k] = 0x60 + k; }
for (let k = 0; k < 26; k++) CODE_TO_VK['Key' + String.fromCharCode(65 + k)] = 0x41 + k;
for (let k = 1; k <= 12; k++) CODE_TO_VK['F' + k] = 0x6F + k;

export function vkOf(e) {
  return CODE_TO_VK[e.code] || 0;
}
