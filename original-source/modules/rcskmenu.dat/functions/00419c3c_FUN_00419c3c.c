/*
 * FUN_00419c3c at 00419c3c
 * undefined __register FUN_00419c3c(HBITMAP param_1, HPALETTE param_2, LPBITMAPINFO param_3, uint param_4, LPVOID param_5)
 * Address ranges: 00419c3c-00419cd8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00419c3c(HBITMAP param_1,HPALETTE param_2,LPBITMAPINFO param_3,uint param_4,LPVOID param_5)

{
  HDC hdc;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar1;
  HPALETTE local_c;
  
  FUN_00419aec(param_1,(uint *)param_3,param_4);
  local_c = (HPALETTE)0x0;
  hdc = CreateCompatibleDC((HDC)0x0);
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffffd8;
  if (param_2 != (HPALETTE)0x0) {
    local_c = SelectPalette(hdc,param_2,0);
    RealizePalette(hdc);
  }
  GetDIBits(hdc,param_1,0,(param_3->bmiHeader).biHeight,param_5,param_3,0);
  *in_FS_OFFSET = uVar1;
  if (local_c != (HPALETTE)0x0) {
    SelectPalette(hdc,local_c,0);
  }
  DeleteDC(hdc);
  return;
}

