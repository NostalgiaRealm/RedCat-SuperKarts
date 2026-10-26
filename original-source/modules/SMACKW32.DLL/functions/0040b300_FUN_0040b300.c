/*
 * FUN_0040b300 at 0040b300
 * undefined FUN_0040b300(void)
 * Address ranges: 0040b300-0040b30a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040b300(undefined4 param_1,int param_2)

{
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  (short)param_2);
}

