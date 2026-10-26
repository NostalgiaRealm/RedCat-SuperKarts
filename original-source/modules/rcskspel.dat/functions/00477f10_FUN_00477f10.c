/*
 * FUN_00477f10 at 00477f10
 * undefined FUN_00477f10(void)
 * Address ranges: 00477f10-00477f42
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined * FUN_00477f10(void)

{
  if ((DAT_00544e00 & 1) == 0) {
    DAT_00544e00 = DAT_00544e00 | 1;
    FUN_00477f00();
    FUN_004be654(&DAT_00477f50);
  }
  return &DAT_00544df8;
}

