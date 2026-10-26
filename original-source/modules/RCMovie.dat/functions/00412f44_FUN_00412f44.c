/*
 * FUN_00412f44 at 00412f44
 * undefined __cdecl FUN_00412f44(undefined4 param_1)
 * Address ranges: 00412f44-00413153
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00412f44(undefined4 param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  iVar1 = FUN_004133f0(0x12);
  if (iVar1 == 0) {
    switch(param_1) {
    case 0xd:
      DAT_00434008 = 0x2715;
      break;
    case 0x1b:
      DAT_00434008 = 10000;
      break;
    case 0x21:
      DAT_00434008 = 0x2716;
      break;
    case 0x22:
      DAT_00434008 = 0x2717;
      break;
    case 0x23:
      DAT_00434008 = 0x2719;
      break;
    case 0x24:
      DAT_00434008 = 0x2718;
      break;
    case 0x25:
      DAT_00434008 = 0x2713;
      break;
    case 0x26:
      DAT_00434008 = 0x2711;
      break;
    case 0x27:
      DAT_00434008 = 0x2714;
      break;
    case 0x28:
      DAT_00434008 = 0x2712;
    }
  }
  else {
    for (; *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) != -1; local_8 = local_8 + 1) {
      if ((*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) == -1) ||
         ((&DAT_0043db90)[*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c] == '\0')) {
        FUN_0040187a((byte *)s__s__d_____check_form_key_pressed_00434b98);
      }
      else if ((*(int *)(&DAT_0043db9c + *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c) != 0)
              && (iVar1 = (**(code **)(&DAT_0043db9c +
                                      *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c))
                                    (DAT_0043d850 + local_8 * 0x1c,param_1), iVar1 != 0)) {
        DAT_0043400c = param_1;
        FUN_00411de7(local_8,4);
        SetFocus(*(HWND *)(DAT_0043d850 + 0x18 + local_8 * 0x1c));
        _DAT_0043d82c = *(undefined4 *)(DAT_0043d850 + 0x18 + local_8 * 0x1c);
        _DAT_0043d828 = 0x11;
        SendMessageA(*(HWND *)(DAT_0043d850 + 0x18 + local_8 * 0x1c),0x2b,0,0x43d818);
        return;
      }
    }
  }
  return;
}

