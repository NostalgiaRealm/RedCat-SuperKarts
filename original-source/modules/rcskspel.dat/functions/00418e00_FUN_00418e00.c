/*
 * FUN_00418e00 at 00418e00
 * undefined FUN_00418e00(void)
 * Address ranges: 00418e00-00418e16
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00418e00(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_1)();
  return *(int *)(param_1[1] + 4) + (iVar1 + -1) * 0x10;
}

