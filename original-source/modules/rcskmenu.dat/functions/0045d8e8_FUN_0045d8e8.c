/*
 * FUN_0045d8e8 at 0045d8e8
 * undefined FUN_0045d8e8(void)
 * Address ranges: 0045d8e8-0045d9be
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045d8e8(int param_1,undefined4 param_2,undefined *param_3,LPRECT param_4,int *param_5)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  LPCSTR lpchText;
  HDC hdc;
  LPRECT lprc;
  
  if (param_5 == (int *)0x0) {
    FUN_00403b34("Assertion failure");
  }
  uVar1 = FUN_00403024(param_5,(int)&PTR_FUN_00452e7c);
  if ((char)uVar1 == '\0') {
    FUN_00403b34("Assertion failure");
  }
  piVar2 = FUN_00453450((int)param_5,6);
  iVar3 = (**(code **)(*piVar2 + 0x20))();
  FUN_0040ebe8(0,0,param_2,&param_4->left,iVar3 + -1);
  piVar2 = *(int **)(*(int *)(param_1 + 0x1f0) + 0xc);
  (**(code **)(*piVar2 + 8))(piVar2,param_5[0x14]);
  uVar4 = FUN_00441578(param_1);
  uVar4 = uVar4 | 0xc10;
  iVar3 = -1;
  lprc = param_4;
  lpchText = FUN_00403f94(param_3);
  hdc = (HDC)FUN_00418994(*(int **)(param_1 + 0x1f0));
  DrawTextA(hdc,lpchText,iVar3,lprc,uVar4);
  param_4->right = param_4->right + 6;
  piVar2 = FUN_00453450((int)param_5,6);
  iVar3 = (**(code **)(*piVar2 + 0x20))();
  param_4->bottom = iVar3 + param_4->top + -1;
  param_4->bottom = param_4->bottom + -1;
  return;
}

