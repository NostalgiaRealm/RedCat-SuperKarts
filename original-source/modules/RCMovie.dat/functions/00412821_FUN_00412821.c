/*
 * FUN_00412821 at 00412821
 * int __cdecl FUN_00412821(int param_1, int param_2)
 * Address ranges: 00412821-0041289b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00412821(int param_1,int param_2)

{
  if ((param_1 < 0) || (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_next_control_index_00434778);
  }
  if (param_1 == DAT_0043d84c) {
    param_1 = -1;
  }
  else {
    do {
      if (DAT_0043d84c <= param_1) {
        return -1;
      }
      param_1 = param_1 + 1;
    } while (*(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) != param_2);
  }
  return param_1;
}

