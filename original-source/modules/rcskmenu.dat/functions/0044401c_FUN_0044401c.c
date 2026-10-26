/*
 * FUN_0044401c at 0044401c
 * undefined4 __register FUN_0044401c(int param_1)
 * Address ranges: 0044401c-0044402c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0044401c(int param_1)

{
  if (*(int *)(param_1 + 0x140) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x140) + 8);
  }
  return 0;
}

