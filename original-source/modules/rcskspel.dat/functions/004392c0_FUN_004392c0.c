/*
 * FUN_004392c0 at 004392c0
 * undefined FUN_004392c0(void)
 * Address ranges: 004392c0-004392d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_004392c0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_1)();
  return *(int *)(param_1[1] + 4) + (iVar1 + -1) * 0x14;
}

