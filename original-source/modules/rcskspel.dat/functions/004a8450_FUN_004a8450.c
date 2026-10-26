/*
 * FUN_004a8450 at 004a8450
 * undefined FUN_004a8450(void)
 * Address ranges: 004a8450-004a848f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_004a8450(int param_1,int param_2)

{
  void *pvVar1;
  
  FUN_004a8510();
  pvVar1 = operator_new(param_2 * 2);
  *(void **)(param_1 + 0x98) = pvVar1;
  *(int *)(param_1 + 0x9c) = param_2;
  pvVar1 = operator_new(param_2 * 2);
  *(int *)(param_1 + 0xa4) = param_2;
  *(void **)(param_1 + 0xa0) = pvVar1;
  return 0;
}

