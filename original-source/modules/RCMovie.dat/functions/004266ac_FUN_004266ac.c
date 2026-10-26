/*
 * FUN_004266ac at 004266ac
 * undefined __cdecl FUN_004266ac(uint * param_1)
 * Address ranges: 004266ac-004266d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004266ac(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}

