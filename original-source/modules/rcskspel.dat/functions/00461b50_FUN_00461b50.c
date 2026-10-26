/*
 * FUN_00461b50 at 00461b50
 * undefined FUN_00461b50(void)
 * Address ranges: 00461b50-0046216a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall
FUN_00461b50(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uStack_1b0;
  int *local_1ac;
  undefined1 local_1a8 [16];
  undefined1 local_198 [16];
  void *local_188;
  undefined1 local_184 [16];
  undefined1 local_174 [16];
  undefined1 local_164 [16];
  undefined1 local_154 [16];
  undefined1 local_144 [28];
  undefined1 local_128 [16];
  undefined1 local_118 [16];
  undefined1 local_108 [16];
  undefined1 local_f8 [16];
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
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
  undefined1 local_1c [12];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cf3ad;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = FUN_004621a0(param_3);
  if (iVar2 != 0) {
    local_198[0] = uStack_1b0._3_1_;
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar6 = &DAT_004f3d40;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_0040b540(&DAT_004f3d40,~uVar5 - 1);
    local_4 = 0;
    uVar3 = FUN_00463d20(local_d8,0x1b7);
    local_4._0_1_ = 1;
    local_184[0] = uStack_1b0._3_1_;
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar6 = s_D__work_rcsk_Code_game_Hud_Manag_004f3d48;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Manag_004f3d48,~uVar5 - 1);
    local_4._0_1_ = 2;
    local_1a8[0] = uStack_1b0._3_1_;
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar6 = s_HeadUp_Display_exception_in__004f3d70;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_0040b540(s_HeadUp_Display_exception_in__004f3d70,~uVar5 - 1);
    local_4._0_1_ = 3;
    uVar4 = FUN_00459040(local_c8,local_1a8,local_184);
    local_4._0_1_ = 4;
    uVar4 = FUN_0041b630(local_b8,uVar4,&DAT_004f3d44);
    local_4._0_1_ = 5;
    uVar3 = FUN_00459040(local_f8,uVar4,uVar3);
    local_4._0_1_ = 6;
    uVar3 = FUN_00459040(local_128,uVar3,local_198);
    local_4._0_1_ = 7;
    uVar3 = FUN_0041b630(local_118,uVar3,s_Trying_to_add_string_with_duplic_004f3d14);
    local_4._0_1_ = 8;
    uVar3 = FUN_00459040(local_108,uVar3,param_3);
    local_4._0_1_ = 9;
    uVar3 = FUN_0041b630(local_e8,uVar3,&DAT_004f3d10);
    local_4 = CONCAT31(local_4._1_3_,10);
    FUN_00459dc0(uVar3);
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_144,&DAT_004d6580);
  }
  if (param_6 == 0) {
    local_188 = operator_new(0xac);
    local_4 = 0xb;
    if (local_188 != (void *)0x0) {
      local_1ac = (int *)FUN_0045a000(param_3,param_4,param_5,2);
      goto LAB_00461f60;
    }
  }
  else {
    if (param_6 != 1) {
      local_184[0] = uStack_1b0._3_1_;
      FUN_0040b4f0(0);
      uVar5 = 0xffffffff;
      pcVar6 = &DAT_004f3db0;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(&DAT_004f3db0,~uVar5 - 1);
      local_4 = 0xd;
      uVar3 = FUN_00463d20(local_e8,0x1c5);
      local_4._0_1_ = 0xe;
      local_198[0] = uStack_1b0._3_1_;
      FUN_0040b4f0(0);
      uVar5 = 0xffffffff;
      pcVar6 = s_D__work_rcsk_Code_game_Hud_Manag_004f3db8;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Manag_004f3db8,~uVar5 - 1);
      local_1a8[0] = uStack_1b0._3_1_;
      local_4._0_1_ = 0xf;
      FUN_0040b4f0(0);
      uVar5 = 0xffffffff;
      pcVar6 = s_HeadUp_Display_exception_in__004f3de0;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_HeadUp_Display_exception_in__004f3de0,~uVar5 - 1);
      local_4._0_1_ = 0x10;
      uVar4 = FUN_00459040(local_108,local_1a8,local_198);
      local_4._0_1_ = 0x11;
      uVar4 = FUN_0041b630(local_118,uVar4,&DAT_004f3db4);
      local_4._0_1_ = 0x12;
      uVar3 = FUN_00459040(local_128,uVar4,uVar3);
      local_4._0_1_ = 0x13;
      uVar3 = FUN_00459040(local_f8,uVar3,local_184);
      local_4._0_1_ = 0x14;
      uVar3 = FUN_0041b630(local_b8,uVar3,s_Unknown_string_type_for_004f3d94);
      local_4._0_1_ = 0x15;
      uVar3 = FUN_00459040(local_c8,uVar3,param_3);
      local_4._0_1_ = 0x16;
      uVar3 = FUN_0041b630(local_d8,uVar3,&DAT_004f3d90);
      local_4 = CONCAT31(local_4._1_3_,0x17);
      FUN_00459dc0(uVar3);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_144,&DAT_004d6580);
    }
    local_188 = operator_new(0xac);
    local_4 = 0xc;
    if (local_188 != (void *)0x0) {
      local_1ac = (int *)FUN_00462b40(param_3,param_4,param_5,0);
      goto LAB_00461f60;
    }
  }
  local_1ac = (int *)0x0;
LAB_00461f60:
  local_4 = 0xffffffff;
  if (local_1ac != (int *)0x0) {
    FUN_00460de0(param_2,local_1ac);
    (**(code **)(*local_1ac + 0x4c))(param_1);
    FUN_004629a0(*(undefined4 *)(*(int *)(param_1 + 0x14) + 8),&uStack_1b0);
    ExceptionList = pvStack_10;
    return uStack_1b0;
  }
  local_164[0] = uStack_1b0._3_1_;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = &DAT_004f3e2c;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f3e2c,~uVar5 - 1);
  local_4 = 0x18;
  uVar3 = FUN_00463d20(local_3c,0x1ca);
  local_4._0_1_ = 0x19;
  local_174[0] = uStack_1b0._3_1_;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_D__work_rcsk_Code_game_Hud_Manag_004f3e34;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Manag_004f3e34,~uVar5 - 1);
  local_4._0_1_ = 0x1a;
  local_154[0] = uStack_1b0._3_1_;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_HeadUp_Display_exception_in__004f3e5c;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f3e5c,~uVar5 - 1);
  local_4._0_1_ = 0x1b;
  uVar4 = FUN_00459040(local_8c,local_154,local_174);
  local_4._0_1_ = 0x1c;
  uVar4 = FUN_0041b630(local_1c,uVar4,&DAT_004f3e30);
  local_4._0_1_ = 0x1d;
  uVar3 = FUN_00459040(local_6c,uVar4,uVar3);
  local_4._0_1_ = 0x1e;
  uVar3 = FUN_00459040(local_2c,uVar3,local_164);
  local_4._0_1_ = 0x1f;
  uVar3 = FUN_0041b630(local_4c,uVar3,s_Unable_to_create_new_overlay_str_004f3e04);
  local_4._0_1_ = 0x20;
  uVar3 = FUN_00459040(local_7c,uVar3,param_3);
  local_4._0_1_ = 0x21;
  uVar3 = FUN_0041b630(local_5c,uVar3,&DAT_004f3e00);
  local_4 = CONCAT31(local_4._1_3_,0x22);
  FUN_00459dc0(uVar3);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_a8,&DAT_004d6580);
}

