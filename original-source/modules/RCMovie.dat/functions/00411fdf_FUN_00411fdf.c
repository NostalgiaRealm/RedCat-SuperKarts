/*
 * FUN_00411fdf at 00411fdf
 * undefined __cdecl FUN_00411fdf(int param_1)
 * Address ranges: 00411fdf-00412060
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00411fdf(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____disable_control__contr_004341ec);
  }
  if (DAT_0043d850 == 0) {
    FUN_0040187a((byte *)s__s__d_____disable_control__No_ac_00434248);
  }
  EnableWindow(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),0);
  return;
}

