/*
 * FUN_004193e4 at 004193e4
 * int __register FUN_004193e4(int param_1)
 * Address ranges: 004193e4-00419469;00419471-00419478
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004193e4(int param_1)

{
  HDC hdc;
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar2;
  
  if (DAT_0047d67c != (HPALETTE)0x0) {
    hdc = GetDC((HWND)0x0);
    uVar2 = *in_FS_OFFSET;
    *in_FS_OFFSET = &stack0xffffffe4;
    iVar1 = GetDeviceCaps(hdc,0x68);
    if (0xf < iVar1) {
      GetPaletteEntries(DAT_0047d67c,0,8,(LPPALETTEENTRY)(param_1 + 4));
      GetPaletteEntries(DAT_0047d67c,8,8,
                        (LPPALETTEENTRY)(param_1 + -0x1c + (uint)*(ushort *)(param_1 + 2) * 4));
    }
    *in_FS_OFFSET = uVar2;
    iVar1 = ReleaseDC((HWND)0x0,hdc);
    return iVar1;
  }
  return param_1 & 0xffffff00;
}

