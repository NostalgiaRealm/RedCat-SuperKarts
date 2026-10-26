/*
 * FUN_0044268c at 0044268c
 * int __register FUN_0044268c(int param_1)
 * Address ranges: 0044268c-004426aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0044268c(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0x134) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x134) + 8);
  }
  if (*(int *)(param_1 + 0x180) != 0) {
    iVar1 = iVar1 + *(int *)(*(int *)(param_1 + 0x180) + 8);
  }
  return iVar1;
}

