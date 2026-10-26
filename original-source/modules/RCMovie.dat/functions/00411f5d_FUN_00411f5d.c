/*
 * FUN_00411f5d at 00411f5d
 * undefined __cdecl FUN_00411f5d(int param_1)
 * Address ranges: 00411f5d-00411fde
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00411f5d(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____enable_control__contro_0043415c);
  }
  if (DAT_0043d850 == 0) {
    FUN_0040187a((byte *)s__s__d_____enable_control__No_act_004341b4);
  }
  EnableWindow(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),1);
  return;
}

