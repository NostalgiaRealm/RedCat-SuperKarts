/*
 * FUN_0045fc24 at 0045fc24
 * undefined FUN_0045fc24(void)
 * Address ranges: 0045fc24-0045fca4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045fc24(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  HWND pHVar2;
  UINT_PTR UVar3;
  UINT UVar4;
  TIMERPROC pTVar5;
  
  FUN_00440988((int)param_1,param_2,param_3,param_4,param_5);
  iVar1 = FUN_0045fac0(param_1,param_1[0x81]);
  if (param_5 < iVar1) {
    FUN_0045fa00(param_1,param_1[0x7e]);
    pTVar5 = (TIMERPROC)0x0;
    UVar4 = param_1[0x87];
    UVar3 = 1;
    pHVar2 = (HWND)FUN_00445724(param_1);
    SetTimer(pHVar2,UVar3,UVar4,pTVar5);
  }
  else {
    FUN_0045fa4c(param_1,param_1[0x7e]);
    pTVar5 = (TIMERPROC)0x0;
    UVar4 = param_1[0x87];
    UVar3 = 1;
    pHVar2 = (HWND)FUN_00445724(param_1);
    SetTimer(pHVar2,UVar3,UVar4,pTVar5);
  }
  return;
}

