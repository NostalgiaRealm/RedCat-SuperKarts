/*
 * FUN_0043806c at 0043806c
 * undefined4 __register FUN_0043806c(int param_1)
 * Address ranges: 0043806c-00438079
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043806c(int param_1)

{
  if (*(int *)(param_1 + 0x38) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x38) + 0x10);
  }
  return 0;
}

