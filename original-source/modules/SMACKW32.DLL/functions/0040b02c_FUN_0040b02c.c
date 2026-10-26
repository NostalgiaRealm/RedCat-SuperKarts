/*
 * FUN_0040b02c at 0040b02c
 * undefined FUN_0040b02c(void)
 * Address ranges: 0040b02c-0040b037
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b02c(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) |
         CONCAT22(uVar1,CONCAT11((char)param_2,(char)((uint)param_2 >> 8))) << 8;
}

