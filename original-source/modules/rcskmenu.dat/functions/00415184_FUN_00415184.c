/*
 * FUN_00415184 at 00415184
 * undefined __register FUN_00415184(int param_1, int param_2)
 * Address ranges: 00415184-004151c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00415184(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x40) + 8);
  if (-1 < iVar3 + -1) {
    iVar2 = 0;
    do {
      iVar1 = FUN_0040f6b0(*(undefined4 **)(param_1 + 0x40),iVar2);
      if (param_2 == iVar1) {
        *(undefined4 *)(param_2 + 0x10) = 0;
        FUN_0040f550(*(int **)(param_1 + 0x40),iVar2);
        return;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

