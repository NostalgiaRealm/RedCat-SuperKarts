/*
 * FUN_00418303 at 00418303
 * int __stdcall FUN_00418303(void)
 * Address ranges: 00418303-00418339
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00418303(void)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xf < local_8) {
      return -1;
    }
    if (*(int *)(&DAT_00435820 + local_8 * 0x10) == 0) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

