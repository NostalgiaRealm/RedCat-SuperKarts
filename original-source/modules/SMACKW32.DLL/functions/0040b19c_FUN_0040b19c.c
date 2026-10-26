/*
 * FUN_0040b19c at 0040b19c
 * undefined FUN_0040b19c(void)
 * Address ranges: 0040b19c-0040b1a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b19c(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}

