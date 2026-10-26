/*
 * FUN_00438210 at 00438210
 * undefined __register FUN_00438210(int * param_1, int param_2, int param_3)
 * Address ranges: 00438210-004382bc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00438210(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int extraout_ECX;
  
  iVar1 = param_3;
  if (*(int *)(param_3 + 0x58) != 0) {
    FUN_004358cc((undefined4 *)PTR_PTR_0047c9cc);
    iVar1 = extraout_ECX;
  }
  if (param_1[0x14] == 0) {
    iVar1 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',iVar1);
    param_1[0x14] = iVar1;
  }
  iVar1 = param_2 + -1;
  if ((-1 < iVar1) && (iVar1 < *(int *)(param_1[0x14] + 8))) {
    iVar2 = FUN_0040f6b0((undefined4 *)param_1[0x14],iVar1);
    if (*(byte *)(param_3 + 0x33) < *(byte *)(iVar2 + 0x33)) {
      iVar1 = FUN_0040f6b0((undefined4 *)param_1[0x14],iVar1);
      FUN_00438028(param_3,*(byte *)(iVar1 + 0x33));
    }
  }
  FUN_004366d4((int)param_1,param_2,*(byte *)(param_3 + 0x33));
  FUN_0040f72c((int *)param_1[0x14],param_2,param_3);
  *(int **)(param_3 + 0x58) = param_1;
  *(int **)(param_3 + 0x7c) = param_1;
  *(code **)(param_3 + 0x78) = FUN_00438438;
  if (param_1[10] != 0) {
    FUN_00436650(param_1);
  }
  iVar1 = FUN_00438084((int)param_1);
  (**(code **)(*param_1 + 0x38))(param_1,iVar1 == 1);
  return;
}

