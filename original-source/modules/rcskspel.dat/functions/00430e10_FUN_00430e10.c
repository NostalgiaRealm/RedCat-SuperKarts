/*
 * FUN_00430e10 at 00430e10
 * undefined FUN_00430e10(void)
 * Address ranges: 00430e10-00430e37
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430e10(int *param_1,undefined4 param_2)

{
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 != (int *)0x0) {
    local_4 = param_2;
    local_8 = param_2;
    (**(code **)(*param_1 + 0x74))(param_1,8,&local_8);
  }
  return;
}

