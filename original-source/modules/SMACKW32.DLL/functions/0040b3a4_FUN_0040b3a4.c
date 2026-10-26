/*
 * FUN_0040b3a4 at 0040b3a4
 * undefined FUN_0040b3a4(void)
 * Address ranges: 0040b3a4-0040b3b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b3a4(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}

