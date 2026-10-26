/*
 * FUN_00445198 at 00445198
 * undefined FUN_00445198(void)
 * Address ranges: 00445198-00445271
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445198(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  bool bVar1;
  BOOL BVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  LONG *pLVar4;
  RECT *pRVar5;
  byte bVar6;
  LONG aLStack_40 [4];
  WINDOWPLACEMENT WStack_30;
  
  bVar6 = 0;
  if ((((param_2 == param_1[0xc]) && (param_3 == param_1[0xd])) && (param_5 == param_1[0xe])) &&
     (param_4 == param_1[0xf])) {
    return;
  }
  bVar1 = FUN_00445a20((int)param_1);
  if ((bVar1) && (BVar2 = IsIconic((HWND)param_1[0x53]), BVar2 == 0)) {
    SetWindowPos((HWND)param_1[0x53],(HWND)0x0,param_2,param_3,param_5,param_4,0x14);
  }
  else {
    param_1[0xc] = param_2;
    param_1[0xd] = param_3;
    param_1[0xe] = param_5;
    param_1[0xf] = param_4;
    bVar1 = FUN_00445a20((int)param_1);
    if (bVar1) {
      WStack_30.length = 0x2c;
      GetWindowPlacement((HWND)param_1[0x53],&WStack_30);
      FUN_0043f054((int)param_1,aLStack_40);
      pLVar4 = aLStack_40;
      pRVar5 = &WStack_30.rcNormalPosition;
      for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
        pRVar5->left = *pLVar4;
        pLVar4 = pLVar4 + (uint)bVar6 * -2 + 1;
        pRVar5 = (RECT *)((int)pRVar5 + ((uint)bVar6 * -2 + 1) * 4);
      }
      SetWindowPlacement((HWND)param_1[0x53],&WStack_30);
    }
  }
  FUN_0043ed90((int)param_1);
  FUN_00403088(param_1,extraout_EDX,extraout_ECX);
  return;
}

