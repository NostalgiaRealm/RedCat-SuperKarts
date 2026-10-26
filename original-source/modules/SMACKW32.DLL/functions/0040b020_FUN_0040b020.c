/*
 * FUN_0040b020 at 0040b020
 * undefined FUN_0040b020(void)
 * Address ranges: 0040b020-0040b02b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b020(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}

