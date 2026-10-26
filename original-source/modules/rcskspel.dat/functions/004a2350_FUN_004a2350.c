/*
 * FUN_004a2350 at 004a2350
 * undefined FUN_004a2350(void)
 * Address ranges: 004a2350-004a2388
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a2350(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  return;
}

