/*
 * FUN_0045bf40 at 0045bf40
 * undefined FUN_0045bf40(void)
 * Address ranges: 0045bf40-0045c254
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045bf40(void)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 local_128 [4];
  char *local_124;
  undefined1 local_118 [16];
  undefined1 local_108 [16];
  undefined1 local_f8 [16];
  undefined1 local_e8 [16];
  undefined1 local_d8 [28];
  undefined1 local_bc [16];
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
  puStack_8 = &LAB_004ce5b1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar3 = s_Visible_004f2d1c;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_Visible_004f2d1c,~uVar6 - 1);
  local_4 = 0;
  uVar2 = FUN_004583c0(local_118);
  FUN_00464150(local_128,uVar2);
  local_4._0_1_ = 2;
  FUN_0040b4f0(1);
  pcVar3 = local_124;
  if (local_124 == (char *)0x0) {
    pcVar3 = "";
  }
  iVar4 = __strcmpi(pcVar3,&DAT_004f30a0);
  if (iVar4 == 0) {
    uVar2 = 1;
  }
  else {
    if (local_124 == (char *)0x0) {
      local_124 = "";
    }
    iVar4 = __strcmpi(local_124,s_false_004f30a8);
    if (iVar4 != 0) {
      iVar4 = FUN_004603e0(&DAT_00544ac0);
      if (iVar4 != 0) {
        FUN_0040b4f0(0);
        uVar6 = 0xffffffff;
        pcVar3 = &DAT_004f30d8;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        FUN_0040b540(&DAT_004f30d8,~uVar6 - 1);
        local_4._0_1_ = 3;
        uVar2 = FUN_00463d20(local_2c,0x13a);
        local_4._0_1_ = 4;
        FUN_0040b4f0(0);
        uVar6 = 0xffffffff;
        pcVar3 = s_D__work_rcsk_Code_game_Hud_IniFi_004f30e0;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f30e0,~uVar6 - 1);
        local_4._0_1_ = 5;
        FUN_0040b4f0(0);
        uVar6 = 0xffffffff;
        pcVar3 = s_HeadUp_Display_exception_in__004f310c;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        FUN_0040b540(s_HeadUp_Display_exception_in__004f310c,~uVar6 - 1);
        local_4._0_1_ = 6;
        uVar5 = FUN_00459040(local_1c,local_e8,local_108);
        local_4._0_1_ = 7;
        uVar5 = FUN_0041b630(local_bc,uVar5,&DAT_004f30dc);
        local_4._0_1_ = 8;
        uVar2 = FUN_00459040(local_8c,uVar5,uVar2);
        local_4._0_1_ = 9;
        uVar2 = FUN_00459040(local_4c,uVar2,local_f8);
        local_4._0_1_ = 10;
        uVar2 = FUN_0041b630(local_6c,uVar2,s_Invalid_Visible_value_for_004f30bc);
        local_4._0_1_ = 0xb;
        uVar5 = FUN_004583c0();
        uVar2 = FUN_00459040(local_ac,uVar2,uVar5);
        local_4._0_1_ = 0xc;
        uVar2 = FUN_0041b630(local_9c,uVar2,&DAT_004f30b8);
        local_4._0_1_ = 0xd;
        uVar2 = FUN_00459040(local_7c,uVar2,local_128);
        local_4._0_1_ = 0xe;
        uVar2 = FUN_0041b630(local_5c,uVar2,&DAT_004f30b4);
        local_4._0_1_ = 0xf;
        uVar2 = FUN_0041b630(local_3c,uVar2,&DAT_004f30b0);
        local_4 = CONCAT31(local_4._1_3_,0x10);
        FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_d8,&DAT_004d6580);
      }
      goto LAB_0045bff5;
    }
    uVar2 = 0;
  }
  FUN_00458460(uVar2);
LAB_0045bff5:
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  ExceptionList = local_c;
  return;
}

