/*
 * FUN_0040b6e0 at 0040b6e0
 * undefined FUN_0040b6e0(void)
 * Address ranges: 0040b6e0-0040b6e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040b6e0(undefined4 param_1,int param_2)

{
  return CONCAT31((uint3)(ushort)((uint)param_2 >> 0x10) | (uint3)((uint)(param_2 << 0x18) >> 8),
                  (char)param_2);
}

