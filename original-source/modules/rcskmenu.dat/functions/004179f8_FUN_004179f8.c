/*
 * FUN_004179f8 at 004179f8
 * undefined FUN_004179f8(void)
 * Address ranges: 004179f8-004179fe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004179f8(int param_1)

{
  return CONCAT31((int3)((uint)*(int *)(param_1 + 0x10) >> 8),
                  *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x1a));
}

