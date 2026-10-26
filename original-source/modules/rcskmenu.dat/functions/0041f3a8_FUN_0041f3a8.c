/*
 * FUN_0041f3a8 at 0041f3a8
 * undefined FUN_0041f3a8(void)
 * Address ranges: 0041f3a8-0041f3c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041f3a8(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 8))();
  FUN_0040f550((int *)param_1[1],((int *)param_1[1])[2] + -1);
  return uVar1;
}

