/*
 * FUN_00486100 at 00486100
 * undefined FUN_00486100(void)
 * Address ranges: 00486100-0048612b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00486100(int param_1)

{
  if (*(char *)(param_1 + 0x234) != '\0') {
    FUN_00485c10();
    FUN_00485aa0();
    if (*(char *)(param_1 + 0x278) == '\0') {
      FUN_00485940();
    }
  }
  return;
}

