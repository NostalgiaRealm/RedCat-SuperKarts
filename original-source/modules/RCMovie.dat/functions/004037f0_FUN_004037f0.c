/*
 * FUN_004037f0 at 004037f0
 * undefined __stdcall FUN_004037f0(void)
 * Address ranges: 004037f0-00403e99
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004037f0(void)

{
  int iVar1;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  int local_68;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  
  local_c = DAT_0042c4d0;
  local_10 = DAT_0042c4d0;
  if (DAT_00438458 == 0) {
    while( true ) {
      _memset(&local_7c,0,0x6c);
      local_7c = 0x6c;
      if (DAT_0042c360 == 0) {
        local_78 = 1;
        local_14 = 0x2200;
      }
      else {
        local_78 = 0x21;
        local_14 = 0x2218;
      }
      local_68 = DAT_0042c360;
      FUN_004015a6((byte *)s_creating_0042d6f8);
      iVar1 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_7c,&DAT_00438434,0);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____could_not_create_primar_0042d710);
      }
      iVar1 = (**(code **)*DAT_00438434)(DAT_00438434,&DAT_00428700,&DAT_004383c8);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____could_not_create_dd2_su_0042d750);
      }
      FUN_004015a6((byte *)s_locking_0042d784);
      iVar1 = FUN_0040322f(0);
      if (iVar1 != 0) break;
      if ((DAT_0042c360 == 0) || (DAT_00438468 != 0)) goto LAB_004039a5;
      (**(code **)(*DAT_00438434 + 8))(DAT_00438434);
      (**(code **)(*DAT_004383c8 + 8))(DAT_004383c8);
      DAT_0042c360 = 0;
    }
    DAT_00438444 = 1;
    local_8 = FUN_00402631(DAT_00438434,&DAT_004383b4);
    FUN_004015a6((byte *)s_locking_inter_0042d790);
    FUN_004027f9(DAT_00438434,local_8);
    FUN_004015a6((byte *)s_locking_done_0042d7a0);
LAB_004039a5:
    FUN_004015a6((byte *)s_getting_pixel_format_0042d7b0);
    FUN_0040e321();
    if (DAT_0043d754 == 0) {
      local_c = DAT_0042c4d0;
    }
    else if (DAT_0043d754 == 4) {
      local_c = FUN_0040de93(DAT_00438474,0x18);
    }
    else {
      local_c = FUN_0040de93(DAT_0042c4d0,8);
    }
    local_10 = local_c;
    iVar1 = (**(code **)(*DAT_00438434 + 0x74))(DAT_00438434,8,&local_10);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_0042d7d4);
    }
    DAT_00438458 = 1;
  }
  if (DAT_0043845c == 0) {
    if (DAT_0042c360 == 0) {
      FUN_004015a6((byte *)s_back_screen_0042d8c0);
      DAT_00438438 = (int *)FUN_00402a32(DAT_0042c350,DAT_0042c354,0x2800);
      iVar1 = (**(code **)*DAT_00438438)(DAT_00438438,&DAT_00428700,&DAT_00438440);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____unable_to_create_attach_0042d8dc);
      }
      iVar1 = FUN_0040322f(1);
      if (iVar1 != 0) {
        DAT_00438448 = 1;
        local_8 = FUN_00402631(DAT_00438438,&DAT_00438420);
        FUN_004027f9(DAT_00438438,local_8);
        FUN_004015a6((byte *)s_back_screen_locking_done_0042d910);
      }
    }
    else {
      FUN_004015a6((byte *)s_back_screen_0042d7fc);
      local_80 = 4;
      iVar1 = (**(code **)(*DAT_00438434 + 0x30))(DAT_00438434,&local_80,&DAT_00438438);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____unable_to_create_attach_0042d818);
      }
      iVar1 = (**(code **)*DAT_00438438)(DAT_00438438,&DAT_00428700,&DAT_00438440);
      if (iVar1 != 0) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____unable_to_create_attach_0042d858);
      }
      FUN_004015a6((byte *)s_back_screen_locking_0042d88c);
      iVar1 = FUN_0040322f(1);
      if (iVar1 != 0) {
        DAT_00438448 = 1;
        local_8 = FUN_00402631(DAT_00438438,&DAT_00438420);
        FUN_004027f9(DAT_00438438,local_8);
        FUN_004015a6((byte *)s_back_screen_locking_done_0042d8a4);
      }
    }
    if (DAT_0043d754 == 0) {
      local_c = DAT_0042c4d0;
    }
    else if (DAT_0043d754 == 4) {
      local_c = FUN_0040de93(DAT_00438474,0x18);
    }
    else {
      local_c = FUN_0040de93(DAT_0042c4d0,8);
    }
    local_10 = local_c;
    iVar1 = (**(code **)(*DAT_00438438 + 0x74))(DAT_00438438,8,&local_10);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_0042d938);
    }
    DAT_0043845c = 1;
  }
  if (DAT_00438460 == 0) {
    DAT_00438418 = (int *)FUN_00402a32(DAT_0042c350,DAT_0042c354,0x2800);
    iVar1 = (**(code **)*DAT_00438418)(DAT_00438418,&DAT_00428700,&DAT_00438424);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____query_interface_for_sur_0042d96c);
    }
    iVar1 = FUN_0040322f(2);
    if (iVar1 != 0) {
      DAT_0043844c = 1;
      local_8 = FUN_00402631(DAT_00438418,&DAT_00438430);
      FUN_004027f9(DAT_00438418,local_8);
    }
    if (DAT_0043d754 == 0) {
      local_c = DAT_0042c4d0;
    }
    else if (DAT_0043d754 == 4) {
      local_c = FUN_0040de93(DAT_00438474,0x18);
    }
    else {
      local_c = FUN_0040de93(DAT_0042c4d0,8);
    }
    local_10 = local_c;
    iVar1 = (**(code **)(*DAT_00438418 + 0x74))(DAT_00438418,8,&local_10);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_0042d9ac);
    }
    DAT_00438460 = 1;
  }
  FUN_004015a6((byte *)s_init_palette_done_0042d9d4);
  FUN_0040e6fa();
  FUN_004037c9(2,0);
  FUN_004037c9(1,0);
  FUN_00401cf3();
  return;
}

