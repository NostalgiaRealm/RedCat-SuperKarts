/*
 * FUN_00487d50 at 00487d50
 * undefined FUN_00487d50(void)
 * Address ranges: 00487d50-00487d6d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00487d50(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_1)();
  return *(int *)(param_1[1] + 4) + (iVar1 + -1) * 0x794;
}

