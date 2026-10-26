/*
 * FUN_0045fca8 at 0045fca8
 * undefined FUN_0045fca8(void)
 * Address ranges: 0045fca8-0045fce7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045fca8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  HWND pHVar1;
  UINT_PTR UVar2;
  
  FUN_00440c6c((int)param_1,param_2,param_3,param_4,param_5);
  UVar2 = 1;
  pHVar1 = (HWND)FUN_00445724(param_1);
  KillTimer(pHVar1,UVar2);
  UVar2 = 2;
  pHVar1 = (HWND)FUN_00445724(param_1);
  KillTimer(pHVar1,UVar2);
  return;
}

