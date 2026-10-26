/*
 * FUN_004479f0 at 004479f0
 * undefined FUN_004479f0(void)
 * Address ranges: 004479f0-00447a08
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_004479f0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_1)();
  return *(int *)(param_1[1] + 4) + (iVar1 + -1) * 0x2c;
}

