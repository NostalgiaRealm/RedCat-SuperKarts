/*
 * FUN_00410ed0 at 00410ed0
 * undefined __register FUN_00410ed0(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00410ed0-00410efe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410ed0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1,param_2);
  (**(code **)(*param_1 + 0x44))(param_1,param_2);
  FUN_00410cf0(param_1,param_2,param_3,uVar1);
  return;
}

