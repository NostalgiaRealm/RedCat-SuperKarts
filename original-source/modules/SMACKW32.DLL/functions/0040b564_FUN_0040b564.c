/*
 * FUN_0040b564 at 0040b564
 * undefined FUN_0040b564(void)
 * Address ranges: 0040b564-0040b570
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040b564(undefined4 param_1,int param_2)

{
  return CONCAT31((uint3)(ushort)((uint)param_2 >> 0x10) | (uint3)((uint)(param_2 << 0x18) >> 8),
                  (char)param_2);
}

