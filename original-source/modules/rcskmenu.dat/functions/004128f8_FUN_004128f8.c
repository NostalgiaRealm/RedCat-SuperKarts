/*
 * FUN_004128f8 at 004128f8
 * int __register FUN_004128f8(int param_1)
 * Address ranges: 004128f8-0041290c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004128f8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00411894(*(int **)(param_1 + 4));
  return iVar1 - (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10));
}

