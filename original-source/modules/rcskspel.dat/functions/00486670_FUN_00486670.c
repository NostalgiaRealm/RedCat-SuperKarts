/*
 * FUN_00486670 at 00486670
 * undefined FUN_00486670(void)
 * Address ranges: 00486670-00486688
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00486670(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_1)();
  return *(int *)(param_1[1] + 4) + (iVar1 + -1) * 0x288;
}

