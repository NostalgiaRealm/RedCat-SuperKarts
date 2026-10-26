/*
 * FUN_0040b3ec at 0040b3ec
 * undefined FUN_0040b3ec(void)
 * Address ranges: 0040b3ec-0040b3f8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040b3ec(undefined4 param_1,int param_2)

{
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  (short)param_2);
}

