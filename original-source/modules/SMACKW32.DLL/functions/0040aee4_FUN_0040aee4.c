/*
 * FUN_0040aee4 at 0040aee4
 * undefined FUN_0040aee4(void)
 * Address ranges: 0040aee4-0040aef2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040aee4(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}

