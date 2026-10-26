/*
 * FUN_0041e4f0 at 0041e4f0
 * BYTE __register FUN_0041e4f0(void)
 * Address ranges: 0041e4f0-0041e532
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

BYTE FUN_0041e4f0(void)

{
  HDC hdc;
  HGDIOBJ pvVar1;
  BOOL BVar2;
  BYTE BVar3;
  tagTEXTMETRICA tStack_40;
  
  BVar3 = '\x01';
  hdc = GetDC((HWND)0x0);
  if (hdc != (HDC)0x0) {
    pvVar1 = SelectObject(hdc,DAT_0047d690);
    if (pvVar1 != (HGDIOBJ)0x0) {
      BVar2 = GetTextMetricsA(hdc,&tStack_40);
      if (BVar2 != 0) {
        BVar3 = tStack_40.tmCharSet;
      }
    }
    ReleaseDC((HWND)0x0,hdc);
  }
  return BVar3;
}

