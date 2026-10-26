/*
 * FUN_0040b918 at 0040b918
 * undefined __stdcall FUN_0040b918(void)
 * Address ranges: 0040b918-0040b9af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040b918(void)

{
  if (DAT_0043d6c8 != 0) {
    if (DAT_0043d6cc != 0) {
      DAT_0043d6cc = 0;
      (**(code **)(*DAT_0043d6c0 + 0x20))(DAT_0043d6c0);
      (**(code **)(*DAT_0043d6c0 + 8))(DAT_0043d6c0);
    }
    if (DAT_0043d6d0 != 0) {
      DAT_0043d6d0 = 0;
      (**(code **)(*DAT_0043d5b8 + 0x20))(DAT_0043d5b8);
      (**(code **)(*DAT_0043d5b8 + 8))(DAT_0043d5b8);
    }
    (**(code **)(*DAT_0043d6c4 + 8))(DAT_0043d6c4);
    DAT_0043d6c8 = 0;
  }
  return;
}

