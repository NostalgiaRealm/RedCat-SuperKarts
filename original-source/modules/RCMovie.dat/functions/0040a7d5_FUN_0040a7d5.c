/*
 * FUN_0040a7d5 at 0040a7d5
 * int __stdcall FUN_0040a7d5(void)
 * Address ranges: 0040a7d5-0040a80b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040a7d5(void)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x13 < local_8) {
      return -1;
    }
    if (*(int *)(&DAT_0043d470 + local_8 * 8) == -1) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

