/*
 * FUN_00466930 at 00466930
 * undefined FUN_00466930(void)
 * Address ranges: 00466930-004669bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466930(int *param_1)

{
  int iVar1;
  int *piVar2;
  HWND hWnd;
  HWND pHVar3;
  BOOL BVar4;
  undefined4 extraout_ECX;
  
  if ((int *)param_1[0x84] != (int *)0x0) {
    iVar1 = (**(code **)(*(int *)param_1[0x84] + 0x14))();
    if (0 < iVar1) {
      piVar2 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e2e8,'\x01',extraout_ECX);
      param_1[0x82] = (int)piVar2;
      (**(code **)(*piVar2 + 8))(piVar2,param_1[0x84]);
      iVar1 = FUN_00466230(param_1);
      param_1[0x81] = iVar1;
    }
  }
  hWnd = GetFocus();
  if (hWnd != (HWND)0x0) {
    pHVar3 = (HWND)FUN_00445724(param_1);
    if (hWnd != pHVar3) {
      pHVar3 = (HWND)FUN_00445724(param_1);
      BVar4 = IsChild(pHVar3,hWnd);
      if (BVar4 == 0) goto LAB_004669a9;
    }
    SetFocus((HWND)0x0);
  }
LAB_004669a9:
  FUN_00444a14(param_1);
  param_1[0x53] = 0;
  return;
}

