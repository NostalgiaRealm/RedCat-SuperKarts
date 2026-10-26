/*
 * FUN_00402744 at 00402744
 * undefined __register FUN_00402744(int * param_1, int param_2)
 * Address ranges: 00402744-00402790
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402744(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (param_2 == 0) {
      *param_1 = 0;
      iVar1 = (*(code *)PTR_FUN_0047b028)(iVar1);
      if (iVar1 == 0) {
        return;
      }
      FUN_004027a0(CONCAT31((int3)((uint)iVar1 >> 8),2));
      return;
    }
    iVar1 = (*(code *)PTR_FUN_0047b02c)(iVar1);
    if (iVar1 != 0) {
      *param_1 = iVar1;
      return;
    }
LAB_00402775:
    FUN_004027a0(1);
    return;
  }
  if (param_2 != 0) {
    iVar1 = (*(code *)PTR_FUN_0047b024)(param_2);
    if (iVar1 == 0) goto LAB_00402775;
    *param_1 = iVar1;
  }
  return;
}

