/*
 * FUN_00466ca4 at 00466ca4
 * int __register FUN_00466ca4(int param_1)
 * Address ranges: 00466ca4-00466cbe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00466ca4(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 500) != 0) {
    iVar1 = FUN_0040f70c(*(int *)(*(int *)(param_1 + 500) + 0x240),param_1);
    return iVar1;
  }
  return -1;
}

