/*
 * FUN_0040b878 at 0040b878
 * undefined FUN_0040b878(void)
 * Address ranges: 0040b878-0040b886
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b878(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) |
         CONCAT22(uVar1,CONCAT11((char)param_2,(char)((uint)param_2 >> 8))) << 8;
}

