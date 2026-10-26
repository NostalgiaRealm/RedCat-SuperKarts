/*
 * FUN_0043f5f0 at 0043f5f0
 * int __register FUN_0043f5f0(int param_1)
 * Address ranges: 0043f5f0-0043f600
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0043f5f0(int param_1)

{
  if (0 < *(int *)(param_1 + 0x94)) {
    return *(int *)(param_1 + 0x94);
  }
  return *(int *)(param_1 + 0x38);
}

