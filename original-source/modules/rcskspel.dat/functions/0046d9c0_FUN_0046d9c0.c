/*
 * FUN_0046d9c0 at 0046d9c0
 * undefined FUN_0046d9c0(void)
 * Address ranges: 0046d9c0-0046d9e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0046d9c0(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  *param_1 = *param_3;
  iVar1 = *param_3;
  param_1[3] = (int)param_3;
  param_1[1] = iVar1 + 0xff8;
  param_1[2] = param_2;
  return;
}

