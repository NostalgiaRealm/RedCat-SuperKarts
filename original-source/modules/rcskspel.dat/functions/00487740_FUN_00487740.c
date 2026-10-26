/*
 * FUN_00487740 at 00487740
 * undefined FUN_00487740(void)
 * Address ranges: 00487740-0048777c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __fastcall FUN_00487740(int param_1)

{
  if (*(char *)(param_1 + 0x724) == '\0') {
    return false;
  }
  FUN_00486ea0();
  FUN_00486d50();
  if (*(char *)(param_1 + 0x768) == '\0') {
    FUN_00486cc0();
  }
  return *(char *)(param_1 + 0x724) == '\0';
}

