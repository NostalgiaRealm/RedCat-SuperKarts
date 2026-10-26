/*
 * FUN_004382c0 at 004382c0
 * undefined __register FUN_004382c0(int * param_1, int param_2)
 * Address ranges: 004382c0-0043832c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004382c0(int *param_1,int param_2)

{
  int iVar1;
  
  if ((-1 < param_2) && (param_1[0x14] != 0)) {
    iVar1 = FUN_00438084((int)param_1);
    if (param_2 < iVar1) goto LAB_004382e6;
  }
  FUN_004358cc((undefined4 *)PTR_PTR_0047c77c);
LAB_004382e6:
  iVar1 = FUN_0040f6b0((undefined4 *)param_1[0x14],param_2);
  FUN_0040f550((int *)param_1[0x14],param_2);
  *(undefined4 *)(iVar1 + 0x58) = 0;
  *(undefined4 *)(iVar1 + 0x78) = 0;
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  if (param_1[10] != 0) {
    FUN_00436650(param_1);
  }
  iVar1 = FUN_00438084((int)param_1);
  (**(code **)(*param_1 + 0x38))(param_1,iVar1 == 0);
  return;
}

