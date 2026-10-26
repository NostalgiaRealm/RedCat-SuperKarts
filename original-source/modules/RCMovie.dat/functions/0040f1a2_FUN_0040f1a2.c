/*
 * FUN_0040f1a2 at 0040f1a2
 * undefined4 __stdcall FUN_0040f1a2(void)
 * Address ranges: 0040f1a2-0040f1db
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040f1a2(void)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x11 < local_8) {
      return 0;
    }
    if (*(int *)(&DAT_0042c378 + local_8 * 0x14) == 0) break;
    local_8 = local_8 + 1;
  }
  return 1;
}

