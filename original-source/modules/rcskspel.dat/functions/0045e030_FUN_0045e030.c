/*
 * FUN_0045e030 at 0045e030
 * undefined FUN_0045e030(void)
 * Address ranges: 0045e030-0045e355;0045e357-0045e455
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045e030(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  undefined1 local_108 [16];
  undefined1 local_f8 [16];
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [4];
  int local_b4;
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined1 local_88 [28];
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
  puStack_8 = &LAB_004ceab0;
  local_c = ExceptionList;
  puVar2 = *(undefined1 **)(param_1 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  ExceptionList = &local_c;
  iVar3 = FUN_004b1f60(puVar2,&DAT_004f2cb0);
  if (4 < iVar3) {
    uVar4 = FUN_00464060(local_d8,0);
    local_4 = 0x13;
    FUN_0041b630(local_b8,uVar4,&DAT_004f34ac);
    local_4 = CONCAT31(local_4._1_3_,0x15);
    FUN_0040b4f0(1);
    iVar3 = FUN_004b20c0(1);
    iVar6 = FUN_004b20c0(2);
    iVar7 = FUN_004b20c0(3);
    iVar8 = FUN_004b20c0(4);
    uVar4 = FUN_0045ed60((float)iVar3,(float)iVar6,(float)iVar7,(float)iVar8,local_b8);
    FUN_0045ae60(param_2,uVar4,(float)iVar7);
    if (local_b4 != 0) {
      cVar1 = *(char *)(local_b4 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(local_b4 + -1);
      }
      else {
        *(char *)(local_b4 + -1) = cVar1 + -1;
      }
    }
    ExceptionList = local_c;
    return;
  }
  uVar4 = FUN_00463d20(local_98,iVar3);
  local_4 = 0;
  uVar4 = FUN_00412710(local_a8,s_Wrong_number_of_arguments___004f3428,uVar4);
  local_4._0_1_ = 1;
  FUN_0041b630(local_c8,uVar4,s___in_character_004f3418);
  local_4._0_1_ = 4;
  FUN_0040b4f0(1);
  local_4._0_1_ = 3;
  FUN_0040b4f0(1);
  FUN_0045b1e0(1,param_2);
  uVar4 = FUN_00463d20(local_d8,(int)(char)param_2);
  local_4._0_1_ = 5;
  uVar4 = FUN_00412710(local_e8,&DAT_004f3450,uVar4);
  local_4._0_1_ = 6;
  uVar4 = FUN_0041b630(local_108,uVar4,s___in_font_004f3444);
  local_4._0_1_ = 7;
  uVar4 = FUN_00459040(local_f8,uVar4,param_3 + 0x808);
  local_4._0_1_ = 8;
  FUN_00460300(uVar4,0,0xffffffff);
  local_4._0_1_ = 7;
  FUN_0040b4f0(1);
  local_4._0_1_ = 6;
  FUN_0040b4f0(1);
  local_4._0_1_ = 5;
  FUN_0040b4f0(1);
  local_4._0_1_ = 3;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar9 = 0xffffffff;
  pcVar10 = &DAT_004f3458;
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f3458,~uVar9 - 1);
  local_4._0_1_ = 9;
  uVar4 = FUN_00463d20(local_d8,0x30a);
  local_4._0_1_ = 10;
  FUN_0040b4f0(0);
  uVar9 = 0xffffffff;
  pcVar10 = s_D__work_rcsk_Code_game_Hud_IniFi_004f3460;
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f3460,~uVar9 - 1);
  local_4._0_1_ = 0xb;
  FUN_0040b4f0(0);
  uVar9 = 0xffffffff;
  pcVar10 = s_HeadUp_Display_exception_in__004f348c;
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f348c,~uVar9 - 1);
  local_4._0_1_ = 0xc;
  uVar5 = FUN_00459040(local_4c,local_108,local_e8);
  local_4._0_1_ = 0xd;
  uVar5 = FUN_0041b630(local_1c,uVar5,&DAT_004f345c);
  local_4._0_1_ = 0xe;
  uVar4 = FUN_00459040(local_6c,uVar5,uVar4);
  local_4._0_1_ = 0xf;
  uVar4 = FUN_00459040(local_2c,uVar4,local_f8);
  local_4._0_1_ = 0x10;
  uVar4 = FUN_00459040(local_5c,uVar4,local_c8);
  local_4._0_1_ = 0x11;
  uVar4 = FUN_0041b630(local_3c,uVar4,&DAT_004f3454);
  local_4 = CONCAT31(local_4._1_3_,0x12);
  FUN_00459dc0(uVar4);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_88,&DAT_004d6580);
}

