/*
 * FUN_00417fb4 at 00417fb4
 * undefined4 __register FUN_00417fb4(int param_1)
 * Address ranges: 00417fb4-00417fba
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00417fb4(int param_1)

{
  return CONCAT31((int3)((uint)*(int *)(param_1 + 0x10) >> 8),
                  *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x1c));
}

