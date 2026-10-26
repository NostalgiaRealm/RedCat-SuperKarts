/*
 * FUN_00412bb8 at 00412bb8
 * undefined __cdecl FUN_00412bb8(int param_1)
 * Address ranges: 00412bb8-00412ca0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00412bb8(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____call_help_function__co_00434a64);
  }
  if ((*(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) == -1) ||
     ((&DAT_0043db90)[*(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) * 0x1c] == '\0')) {
    FUN_0040187a((byte *)s__s__d_____destroy_form__Unused_c_00434ac0);
  }
  else if (*(int *)(&DAT_0043dba0 + *(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) * 0x1c) != 0) {
    (**(code **)(&DAT_0043dba0 + *(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) * 0x1c))
              (DAT_0043d850 + param_1 * 0x1c);
  }
  return;
}

