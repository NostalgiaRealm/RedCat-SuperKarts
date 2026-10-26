/*
 * FUN_004532e0 at 004532e0
 * undefined FUN_004532e0(void)
 * Address ranges: 004532e0-004532f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_004532e0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_1)();
  return *(int *)(param_1[1] + 4) + (iVar1 + -1) * 4;
}

