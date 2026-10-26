/*
 * FUN_004051d7 at 004051d7
 * undefined __cdecl FUN_004051d7(int param_1)
 * Address ranges: 004051d7-004054ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004051d7(int param_1)

{
  int iVar1;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_28 = *(int *)(*(int *)(DAT_0043d858 + 8 + DAT_0042df9c * 0xc) + 4 + DAT_0042dfa0 * 8);
  local_20 = DAT_0042df80;
  local_24 = DAT_0042df84;
  local_18 = DAT_0042df80 + *(int *)(DAT_0043d6e8 + 8 + local_28 * 0x20);
  local_1c = DAT_0042df84 + *(int *)(DAT_0043d6e8 + 0xc + local_28 * 0x20);
  if ((((-1 < local_18) && (DAT_0042df80 <= DAT_0042c350)) && (-1 < local_1c)) &&
     (DAT_0042df84 <= DAT_0042c354)) {
    if (DAT_0042df80 < 0) {
      local_20 = 0;
    }
    if (DAT_0042df84 < 0) {
      local_24 = 0;
    }
    if (DAT_0042c354 < local_1c) {
      local_1c = DAT_0042c354;
    }
    if (DAT_0042c350 < local_18) {
      local_18 = DAT_0042c350;
    }
    if ((local_20 < local_18) && (local_24 < local_1c)) {
      local_38 = 0;
      local_34 = 0;
      local_30 = local_18 - local_20;
      local_2c = local_1c - local_24;
      local_14 = local_20;
      local_10 = local_24;
      local_c = local_18;
      local_8 = local_1c;
      if (param_1 == 0) {
        FUN_004028c2(DAT_00438434);
        iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                          (DAT_00438434,&local_14,DAT_004384ac,&local_38,0x1000000,0);
        if (iVar1 != 0) {
          FUN_00401f61(iVar1);
          FUN_0040187a((byte *)s__s__d_____restore_mouse_button__b_0042e7c0);
        }
      }
      else if (param_1 == 1) {
        FUN_004028c2(DAT_00438438);
        iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                          (DAT_00438438,&local_14,DAT_004384ac,&local_38,0x1000000,0);
        if (iVar1 != 0) {
          FUN_00401f61(iVar1);
          FUN_0040187a((byte *)s__s__d_____restore_mouse_button__b_0042e850);
        }
      }
      else if (param_1 == 2) {
        FUN_004028c2(DAT_00438418);
        iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                          (DAT_00438418,&local_14,DAT_004384ac,&local_38,0x1000000,0);
        if (iVar1 != 0) {
          FUN_00401f61(iVar1);
          FUN_0040187a((byte *)s__s__d_____restore_mouse_button__b_0042e8e0);
        }
      }
    }
  }
  return;
}

