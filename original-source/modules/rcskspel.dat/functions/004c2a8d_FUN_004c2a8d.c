/*
 * FUN_004c2a8d at 004c2a8d
 * undefined FUN_004c2a8d(void)
 * Address ranges: 004c2a8d-004c2a9a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004c2a8d(int *param_1)

{
  *param_1 = *param_1 + 4;
  return CONCAT22((short)((uint)*param_1 >> 0x10),*(undefined2 *)(*param_1 + -4));
}

