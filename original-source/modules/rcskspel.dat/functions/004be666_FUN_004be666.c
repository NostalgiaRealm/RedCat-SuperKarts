/*
 * FUN_004be666 at 004be666
 * undefined FUN_004be666(void)
 * Address ranges: 004be666-004be694
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004be666(void)

{
  DAT_006b7dd4 = _malloc(0x80);
  if (DAT_006b7dd4 == (undefined4 *)0x0) {
    __amsg_exit(0x18);
  }
  *DAT_006b7dd4 = 0;
  DAT_006b7dd0 = DAT_006b7dd4;
  return;
}

