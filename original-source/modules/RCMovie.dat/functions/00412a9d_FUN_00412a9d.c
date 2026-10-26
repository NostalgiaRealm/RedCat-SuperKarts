/*
 * FUN_00412a9d at 00412a9d
 * int __cdecl FUN_00412a9d(int param_1)
 * Address ranges: 00412a9d-00412b00
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00412a9d(int param_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) == -1) {
      FUN_0040187a((byte *)s__s__d_____get_control_index__win_00434980);
      return -1;
    }
    if (*(int *)(DAT_0043d850 + 0x18 + local_8 * 0x1c) == param_1) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

