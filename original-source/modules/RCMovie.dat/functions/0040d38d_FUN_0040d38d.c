/*
 * FUN_0040d38d at 0040d38d
 * undefined __cdecl FUN_0040d38d(int param_1)
 * Address ranges: 0040d38d-0040d64e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040d38d(int param_1)

{
  int iVar1;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_18 = 0;
  local_1c = 0;
  if (DAT_0043d6fc != 0) {
    local_2c = 0;
    local_24 = 8;
    local_28 = 0;
    local_20 = 8;
    if (param_1 == 0) {
      FUN_004028c2(DAT_00438434);
      for (local_1c = 0; local_1c < DAT_0042c354; local_1c = local_1c + 8) {
        local_10 = local_1c;
        local_8 = local_1c + 8;
        for (local_18 = 0; local_18 < DAT_0042c350; local_18 = local_18 + 8) {
          local_14 = local_18;
          local_c = local_18 + 8;
          iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                            (DAT_00438434,&local_14,DAT_0043d6fc,&local_2c,0x1008000,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____help_grid_blitting_erro_00432364);
          }
        }
      }
    }
    else if (param_1 == 1) {
      FUN_004028c2(DAT_00438438);
      for (local_1c = 0; local_1c < DAT_0042c354; local_1c = local_1c + 8) {
        local_10 = local_1c;
        local_8 = local_1c + 8;
        for (local_18 = 0; local_18 < DAT_0042c350; local_18 = local_18 + 8) {
          local_14 = local_18;
          local_c = local_18 + 8;
          iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                            (DAT_00438438,&local_14,DAT_0043d6fc,&local_2c,0x1008000,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____help_grid_blitting_erro_00432394);
          }
        }
      }
    }
    else if (param_1 == 2) {
      FUN_004028c2(DAT_00438418);
      for (local_1c = 0; local_1c < DAT_0042c354; local_1c = local_1c + 8) {
        local_10 = local_1c;
        local_8 = local_1c + 8;
        for (local_18 = 0; local_18 < DAT_0042c350; local_18 = local_18 + 8) {
          local_14 = local_18;
          local_c = local_18 + 8;
          iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                            (DAT_00438418,&local_14,DAT_0043d6fc,&local_2c,0x1008000,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____help_grid_blitting_erro_004323c4);
          }
        }
      }
    }
  }
  return;
}

