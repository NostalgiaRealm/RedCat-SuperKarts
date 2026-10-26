/*
 * FUN_0048ada0 at 0048ada0
 * undefined FUN_0048ada0(void)
 * Address ranges: 0048ada0-0048adb7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_0048ada0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_1)();
  return *(int *)(param_1[1] + 4) + (iVar1 + -1) * 0x120;
}

