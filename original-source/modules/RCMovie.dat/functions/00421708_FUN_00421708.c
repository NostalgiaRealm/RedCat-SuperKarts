/*
 * FUN_00421708 at 00421708
 * undefined __stdcall FUN_00421708(void)
 * Address ranges: 00421708-00421740
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00421708(void)

{
  if ((DAT_0043e2bc == 1) || ((DAT_0043e2bc == 0 && (DAT_004370e4 == 1)))) {
    FUN_00421741(0xfc);
    if (DAT_0043e43c != (code *)0x0) {
      (*DAT_0043e43c)();
    }
    FUN_00421741(0xff);
  }
  return;
}

