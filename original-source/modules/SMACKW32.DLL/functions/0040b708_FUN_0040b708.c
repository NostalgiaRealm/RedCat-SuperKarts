/*
 * FUN_0040b708 at 0040b708
 * undefined FUN_0040b708(void)
 * Address ranges: 0040b708-0040b711
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b708(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 0x10) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 8;
}

