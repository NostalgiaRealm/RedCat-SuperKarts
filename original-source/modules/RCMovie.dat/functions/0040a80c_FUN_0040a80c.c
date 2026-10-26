/*
 * FUN_0040a80c at 0040a80c
 * undefined __stdcall FUN_0040a80c(void)
 * Address ranges: 0040a80c-0040a83b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a80c(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x14; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_0043d470 + local_8 * 8) = 0xffffffff;
  }
  return;
}

