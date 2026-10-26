/*
 * FUN_0040d190 at 0040d190
 * undefined __stdcall FUN_0040d190(void)
 * Address ranges: 0040d190-0040d1b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d190(void)

{
  if (DAT_0043d6fc != (int *)0x0) {
    (**(code **)(*DAT_0043d6fc + 8))(DAT_0043d6fc);
    DAT_0043d6fc = (int *)0x0;
  }
  return;
}

