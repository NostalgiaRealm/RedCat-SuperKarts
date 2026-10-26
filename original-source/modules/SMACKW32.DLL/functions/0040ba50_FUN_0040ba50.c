/*
 * FUN_0040ba50 at 0040ba50
 * undefined FUN_0040ba50(void)
 * Address ranges: 0040ba50-0040ba5e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040ba50(undefined4 param_1,int param_2)

{
  return CONCAT31((uint3)(ushort)((uint)param_2 >> 0x10) | (uint3)((uint)(param_2 << 0x18) >> 8),
                  (char)((uint)param_2 >> 0x10));
}

