/*
 * FUN_0040b354 at 0040b354
 * undefined FUN_0040b354(void)
 * Address ranges: 0040b354-0040b361
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040b354(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,(short)param_2) << 8;
}

