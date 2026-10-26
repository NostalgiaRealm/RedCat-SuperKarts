/*
 * FUN_00411c68 at 00411c68
 * undefined FUN_00411c68(void)
 * Address ranges: 00411c68-00411c92
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411c68(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1[3];
  FUN_00411c40(param_1,param_2);
  param_1[2] = param_2;
  if (param_2 < iVar1) {
    (**(code **)(*param_1 + 0xc))(param_1,0,2);
  }
  return;
}

