/*
 * FUN_0043ea94 at 0043ea94
 * undefined4 __register FUN_0043ea94(int param_1)
 * Address ranges: 0043ea94-0043eaa1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043ea94(int param_1)

{
  if (*(int *)(param_1 + 0x5c) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x10);
  }
  return 0;
}

