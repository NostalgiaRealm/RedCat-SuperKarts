/*
 * FUN_004550f0 at 004550f0
 * undefined FUN_004550f0(void)
 * Address ranges: 004550f0-00455117
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004550f0(void)

{
  if ((DAT_00544078 & 1) == 0) {
    DAT_00544078 = DAT_00544078 | 1;
    FUN_004be99e(&DAT_00544080,0x40,0x28,thunk_FUN_0044fa40);
  }
  return;
}

