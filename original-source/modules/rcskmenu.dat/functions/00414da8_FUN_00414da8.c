/*
 * FUN_00414da8 at 00414da8
 * undefined4 __register FUN_00414da8(int param_1)
 * Address ranges: 00414da8-00414db5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00414da8(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x10) + 8);
  }
  return 0;
}

