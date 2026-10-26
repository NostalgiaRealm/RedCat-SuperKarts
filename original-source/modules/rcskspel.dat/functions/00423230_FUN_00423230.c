/*
 * FUN_00423230 at 00423230
 * undefined FUN_00423230(void)
 * Address ranges: 00423230-00423272
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423230(undefined4 param_1)

{
  FUN_0048f4e0();
  DAT_0050bc20 = __ftol();
  if (DAT_0050bc20 <= DAT_0050bc24) {
    DAT_0050bc24 = 0;
    DAT_0050bc28 = param_1;
    return;
  }
  DAT_0050bc28 = param_1;
  return;
}

