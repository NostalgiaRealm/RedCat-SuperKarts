/*
 * FUN_00404384 at 00404384
 * undefined __stdcall FUN_00404384(void)
 * Address ranges: 00404384-004043bc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404384(void)

{
  if ((DAT_00408c58 == 1) || ((DAT_00408c58 == 0 && (DAT_00408244 == 1)))) {
    FUN_004043bd(0xfc);
    if (DAT_00408d70 != (code *)0x0) {
      (*DAT_00408d70)();
    }
    FUN_004043bd(0xff);
  }
  return;
}

