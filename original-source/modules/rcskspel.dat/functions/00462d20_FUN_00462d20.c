/*
 * FUN_00462d20 at 00462d20
 * undefined FUN_00462d20(void)
 * Address ranges: 00462d20-004631c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00462d20(int param_1)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  float10 fVar8;
  undefined1 local_f8 [16];
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined1 local_c8 [4];
  int local_c4;
  int local_c0;
  undefined1 local_b8 [28];
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
  puStack_8 = &LAB_004cf4c1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004635c0(local_c8,0,*(undefined4 *)(param_1 + 0x98));
  local_4 = 0;
  FUN_00463b20();
  fVar8 = (float10)FUN_0045ae40();
  if ((float10)0.0 < fVar8) {
    fVar1 = (float)((float10)*(float *)(param_1 + 0x94) / fVar8);
    iVar5 = FUN_00463b30();
    if (iVar5 == 0) {
      FUN_004631d0(local_c8,fVar1);
    }
    else if (iVar5 == 1) {
      FUN_004632c0(local_c8,fVar1);
    }
    else {
      if (iVar5 != 2) {
        FUN_0040b4f0(0);
        uVar6 = 0xffffffff;
        pcVar7 = &DAT_004f3f90;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        FUN_0040b540(&DAT_004f3f90,~uVar6 - 1);
        local_4._0_1_ = 0xd;
        uVar3 = FUN_00463d20(local_3c,0x52);
        local_4._0_1_ = 0xe;
        FUN_0040b4f0(0);
        uVar6 = 0xffffffff;
        pcVar7 = s_D__work_rcsk_Code_game_Hud_PropS_004f3f98;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        FUN_0040b540(s_D__work_rcsk_Code_game_Hud_PropS_004f3f98,~uVar6 - 1);
        local_4._0_1_ = 0xf;
        FUN_0040b4f0(0);
        uVar6 = 0xffffffff;
        pcVar7 = s_HeadUp_Display_exception_in__004f3fc4;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        FUN_0040b540(s_HeadUp_Display_exception_in__004f3fc4,~uVar6 - 1);
        local_4._0_1_ = 0x10;
        uVar4 = FUN_00459040(local_5c,local_e8,local_d8);
        local_4._0_1_ = 0x11;
        uVar4 = FUN_0041b630(local_7c,uVar4,&DAT_004f3f94);
        local_4._0_1_ = 0x12;
        uVar3 = FUN_00459040(local_8c,uVar4,uVar3);
        local_4._0_1_ = 0x13;
        uVar3 = FUN_00459040(local_2c,uVar3,local_f8);
        local_4._0_1_ = 0x14;
        uVar3 = FUN_0041b630(local_6c,uVar3,s_Invalid_alignment_in_string_004f3f70);
        local_4._0_1_ = 0x15;
        uVar4 = FUN_004583c0();
        uVar3 = FUN_00459040(local_4c,uVar3,uVar4);
        local_4._0_1_ = 0x16;
        uVar3 = FUN_0041b630(local_9c,uVar3,&DAT_004f3f6c);
        local_4 = CONCAT31(local_4._1_3_,0x17);
        FUN_00459dc0(uVar3);
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_b8,&DAT_004d6580);
      }
      FUN_00463400(local_c8,fVar1);
    }
    iVar5 = local_c0;
    if (local_c0 < *(int *)(param_1 + 0x98)) {
      do {
        FUN_00463b80();
        FUN_00459990(0xffffffff);
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(param_1 + 0x98));
    }
    if (local_c4 != 0) {
      cVar2 = *(char *)(local_c4 + -1);
      if ((cVar2 == '\0') || (cVar2 == -1)) {
        FUN_004bc150(local_c4 + -1);
      }
      else {
        *(char *)(local_c4 + -1) = cVar2 + -1;
      }
    }
    ExceptionList = local_c;
    return;
  }
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = &DAT_004f3f18;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(&DAT_004f3f18,~uVar6 - 1);
  local_4._0_1_ = 1;
  uVar3 = FUN_00463d20(local_1c,0x42);
  local_4._0_1_ = 2;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = s_D__work_rcsk_Code_game_Hud_PropS_004f3f20;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_PropS_004f3f20,~uVar6 - 1);
  local_4._0_1_ = 3;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = s_HeadUp_Display_exception_in__004f3f4c;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f3f4c,~uVar6 - 1);
  local_4._0_1_ = 4;
  uVar4 = FUN_00459040(local_9c,local_e8,local_f8);
  local_4._0_1_ = 5;
  uVar4 = FUN_0041b630(local_4c,uVar4,&DAT_004f3f1c);
  local_4._0_1_ = 6;
  uVar3 = FUN_00459040(local_6c,uVar4,uVar3);
  local_4._0_1_ = 7;
  uVar3 = FUN_00459040(local_2c,uVar3,local_d8);
  local_4._0_1_ = 8;
  uVar3 = FUN_0041b630(local_8c,uVar3,s_Font_004f3f10);
  local_4._0_1_ = 9;
  iVar5 = FUN_00463b20();
  uVar3 = FUN_00459040(local_7c,uVar3,iVar5 + 0x808);
  local_4._0_1_ = 10;
  uVar3 = FUN_0041b630(local_5c,uVar3,s_initialized_incorrectly__All_cha_004f3ed8);
  local_4._0_1_ = 0xb;
  uVar3 = FUN_0041b630(local_3c,uVar3,&DAT_004f3ed4);
  local_4 = CONCAT31(local_4._1_3_,0xc);
  FUN_00459dc0(uVar3);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_b8,&DAT_004d6580);
}

