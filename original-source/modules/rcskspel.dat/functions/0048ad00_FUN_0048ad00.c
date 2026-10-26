/*
 * FUN_0048ad00 at 0048ad00
 * undefined FUN_0048ad00(void)
 * Address ranges: 0048ad00-0048ad16
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_0048ad00(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_1)();
  return *(int *)(param_1[1] + 4) + (iVar1 + -1) * 0x20;
}

