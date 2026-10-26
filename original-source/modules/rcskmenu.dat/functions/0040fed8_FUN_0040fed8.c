/*
 * FUN_0040fed8 at 0040fed8
 * int __register FUN_0040fed8(int param_1)
 * Address ranges: 0040fed8-0040feec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040fed8(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = FUN_0040f70c(*(int *)(*(int *)(param_1 + 4) + 8),param_1);
    return iVar1;
  }
  return -1;
}

