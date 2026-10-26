/*
 * FUN_0042667e at 0042667e
 * undefined __cdecl FUN_0042667e(uint * param_1)
 * Address ranges: 0042667e-004266ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0042667e(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  *param_1 = uVar1 * 2;
  param_1[1] = uVar2 * 2 | uVar1 >> 0x1f;
  param_1[2] = param_1[2] << 1 | uVar2 >> 0x1f;
  return;
}

