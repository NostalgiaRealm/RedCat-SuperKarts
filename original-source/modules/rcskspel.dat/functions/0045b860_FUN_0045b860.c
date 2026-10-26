/*
 * FUN_0045b860 at 0045b860
 * undefined FUN_0045b860(void)
 * Address ranges: 0045b860-0045bb95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045b860(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  undefined1 local_128 [4];
  int local_124;
  int local_120;
  undefined4 local_11c;
  undefined1 local_118 [16];
  undefined1 local_108 [16];
  undefined1 local_f8 [16];
  undefined1 local_e8 [16];
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
  puStack_8 = &LAB_004ce45c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_004b1ed0(s_Elements_004f2cc0,s_Count_004f2d2c);
  iVar7 = 0;
  if (0 < iVar2) {
    do {
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar8 = s_Elements_004f2cc0;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_Elements_004f2cc0,~uVar6 - 1);
      local_4 = 0;
      uVar3 = FUN_00463d20(local_d8,iVar7);
      local_4._0_1_ = 1;
      FUN_00464150(local_128,local_118,uVar3);
      local_4._0_1_ = 4;
      FUN_0040b4f0(1);
      local_4._0_1_ = 3;
      FUN_0040b4f0(1);
      if (local_120 == 0) {
        uVar3 = FUN_00463d20(local_1c,iVar7);
        local_4._0_1_ = 5;
        FUN_0040b4f0(0);
        uVar6 = 0xffffffff;
        pcVar8 = &DAT_004f2f74;
        goto code_r0x0045b9f6;
      }
      uVar3 = FUN_0045bba0(local_128);
      uVar3 = FUN_0045c260(local_128,uVar3);
      FUN_0045c370(uVar3);
      FUN_0045bf10(uVar3);
      local_4 = 0xffffffff;
      if (local_124 != 0) {
        cVar1 = *(char *)(local_124 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150(local_124 + -1);
        }
        else {
          *(char *)(local_124 + -1) = cVar1 + -1;
        }
      }
      iVar7 = iVar7 + 1;
      local_124 = 0;
      local_120 = 0;
      local_11c = 0;
    } while (iVar7 < iVar2);
  }
  ExceptionList = local_c;
  return;
  while( true ) {
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    if (cVar1 == '\0') break;
code_r0x0045b9f6:
    if (uVar6 == 0) break;
  }
  FUN_0040b540(&DAT_004f2f74,~uVar6 - 1);
  local_4._0_1_ = 6;
  uVar4 = FUN_00463d20(local_ac,0xf0);
  local_4._0_1_ = 7;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar8 = s_D__work_rcsk_Code_game_Hud_IniFi_004f2f7c;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f2f7c,~uVar6 - 1);
  local_4._0_1_ = 8;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar8 = s_HeadUp_Display_exception_in__004f2fa8;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f2fa8,~uVar6 - 1);
  local_4._0_1_ = 9;
  uVar5 = FUN_00459040(local_8c,local_e8,local_108);
  local_4._0_1_ = 10;
  uVar5 = FUN_0041b630(local_4c,uVar5,&DAT_004f2f78);
  local_4._0_1_ = 0xb;
  uVar4 = FUN_00459040(local_6c,uVar5,uVar4);
  local_4._0_1_ = 0xc;
  uVar4 = FUN_00459040(local_2c,uVar4,local_f8);
  local_4._0_1_ = 0xd;
  uVar4 = FUN_0041b630(local_9c,uVar4,s_Overlay_heading_004f2f60);
  local_4._0_1_ = 0xe;
  uVar3 = FUN_00459040(local_7c,uVar4,uVar3);
  local_4._0_1_ = 0xf;
  uVar3 = FUN_0041b630(local_5c,uVar3,s_not_found_004f2f54);
  local_4._0_1_ = 0x10;
  uVar3 = FUN_0041b630(local_3c,uVar3,&DAT_004f2f50);
  local_4 = CONCAT31(local_4._1_3_,0x11);
  FUN_00459dc0(uVar3);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_c8,&DAT_004d6580);
}

