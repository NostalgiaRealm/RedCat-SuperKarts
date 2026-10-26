/*
 * FUN_00406d14 at 00406d14
 * undefined __stdcall FUN_00406d14(void)
 * Address ranges: 00406d14-00406d7b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00406d14(void)

{
  if (DAT_0043d43c != 0) {
    FUN_00406873();
    (**(code **)(*DAT_0043d410 + 8))(DAT_0043d410);
    LocalReAlloc(DAT_0043d420,0,2);
    DAT_0043d43c = 0;
    DAT_0043d440 = 0;
    DAT_0043d444 = 0;
    DAT_0043d448 = 0;
    DAT_0043d44c = 0;
  }
  return;
}

