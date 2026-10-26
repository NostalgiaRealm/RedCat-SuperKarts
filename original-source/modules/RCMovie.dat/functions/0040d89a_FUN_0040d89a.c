/*
 * FUN_0040d89a at 0040d89a
 * int __stdcall FUN_0040d89a(void)
 * Address ranges: 0040d89a-0040d8d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040d89a(void)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (9 < local_8) {
      return -1;
    }
    if (*(int *)(&DAT_004322f0 + local_8 * 4) == -1) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

