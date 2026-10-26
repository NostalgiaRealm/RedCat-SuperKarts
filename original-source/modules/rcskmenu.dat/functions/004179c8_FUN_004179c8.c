/*
 * FUN_004179c8 at 004179c8
 * undefined4 __register FUN_004179c8(int param_1)
 * Address ranges: 004179c8-004179ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004179c8(int param_1)

{
  return CONCAT31((int3)((uint)*(int *)(param_1 + 0x10) >> 8),
                  *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x18));
}

