/*
 * FUN_0040b284 at 0040b284
 * undefined FUN_0040b284(void)
 * Address ranges: 0040b284-0040b290
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b284(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}

