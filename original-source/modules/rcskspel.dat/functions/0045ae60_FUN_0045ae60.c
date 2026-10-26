/*
 * FUN_0045ae60 at 0045ae60
 * undefined FUN_0045ae60(void)
 * Address ranges: 0045ae60-0045b097;0045b099-0045b115
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0045ae60(int param_1,uint param_2,undefined4 param_3,float param_4)

{
  undefined4 *puVar1;
  char cVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  char *pcVar7;
  undefined1 local_f8 [16];
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [28];
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
  puStack_8 = &LAB_004ce2ee;
  local_c = ExceptionList;
  if (0.0 <= param_4) {
    puVar1 = (undefined4 *)(param_1 + (param_2 & 0xff) * 8);
    if (*(float *)(param_1 + 4 + (param_2 & 0xff) * 8) <= param_4) {
      fVar3 = param_4;
      if (param_4 < *(float *)(param_1 + 0x804)) {
        fVar3 = *(float *)(param_1 + 0x804);
      }
      *(float *)(param_1 + 0x804) = fVar3;
    }
    else {
      ExceptionList = &local_c;
      FUN_0045b170();
    }
    *puVar1 = param_3;
    puVar1[1] = param_4;
    ExceptionList = local_c;
    return;
  }
  ExceptionList = &local_c;
  uVar4 = FUN_00463e20(local_b8,param_4);
  local_4 = 0;
  uVar4 = FUN_00412710(local_a8,s_Negative_value_004f2c4c,uVar4);
  local_4._0_1_ = 1;
  FUN_0041b630(local_c8,uVar4,s_for_character_004f2c3c);
  local_4._0_1_ = 4;
  FUN_0040b4f0(1);
  local_4._0_1_ = 3;
  FUN_0040b4f0(1);
  FUN_0045b1e0(1,param_2);
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = &DAT_004f2c60;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(&DAT_004f2c60,~uVar6 - 1);
  local_4._0_1_ = 5;
  uVar4 = FUN_00463d20(local_7c,0x67);
  local_4._0_1_ = 6;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = s_D__work_rcsk_Code_game_Hud_Font__004f2c68;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Font__004f2c68,~uVar6 - 1);
  local_4._0_1_ = 7;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = s_HeadUp_Display_exception_in__004f2c8c;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f2c8c,~uVar6 - 1);
  local_4._0_1_ = 8;
  uVar5 = FUN_00459040(local_1c,local_d8,local_e8);
  local_4._0_1_ = 9;
  uVar5 = FUN_0041b630(local_2c,uVar5,&DAT_004f2c64);
  local_4._0_1_ = 10;
  uVar4 = FUN_00459040(local_4c,uVar5,uVar4);
  local_4._0_1_ = 0xb;
  uVar4 = FUN_00459040(local_6c,uVar4,local_f8);
  local_4._0_1_ = 0xc;
  uVar4 = FUN_00459040(local_5c,uVar4,local_c8);
  local_4._0_1_ = 0xd;
  uVar4 = FUN_0041b630(local_3c,uVar4,&DAT_004f2c5c);
  local_4 = CONCAT31(local_4._1_3_,0xe);
  FUN_00459dc0(uVar4);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_98,&DAT_004d6580);
}

