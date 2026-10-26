/*
 * FUN_00437010 at 00437010
 * undefined FUN_00437010(void)
 * Address ranges: 00437010-00437037
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00437010(void)

{
  if ((DAT_0053bf08 & 1) == 0) {
    DAT_0053bf08 = DAT_0053bf08 | 1;
    FUN_004be99e(&DAT_0053bf10,0x10,6,FUN_0040b4b0);
  }
  return;
}

