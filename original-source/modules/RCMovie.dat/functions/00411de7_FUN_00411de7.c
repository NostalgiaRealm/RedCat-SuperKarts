/*
 * FUN_00411de7 at 00411de7
 * undefined __cdecl FUN_00411de7(int param_1, undefined4 param_2)
 * Address ranges: 00411de7-00411f4c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00411de7(int param_1,undefined4 param_2)

{
  HWND pHVar1;
  
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____set_control_state__con_0043406c);
  }
  if (DAT_0043d850 == 0) {
    FUN_0040187a((byte *)s__s__d_____set_control_state__No_a_004340c8);
  }
  *(undefined4 *)(DAT_0043d850 + 0x14 + param_1 * 0x1c) =
       *(undefined4 *)(DAT_0043d850 + 0x10 + param_1 * 0x1c);
  *(undefined4 *)(DAT_0043d850 + 0x10 + param_1 * 0x1c) = param_2;
  switch(param_2) {
  case 1:
    pHVar1 = GetFocus();
    if (pHVar1 != *(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c)) {
      if (*(int *)(DAT_0043d850 + 8 + param_1 * 0x1c) == 4) {
        FUN_0040187a((byte *)s__s__d_____set_control_state__are_00434104);
      }
      else {
        SetFocus(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c));
      }
    }
    break;
  case 2:
    EnableWindow(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),0);
    break;
  case 3:
    EnableWindow(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),1);
    break;
  case 4:
    DAT_00434008 = param_1;
  }
  return;
}

