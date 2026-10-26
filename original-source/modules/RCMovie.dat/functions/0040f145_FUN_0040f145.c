/*
 * FUN_0040f145 at 0040f145
 * int __cdecl FUN_0040f145(int param_1, int param_2, int param_3)
 * Address ranges: 0040f145-0040f1a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_0040f145(int param_1,int param_2,int param_3)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x11 < local_8) {
      return -1;
    }
    if (((*(int *)(&DAT_0042c368 + local_8 * 0x14) == param_1) &&
        (*(int *)(&DAT_0042c36c + local_8 * 0x14) == param_2)) &&
       (*(int *)(&DAT_0042c370 + local_8 * 0x14) == param_3)) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

