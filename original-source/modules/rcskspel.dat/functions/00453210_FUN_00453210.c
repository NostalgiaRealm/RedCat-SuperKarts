/*
 * FUN_00453210 at 00453210
 * undefined FUN_00453210(void)
 * Address ranges: 00453210-00453225
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00453210(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_1)();
  return *(int *)(param_1[1] + 4) + (iVar1 + -1) * 0xc;
}

