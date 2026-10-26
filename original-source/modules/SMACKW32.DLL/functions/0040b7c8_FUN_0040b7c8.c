/*
 * FUN_0040b7c8 at 0040b7c8
 * undefined FUN_0040b7c8(void)
 * Address ranges: 0040b7c8-0040b7d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040b7c8(undefined4 param_1,int param_2)

{
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  (short)param_2);
}

