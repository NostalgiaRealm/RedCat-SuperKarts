/*
 * FUN_0042c590 at 0042c590
 * uint __register FUN_0042c590(int param_1)
 * Address ranges: 0042c590-0042c595
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0042c590(int param_1)

{
  return CONCAT31((int3)((uint)param_1 >> 8),*(undefined1 *)(param_1 + 0x4e)) ^ 1;
}

