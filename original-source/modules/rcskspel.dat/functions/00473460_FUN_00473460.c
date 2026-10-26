/*
 * FUN_00473460 at 00473460
 * undefined FUN_00473460(void)
 * Address ranges: 00473460-00473492
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined * FUN_00473460(void)

{
  if ((DAT_00544d91 & 1) == 0) {
    DAT_00544d91 = DAT_00544d91 | 1;
    FUN_00473450();
    FUN_004be654(&DAT_004734a0);
  }
  return &DAT_00544d90;
}

