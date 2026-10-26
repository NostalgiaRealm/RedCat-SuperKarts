/*
 * FUN_0040b9f8 at 0040b9f8
 * undefined FUN_0040b9f8(void)
 * Address ranges: 0040b9f8-0040ba01
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b9f8(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}

