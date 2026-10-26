/*
 * FUN_00451c90 at 00451c90
 * undefined __register FUN_00451c90(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00451c90-00451cab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00451c90(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  piVar1 = FUN_004516b8(param_1,param_2,param_3);
  FUN_004524e4((int)param_1,(int)piVar1);
  (**(code **)(*param_1 + 0x10))(param_1,param_1);
  return;
}

