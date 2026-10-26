/*
 * FUN_004127b0 at 004127b0
 * int __cdecl FUN_004127b0(int param_1, int param_2)
 * Address ranges: 004127b0-00412820
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_004127b0(int param_1,int param_2)

{
  if ((param_1 < 0) || (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_previous_control_i_00434714);
  }
  if (param_1 == 0) {
    param_1 = -1;
  }
  else {
    do {
      if (param_1 < 1) {
        return -1;
      }
      param_1 = param_1 + -1;
    } while (*(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) != param_2);
  }
  return param_1;
}

