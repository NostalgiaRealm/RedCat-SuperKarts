/*
 * FUN_004458b8 at 004458b8
 * int __register FUN_004458b8(int param_1)
 * Address ranges: 004458b8-004458d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004458b8(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x24) != 0) {
    iVar1 = FUN_0040f70c(*(int *)(*(int *)(param_1 + 0x24) + 0x16c),param_1);
    return iVar1;
  }
  return -1;
}

