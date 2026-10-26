/*
 * FUN_00416d40 at 00416d40
 * undefined __stdcall FUN_00416d40(uint param_1, uint param_2)
 * Address ranges: 00416d40-00416f82
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00416d40(uint param_1,uint param_2)

{
  uint uVar1;
  int local_28;
  short *local_24;
  int local_20;
  int local_1c;
  short local_18;
  short local_14;
  int local_10;
  undefined4 local_c;
  short *local_8;
  
  local_c = FUN_004152a3();
  if (DAT_0042c358 == 8) {
    for (local_10 = 0; local_10 < 0x100; local_10 = local_10 + 1) {
      if (*(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_10 * 0xc) != 0) {
        local_8 = (short *)FUN_0041531a(local_10,&local_28);
        for (local_20 = 0;
            local_20 < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_10 * 0xc) + 8);
            local_20 = local_20 + 1) {
          for (local_1c = 0;
              local_1c < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_10 * 0xc) + 4);
              local_1c = local_1c + 1) {
            if ((uint)*(byte *)((int)local_8 + local_1c) == (param_1 & 0xff)) {
              *(undefined1 *)((int)local_8 + local_1c) = (undefined1)param_2;
            }
          }
          local_8 = (short *)((int)local_8 + local_28);
        }
        FUN_00415412(local_10,local_8);
      }
    }
  }
  else if (DAT_0042c358 == 0x10) {
    uVar1 = FUN_0040de93(param_1,0x18);
    local_18 = (short)uVar1;
    uVar1 = FUN_0040de93(param_2,0x18);
    local_14 = (short)uVar1;
    for (local_10 = 0; local_10 < 0x100; local_10 = local_10 + 1) {
      if (*(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + local_10 * 0xc) != 0) {
        local_8 = (short *)FUN_0041531a(local_10,&local_28);
        for (local_20 = 0;
            local_20 < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_10 * 0xc) + 8);
            local_20 = local_20 + 1) {
          local_24 = local_8;
          for (local_1c = 0;
              local_1c < *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + local_10 * 0xc) + 4);
              local_1c = local_1c + 1) {
            if (*local_24 == local_18) {
              *local_24 = local_14;
            }
            local_24 = local_24 + 1;
          }
          local_8 = (short *)((int)local_8 + local_28);
        }
        FUN_00415412(local_10,local_8);
      }
    }
  }
  else {
    FUN_0040187a((byte *)s__s___d___Only_8_and_16_bit_ascii_00435794);
  }
  return;
}

