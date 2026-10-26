/*
 * FUN_00434364 at 00434364
 * undefined4 __register FUN_00434364(int * param_1, int * param_2)
 * Address ranges: 00434364-004343a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00434364(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_004118b0(param_1);
  iVar2 = FUN_004118b0(param_2);
  if (iVar1 == iVar2) {
    uVar3 = FUN_004118b0(param_1);
    uVar4 = FUN_00407ce4((int *)param_1[1],(int *)param_2[1],uVar3);
    if ((char)uVar4 != '\0') {
      return CONCAT31((int3)((uint)uVar4 >> 8),1);
    }
  }
  return 0;
}

