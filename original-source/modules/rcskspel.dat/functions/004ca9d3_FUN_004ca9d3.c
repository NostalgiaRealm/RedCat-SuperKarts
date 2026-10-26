/*
 * FUN_004ca9d3 at 004ca9d3
 * undefined FUN_004ca9d3(void)
 * Address ranges: 004ca9d3-004ca9ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004ca9d3(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}

