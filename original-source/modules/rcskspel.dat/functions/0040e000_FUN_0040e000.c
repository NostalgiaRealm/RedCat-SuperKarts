/*
 * FUN_0040e000 at 0040e000
 * undefined FUN_0040e000(void)
 * Address ranges: 0040e000-0040e022
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040e000(int param_1)

{
  return 6 - *(int *)(&DAT_00505938 + (&DAT_00503f5c)[param_1 * 0x47] * 0x18);
}

