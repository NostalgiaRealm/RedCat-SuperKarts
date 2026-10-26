/*
 * FUN_00411c40 at 00411c40
 * undefined __register FUN_00411c40(int * param_1, int param_2)
 * Address ranges: 00411c40-00411c64
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411c40(int *param_1,int param_2)

{
  undefined4 uVar1;
  int local_8;
  
  local_8 = param_2;
  uVar1 = (**(code **)(*param_1 + 0x10))(param_1,&local_8);
  FUN_00411b98((int)param_1,uVar1,param_1[2]);
  param_1[4] = local_8;
  return;
}

