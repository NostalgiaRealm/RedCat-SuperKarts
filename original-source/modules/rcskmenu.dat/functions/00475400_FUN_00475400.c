/*
 * FUN_00475400 at 00475400
 * undefined4 __register FUN_00475400(int param_1)
 * Address ranges: 00475400-0047546c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00475400(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  
  FUN_00475490(param_1);
  FUN_00475780();
  FUN_00475940();
  iVar1 = *(int *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c) + 0x14);
  if (iVar1 == -1) {
    iVar1 = FUN_00457c6c(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98));
    *(int *)(param_1 + 0x3a4) = iVar1;
    uVar3 = extraout_ECX_00;
  }
  else {
    *(int *)(param_1 + 0x3a4) = iVar1;
    uVar3 = extraout_ECX;
  }
  piVar2 = FUN_00459f94((int *)&PTR_FUN_00459f34,'\x01',uVar3);
  *(int **)(param_1 + 0x3a8) = piVar2;
  uVar3 = FUN_00475ab4(param_1);
  return CONCAT31((int3)((uint)uVar3 >> 8),1);
}

