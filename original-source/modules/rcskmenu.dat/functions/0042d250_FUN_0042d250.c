/*
 * FUN_0042d250 at 0042d250
 * undefined FUN_0042d250(void)
 * Address ranges: 0042d250-0042d2b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d250(int *param_1,UINT *param_2)

{
  HWND pHVar1;
  UINT UVar2;
  HWND hWnd;
  UINT UVar3;
  UINT UVar4;
  
  if (param_1[0x8f] == 0) {
    FUN_0044329c((int)param_1,param_2);
  }
  else {
    if (*param_2 != 5) {
      UVar2 = param_2[2];
      UVar4 = param_2[1];
      UVar3 = *param_2;
      pHVar1 = (HWND)param_1[0x8f];
      hWnd = (HWND)FUN_00445724(param_1);
      UVar2 = DefFrameProcA(hWnd,pHVar1,UVar3,UVar4,UVar2);
      param_2[3] = UVar2;
      return;
    }
    UVar2 = param_2[2];
    UVar4 = param_2[1];
    UVar3 = *param_2;
    pHVar1 = (HWND)FUN_00445724(param_1);
    UVar2 = DefWindowProcA(pHVar1,UVar3,UVar4,UVar2);
    param_2[3] = UVar2;
  }
  return;
}

