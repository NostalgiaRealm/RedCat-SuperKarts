/*
 * FUN_0045196c at 0045196c
 * undefined __register FUN_0045196c(int * param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 0045196c-004519f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045196c(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  int iVar6;
  int *piVar7;
  
  uVar1 = FUN_00403024(param_1,(int)&PTR_FUN_00416860);
  if ((char)uVar1 != '\0') {
    FUN_00451764(param_1,extraout_EDX,extraout_ECX,param_4);
    return;
  }
  iVar6 = 0x18;
  iVar2 = (**(code **)(*param_1 + 0x20))();
  iVar3 = (**(code **)(*param_1 + 0x2c))();
  FUN_00452624(*(int **)(param_4 + -4),iVar3,iVar2,iVar6);
  puVar4 = (undefined4 *)FUN_00451eac(*(int **)(param_4 + -4),extraout_EDX_00,extraout_ECX_00);
  FUN_00402b54(puVar4,*(uint *)(*(int *)(param_4 + -4) + 0x7c),0);
  piVar7 = param_1;
  piVar5 = (int *)FUN_00451e40(*(int *)(param_4 + -4),extraout_EDX_01,extraout_ECX_01);
  FUN_00418458(piVar5,0,0,piVar7);
  uVar1 = (**(code **)(*param_1 + 0x28))();
  (**(code **)(**(int **)(param_4 + -4) + 0x3c))(*(int **)(param_4 + -4),uVar1);
  return;
}

