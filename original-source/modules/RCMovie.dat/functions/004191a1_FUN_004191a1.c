/*
 * FUN_004191a1 at 004191a1
 * undefined4 __cdecl FUN_004191a1(int param_1)
 * Address ranges: 004191a1-0041920a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004191a1(int param_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (7 < local_8) {
      return 0;
    }
    if ((*(int *)(&DAT_0043dd48 + local_8 * 8) == param_1) &&
       (*(int *)(&DAT_0043dd4c + local_8 * 8) != 0)) break;
    if ((*(int *)(&DAT_0043dda4 + local_8 * 8) == param_1) &&
       (*(int *)(&DAT_0043dda8 + local_8 * 8) != 0)) {
      return 1;
    }
    local_8 = local_8 + 1;
  }
  return 1;
}

