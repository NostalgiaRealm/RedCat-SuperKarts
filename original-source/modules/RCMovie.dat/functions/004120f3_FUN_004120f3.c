/*
 * FUN_004120f3 at 004120f3
 * undefined __cdecl FUN_004120f3(int param_1)
 * Address ranges: 004120f3-00412172
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004120f3(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____focus_control__control_00434324);
  }
  if (DAT_0043d850 == 0) {
    FUN_0040187a((byte *)s__s__d_____focus_control__No_acti_0043437c);
  }
  SetFocus(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c));
  return;
}

