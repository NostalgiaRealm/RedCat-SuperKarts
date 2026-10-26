/*
 * FUN_004241ec at 004241ec
 * undefined FUN_004241ec(void)
 * Address ranges: 004241ec-00424226
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004241ec(int *param_1,undefined4 param_2,undefined4 param_3)

{
  HWND hWnd;
  uint uVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int nIndex;
  
  if (((char)param_1[0x7e] != '\0') && ((*(byte *)(param_1 + 0x11) & 1) == 0)) {
    nIndex = -0x10;
    hWnd = (HWND)FUN_00445724(param_1);
    uVar1 = GetWindowLongA(hWnd,nIndex);
    param_3 = extraout_ECX;
    if ((uVar1 & 4) == 0) {
      FUN_00423cb0(param_1);
      param_3 = extraout_ECX_00;
    }
  }
  FUN_00444b80(param_1,param_2,param_3);
  return;
}

