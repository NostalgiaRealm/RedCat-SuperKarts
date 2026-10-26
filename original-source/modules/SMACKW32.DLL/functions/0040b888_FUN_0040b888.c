/*
 * FUN_0040b888 at 0040b888
 * undefined FUN_0040b888(void)
 * Address ranges: 0040b888-0040b894
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b888(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11((char)param_2,(char)param_2));
  return uVar1 >> 8 | uVar1 << 0x18;
}

