/*
 * FUN_0045e460 at 0045e460
 * undefined FUN_0045e460(void)
 * Address ranges: 0045e460-0045e798
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045e460(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  undefined1 local_138 [16];
  undefined1 local_128 [16];
  undefined1 local_118 [16];
  undefined1 local_108 [16];
  undefined1 local_f8 [16];
  undefined1 local_e8 [8];
  int local_e0;
  undefined1 local_d8 [16];
  undefined1 local_c8 [28];
  undefined1 local_ac [16];
  undefined1 local_9c [16];
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
  puStack_8 = &LAB_004ceb60;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_004b1ed0(s_Strings_004f2cd4,s_Count_004f2d2c);
  iVar7 = 0;
  if (0 < iVar2) {
    do {
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar8 = s_Strings_004f2cd4;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_Strings_004f2cd4,~uVar6 - 1);
      local_4 = 0;
      uVar3 = FUN_00463d20(local_d8,iVar7);
      local_4._0_1_ = 1;
      FUN_00464150(local_e8,local_138,uVar3);
      local_4._0_1_ = 4;
      FUN_0040b4f0(1);
      local_4._0_1_ = 3;
      FUN_0040b4f0(1);
      if (local_e0 == 0) {
        uVar3 = FUN_00463d20(local_ac,iVar7);
        local_4._0_1_ = 5;
        FUN_0040b4f0(0);
        uVar6 = 0xffffffff;
        pcVar8 = s_Overlay_heading_004f34c4;
        goto code_r0x0045e5ba;
      }
      FUN_0045e7a0(local_e8);
      local_4 = 0xffffffff;
      FUN_0040b4f0(1);
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar2);
  }
  ExceptionList = local_c;
  return;
  while( true ) {
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    if (cVar1 == '\0') break;
code_r0x0045e5ba:
    if (uVar6 == 0) break;
  }
  FUN_0040b540(s_Overlay_heading_004f34c4,~uVar6 - 1);
  local_4._0_1_ = 6;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar8 = &DAT_004f34d8;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f34d8,~uVar6 - 1);
  local_4._0_1_ = 7;
  uVar4 = FUN_00463d20(local_1c,0x32c);
  local_4._0_1_ = 8;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar8 = s_D__work_rcsk_Code_game_Hud_IniFi_004f34e0;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f34e0,~uVar6 - 1);
  local_4._0_1_ = 9;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar8 = s_HeadUp_Display_exception_in__004f350c;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f350c,~uVar6 - 1);
  local_4._0_1_ = 10;
  uVar5 = FUN_00459040(local_8c,local_f8,local_128);
  local_4._0_1_ = 0xb;
  uVar5 = FUN_0041b630(local_4c,uVar5,&DAT_004f34dc);
  local_4._0_1_ = 0xc;
  uVar4 = FUN_00459040(local_6c,uVar5,uVar4);
  local_4._0_1_ = 0xd;
  uVar4 = FUN_00459040(local_2c,uVar4,local_118);
  local_4._0_1_ = 0xe;
  uVar4 = FUN_00459040(local_9c,uVar4,local_108);
  local_4._0_1_ = 0xf;
  uVar3 = FUN_00459040(local_7c,uVar4,uVar3);
  local_4._0_1_ = 0x10;
  uVar3 = FUN_0041b630(local_5c,uVar3,s_not_found_004f34b8);
  local_4._0_1_ = 0x11;
  uVar3 = FUN_0041b630(local_3c,uVar3,&DAT_004f34b4);
  local_4 = CONCAT31(local_4._1_3_,0x12);
  FUN_00459dc0(uVar3);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_c8,&DAT_004d6580);
}

