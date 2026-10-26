/*
 * FUN_0040b18c at 0040b18c
 * undefined FUN_0040b18c(void)
 * Address ranges: 0040b18c-0040b19a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b18c(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}

