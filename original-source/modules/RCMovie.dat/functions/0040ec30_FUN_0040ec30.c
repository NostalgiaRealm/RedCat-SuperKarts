/*
 * FUN_0040ec30 at 0040ec30
 * int __stdcall FUN_0040ec30(void)
 * Address ranges: 0040ec30-0040ec8d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040ec30(void)

{
  int local_8;
  
  if (DAT_0043d7ec == 0) {
    FUN_0040187a((byte *)s_s__d____error_attempting_to_find_00432c10);
  }
  local_8 = 0;
  while( true ) {
    if (DAT_0043d79c <= local_8) {
      return -1;
    }
    if (*(int *)(DAT_0043d798 + 4 + local_8 * 8) == 3) break;
    local_8 = local_8 + 1;
  }
  return local_8 + 0x41;
}

