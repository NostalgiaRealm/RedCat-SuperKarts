/*
 * FUN_0040b0d8 at 0040b0d8
 * undefined FUN_0040b0d8(void)
 * Address ranges: 0040b0d8-0040b0e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040b0d8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = CONCAT31((int3)((uint)param_2 >> 8),(char)((uint)param_2 >> 8));
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(iVar1 << 0x18) >> 0x10),
                  (short)iVar1);
}

