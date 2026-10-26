/*
 * FUN_0040af4c at 0040af4c
 * undefined FUN_0040af4c(void)
 * Address ranges: 0040af4c-0040af57
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040af4c(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31((uint3)(byte)((uint)param_2 >> 0x18) |
                  (uint3)(((uint)CONCAT11((char)param_2,(char)param_2) << 0x10) >> 8),
                  (char)((uint)param_2 >> 8));
}

