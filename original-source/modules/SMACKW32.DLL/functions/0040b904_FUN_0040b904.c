/*
 * FUN_0040b904 at 0040b904
 * undefined FUN_0040b904(void)
 * Address ranges: 0040b904-0040b90d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b904(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}

