/*
 * FUN_00488f20 at 00488f20
 * undefined FUN_00488f20(void)
 * Address ranges: 00488f20-00488f3a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00488f20(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_1)();
  return *(int *)(param_1[1] + 4) + (iVar1 + -1) * 0x17c;
}

