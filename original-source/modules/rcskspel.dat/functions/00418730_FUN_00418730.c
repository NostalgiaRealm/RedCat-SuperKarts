/*
 * FUN_00418730 at 00418730
 * undefined FUN_00418730(void)
 * Address ranges: 00418730-00418745
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_00418730(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x14) + param_2 * 4);
  return -(uint)(uVar1 != 0xffffffff) & uVar1;
}

