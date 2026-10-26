/*
 * FUN_004105cc at 004105cc
 * undefined FUN_004105cc(void)
 * Address ranges: 004105cc-004105ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004105cc(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x14))();
  (**(code **)(*param_1 + 0x54))(param_1,uVar1,param_2);
  return uVar1;
}

