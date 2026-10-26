/*
 * FUN_0040b2e4 at 0040b2e4
 * undefined FUN_0040b2e4(void)
 * Address ranges: 0040b2e4-0040b2f0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040b2e4(undefined4 param_1,int param_2)

{
  return CONCAT31((uint3)(ushort)((uint)param_2 >> 0x10) | (uint3)((uint)(param_2 << 0x18) >> 8),
                  (char)param_2);
}

