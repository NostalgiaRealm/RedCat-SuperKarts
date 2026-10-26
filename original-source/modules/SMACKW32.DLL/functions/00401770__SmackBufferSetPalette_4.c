/*
 * _SmackBufferSetPalette@4 at 00401770
 * UINT __stdcall _SmackBufferSetPalette@4(int param_1)
 * Address ranges: 00401770-0040180f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

UINT _SmackBufferSetPalette_4(int param_1)

{
  HDC hdc;
  HPALETTE hPal;
  UINT UVar1;
  
                    /* 0x1770  7  _SmackBufferSetPalette@4 */
  if ((param_1 != 0) && (*(int *)(param_1 + 0xc) == 0)) {
    if (*(int *)(param_1 + 0x458) == 0) {
      FUN_00402940();
    }
    hdc = GetDC(*(HWND *)(param_1 + 0x464));
    hPal = SelectPalette(hdc,*(HPALETTE *)(param_1 + 0x458),0);
    UVar1 = RealizePalette(hdc);
    if (*(int *)(param_1 + 0x444) != 0) {
      InvalidateRect(*(HWND *)(param_1 + 0x464),(RECT *)0x0,0);
    }
    SelectPalette(hdc,hPal,0);
    ReleaseDC(*(HWND *)(param_1 + 0x464),hdc);
    return UVar1;
  }
  return 0;
}

