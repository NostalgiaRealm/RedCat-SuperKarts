/*
 * FUN_00412b01 at 00412b01
 * undefined4 __cdecl FUN_00412b01(int param_1)
 * Address ranges: 00412b01-00412b6f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00412b01(int param_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) == -1) {
      FUN_0040187a((byte *)s__s__d_____get_control_pointer__w_004349c8);
      return 0;
    }
    if (*(int *)(DAT_0043d850 + 0x18 + local_8 * 0x1c) == param_1) break;
    local_8 = local_8 + 1;
  }
  return *(undefined4 *)(DAT_0043d850 + 0xc + local_8 * 0x1c);
}

