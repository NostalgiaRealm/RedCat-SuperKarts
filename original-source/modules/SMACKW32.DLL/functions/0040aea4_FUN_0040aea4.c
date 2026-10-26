/*
 * FUN_0040aea4 at 0040aea4
 * undefined FUN_0040aea4(void)
 * Address ranges: 0040aea4-0040aeb0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040aea4(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 0x10) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 8;
}

