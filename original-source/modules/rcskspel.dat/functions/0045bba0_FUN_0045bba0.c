/*
 * FUN_0045bba0 at 0045bba0
 * undefined FUN_0045bba0(void)
 * Address ranges: 0045bba0-0045bf0b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0045bba0(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  undefined1 local_108 [16];
  undefined1 local_f8 [16];
  undefined1 local_e8 [16];
  undefined1 local_d8 [8];
  int local_d0;
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [28];
  undefined1 local_8c [16];
  undefined1 local_7c [16];
  undefined1 local_6c [16];
  undefined1 local_5c [16];
  undefined1 local_4c [16];
  undefined1 local_3c [16];
  undefined1 local_2c [16];
  undefined1 local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ce50c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = s_Parent_004f2cdc;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_Parent_004f2cdc,~uVar4 - 1);
  local_4 = 0;
  FUN_00464150(local_d8,param_1,local_c8);
  local_4._0_1_ = 2;
  FUN_0040b4f0(1);
  if (local_d0 != 0) {
    uVar2 = FUN_004614b0(local_d8);
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar5 = s_D__work_rcsk_Code_game_Hud_IniFi_004f3048;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f3048,~uVar4 - 1);
    local_4._0_1_ = 0xf;
    uVar3 = FUN_00412710(local_f8,s_Parent_composite_004f308c,local_d8);
    local_4._0_1_ = 0x10;
    uVar3 = FUN_0041b630(local_e8,uVar3,s_not_found_in_overlay_004f3074);
    local_4._0_1_ = 0x11;
    FUN_00464530(uVar2,uVar3,local_108,0x10c);
    local_4._0_1_ = 0x10;
    FUN_0040b4f0(1);
    local_4._0_1_ = 0xf;
    FUN_0040b4f0(1);
    local_4 = CONCAT31(local_4._1_3_,2);
    FUN_0040b4f0(1);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    ExceptionList = local_c;
    return uVar2;
  }
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = s_No_parent_in_ini_file_for_compon_004f2fcc;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_No_parent_in_ini_file_for_compon_004f2fcc,~uVar4 - 1);
  local_4._0_1_ = 3;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = &DAT_004f2ff4;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f2ff4,~uVar4 - 1);
  local_4._0_1_ = 4;
  uVar2 = FUN_00463d20(local_8c,0x109);
  local_4._0_1_ = 5;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = s_D__work_rcsk_Code_game_Hud_IniFi_004f2ffc;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f2ffc,~uVar4 - 1);
  local_4._0_1_ = 6;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = s_HeadUp_Display_exception_in__004f3028;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f3028,~uVar4 - 1);
  local_4._0_1_ = 7;
  uVar3 = FUN_00459040(local_1c,local_b8,local_108);
  local_4._0_1_ = 8;
  uVar3 = FUN_0041b630(local_6c,uVar3,&DAT_004f2ff8);
  local_4._0_1_ = 9;
  uVar2 = FUN_00459040(local_2c,uVar3,uVar2);
  local_4._0_1_ = 10;
  uVar2 = FUN_00459040(local_4c,uVar2,local_f8);
  local_4._0_1_ = 0xb;
  uVar2 = FUN_00459040(local_7c,uVar2,local_e8);
  local_4._0_1_ = 0xc;
  uVar2 = FUN_00459040(local_5c,uVar2,param_1);
  local_4._0_1_ = 0xd;
  uVar2 = FUN_0041b630(local_3c,uVar2,&DAT_004f2fc8);
  local_4 = CONCAT31(local_4._1_3_,0xe);
  FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_a8,&DAT_004d6580);
}

