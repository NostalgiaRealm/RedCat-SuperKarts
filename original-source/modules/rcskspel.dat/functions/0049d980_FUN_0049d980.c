/*
 * FUN_0049d980 at 0049d980
 * undefined FUN_0049d980(void)
 * Address ranges: 0049d980-0049d9d1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0049d980(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = __ftol();
  param_2 = ((100 - (iVar1 * 100) / *(int *)(param_1 + 0xc)) * *(int *)(param_1 + 0x10)) / 100;
  FUN_0049f340(&param_2,0,100);
  return param_2;
}

