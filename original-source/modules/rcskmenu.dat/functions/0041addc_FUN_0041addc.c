/*
 * FUN_0041addc at 0041addc
 * undefined FUN_0041addc(void)
 * Address ranges: 0041addc-0041ae6e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041addc(int *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar5;
  
  if ((param_2 != (int *)0x0) &&
     (uVar3 = FUN_00403024(param_2,(int)&PTR_FUN_004166f0), param_3 = extraout_ECX,
     (char)uVar3 == '\0')) {
    FUN_0040fca8(param_1,param_2);
    return;
  }
  iVar5 = 0;
  piVar1 = (int *)param_1[8];
  if (piVar1 != (int *)0x0) {
    iVar5 = piVar1[5];
    FUN_0041bd54(piVar1);
    param_3 = extraout_ECX_00;
  }
  if (param_2 == (int *)0x0) {
    iVar4 = FUN_00402e7c((int *)&PTR_FUN_00416690,'\x01',param_3);
    param_1[8] = iVar4;
    *(undefined1 *)(param_1 + 9) = 1;
  }
  else {
    param_1[8] = param_2[8];
    *(char *)(param_1 + 9) = (char)param_2[9];
  }
  FUN_0041bd50(param_1[8]);
  iVar4 = (**(code **)(*param_1 + 0x24))();
  if ((iVar5 == iVar4) || (iVar5 = (**(code **)(*param_1 + 0x24))(), iVar5 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  *(undefined1 *)((int)param_1 + 0x1a) = uVar2;
  (**(code **)(*param_1 + 0x10))(param_1,param_1);
  return;
}

