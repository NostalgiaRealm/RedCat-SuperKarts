/*
 * FUN_004105f0 at 004105f0
 * undefined FUN_004105f0(void)
 * Address ranges: 004105f0-00410610
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004105f0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x34))();
  (**(code **)(*param_1 + 0x24))(param_1,uVar1,param_3);
  return uVar1;
}

