/*
 * FUN_0042376c at 0042376c
 * uint __register FUN_0042376c(int param_1)
 * Address ranges: 0042376c-00423775
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0042376c(int param_1)

{
  return CONCAT31((int3)((uint)param_1 >> 8),(*(byte *)(param_1 + 0x40) & 0x40) != 0) ^ 1;
}

