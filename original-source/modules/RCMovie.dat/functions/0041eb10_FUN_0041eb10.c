/*
 * FUN_0041eb10 at 0041eb10
 * undefined FUN_0041eb10(void)
 * Address ranges: 0041eb10-0041eb30
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __thiscall FUN_0041eb10(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_004028e3(param_2,param_3);
  *(int *)(param_1 + 0x1d) = iVar1;
  return iVar1 != 0;
}

