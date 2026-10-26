/*
 * FUN_0044df8c at 0044df8c
 * undefined FUN_0044df8c(void)
 * Address ranges: 0044df8c-0044dfa6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0044df8c(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x20))();
  (**(code **)(*param_1 + 0x10))(param_1,uVar1);
  return uVar1;
}

