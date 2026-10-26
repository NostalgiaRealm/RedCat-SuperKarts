/*
 * FUN_004456a4 at 004456a4
 * undefined FUN_004456a4(void)
 * Address ranges: 004456a4-004456db
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004456a4(int *param_1)

{
  int *piVar1;
  HWND hWnd;
  undefined4 extraout_ECX;
  
  piVar1 = FUN_004298bc(param_1);
  if (piVar1 != (int *)0x0) {
    FUN_0042d3b4(piVar1,param_1,extraout_ECX);
    return;
  }
  if (param_1[0x59] == 0) {
    FUN_004298e4(param_1);
  }
  else {
    hWnd = (HWND)FUN_00445724(param_1);
    SetFocus(hWnd);
  }
  return;
}

