/*
 * FUN_0040b698 at 0040b698
 * undefined FUN_0040b698(void)
 * Address ranges: 0040b698-0040b6a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b698(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}

