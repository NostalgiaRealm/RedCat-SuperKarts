/*
 * FUN_00404ed3 at 00404ed3
 * undefined __cdecl FUN_00404ed3(int param_1)
 * Address ranges: 00404ed3-004051d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00404ed3(int param_1)

{
  int iVar1;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_28 = *(int *)(*(int *)(DAT_0043d858 + 8 + DAT_0042df9c * 0xc) + 4 + DAT_0042dfa0 * 8);
  local_20 = DAT_00438480;
  local_24 = DAT_00438484;
  local_18 = DAT_00438480 + *(int *)(DAT_0043d6e8 + 8 + local_28 * 0x20);
  local_1c = DAT_00438484 + *(int *)(DAT_0043d6e8 + 0xc + local_28 * 0x20);
  if ((((-1 < local_18) && (DAT_00438480 <= DAT_0042c350)) && (-1 < local_1c)) &&
     (DAT_00438484 <= DAT_0042c354)) {
    if (DAT_00438480 < 0) {
      local_20 = 0;
    }
    if (DAT_00438484 < 0) {
      local_24 = 0;
    }
    if (DAT_0042c354 < local_1c) {
      local_1c = DAT_0042c354;
    }
    if (DAT_0042c350 < local_18) {
      local_18 = DAT_0042c350;
    }
    if ((local_20 < local_18) && (local_24 < local_1c)) {
      local_38 = local_20;
      local_34 = local_24;
      local_30 = local_18;
      local_2c = local_1c;
      local_14 = 0;
      local_10 = 0;
      local_c = local_18 - local_20;
      local_8 = local_1c - local_24;
      if (param_1 == 0) {
        FUN_004028c2(DAT_00438434);
        iVar1 = (**(code **)(*DAT_004384ac + 0x14))
                          (DAT_004384ac,&local_14,DAT_00438434,&local_38,0x1000000,0);
        if (iVar1 != 0) {
          FUN_00401f61(iVar1);
          FUN_0040187a((byte *)s__s__d_____store_mouse_button__bl_0042e610);
        }
      }
      else if (param_1 == 1) {
        FUN_004028c2(DAT_00438438);
        iVar1 = (**(code **)(*DAT_004384ac + 0x14))
                          (DAT_004384ac,&local_14,DAT_00438438,&local_38,0x1000000,0);
        if (iVar1 != 0) {
          FUN_00401f61(iVar1);
          FUN_0040187a((byte *)s__s__d_____store_mouse_button__bl_0042e6a0);
        }
      }
      else if (param_1 == 2) {
        FUN_004028c2(DAT_00438418);
        iVar1 = (**(code **)(*DAT_004384ac + 0x14))
                          (DAT_004384ac,&local_14,DAT_00438418,&local_38,0x1000000,0);
        if (iVar1 != 0) {
          FUN_00401f61(iVar1);
          FUN_0040187a((byte *)s__s__d_____store_mouse_button__bl_0042e730);
        }
      }
      _DAT_0042df88 = DAT_0042df80;
      _DAT_0042df8c = DAT_0042df84;
      DAT_0042df80 = DAT_00438480;
      DAT_0042df84 = DAT_00438484;
    }
  }
  return;
}

