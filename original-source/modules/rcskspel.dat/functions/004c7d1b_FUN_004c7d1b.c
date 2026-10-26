/*
 * FUN_004c7d1b at 004c7d1b
 * undefined FUN_004c7d1b(void)
 * Address ranges: 004c7d1b-004c7d53
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c7d1b(void)

{
  if ((DAT_006b673c == 1) || ((DAT_006b673c == 0 && (DAT_00502ae4 == 1)))) {
    FUN_004c7d54(0xfc);
    if (DAT_006b68d4 != (code *)0x0) {
      (*DAT_006b68d4)();
    }
    FUN_004c7d54(0xff);
  }
  return;
}

