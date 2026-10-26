/*
 * _SmackBufferFocused@4 at 00401b40
 * bool __stdcall _SmackBufferFocused@4(int param_1)
 * Address ranges: 00401b40-00401b7f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool _SmackBufferFocused_4(int param_1)

{
  HWND pHVar1;
  uint uVar2;
  
                    /* 0x1b40  4  _SmackBufferFocused@4 */
  if (param_1 == 0) {
    return false;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    pHVar1 = GetFocus();
    uVar2 = (uint)(pHVar1 == *(HWND *)(param_1 + 0x464));
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x460);
  }
  return uVar2 != 0;
}

