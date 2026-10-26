/*
 * FUN_0045fde4 at 0045fde4
 * undefined FUN_0045fde4(void)
 * Address ranges: 0045fde4-0045fe36
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045fde4(int *param_1,int param_2)

{
  HWND pHVar1;
  UINT uElapse;
  UINT_PTR UVar2;
  TIMERPROC lpTimerFunc;
  
  (**(code **)(*param_1 + -0x10))(param_1,param_2);
  if (*(int *)(param_2 + 4) == 1) {
    UVar2 = 1;
    pHVar1 = (HWND)FUN_00445724(param_1);
    KillTimer(pHVar1,UVar2);
    lpTimerFunc = (TIMERPROC)0x0;
    uElapse = param_1[0x88];
    UVar2 = 2;
    pHVar1 = (HWND)FUN_00445724(param_1);
    SetTimer(pHVar1,UVar2,uElapse,lpTimerFunc);
    FUN_0045fe38(param_1);
  }
  if (*(int *)(param_2 + 4) == 2) {
    FUN_0045fe38(param_1);
  }
  return;
}

