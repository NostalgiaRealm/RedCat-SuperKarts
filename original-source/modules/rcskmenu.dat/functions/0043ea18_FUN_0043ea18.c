/*
 * FUN_0043ea18 at 0043ea18
 * undefined1 __register FUN_0043ea18(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 0043ea18-0043ea92
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_0043ea18(int *param_1,undefined4 param_2,undefined4 param_3)

{
  HPALETTE pHVar1;
  HDC hdc;
  UINT UVar2;
  undefined1 local_13;
  HWND pHStack_10;
  
  local_13 = 0;
  if (*(char *)((int)param_1 + 0x47) != '\0') {
    pHVar1 = (HPALETTE)FUN_00403088(param_1,param_2,param_3);
    if (pHVar1 != (HPALETTE)0x0) {
      hdc = (HDC)(**(code **)(*param_1 + 0x44))(param_1,&pHStack_10);
      pHVar1 = SelectPalette(hdc,pHVar1,-(uint)((char)param_2 != '\x01'));
      UVar2 = RealizePalette(hdc);
      if (UVar2 != 0) {
        (**(code **)(*param_1 + 0x74))();
      }
      SelectPalette(hdc,pHVar1,-1);
      ReleaseDC(pHStack_10,hdc);
      local_13 = 1;
    }
  }
  return local_13;
}

