/*
 * FUN_0048de10 at 0048de10
 * undefined FUN_0048de10(void)
 * Address ranges: 0048de10-0048de32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_0048de10(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_1)();
  return *(int *)(param_1[1] + 4) + (iVar1 + -1) * 0x11b0;
}

