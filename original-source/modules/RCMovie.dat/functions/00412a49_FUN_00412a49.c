/*
 * FUN_00412a49 at 00412a49
 * undefined4 __cdecl FUN_00412a49(int param_1)
 * Address ranges: 00412a49-00412a9c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00412a49(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_control_y__control_0043493c);
  }
  return *(undefined4 *)(DAT_0043d850 + 4 + param_1 * 0x1c);
}

