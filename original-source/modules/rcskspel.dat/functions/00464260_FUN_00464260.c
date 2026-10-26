/*
 * FUN_00464260 at 00464260
 * undefined FUN_00464260(void)
 * Address ranges: 00464260-00464511;00464514-0046452a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00464260(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  char *pcVar8;
  undefined1 local_158 [16];
  undefined1 local_148 [16];
  undefined1 local_138 [16];
  undefined1 local_128 [28];
  undefined1 local_10c [16];
  undefined1 local_fc [16];
  undefined1 local_ec [16];
  undefined1 local_dc [16];
  undefined1 local_cc [16];
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
  puStack_8 = &LAB_004cf65c;
  local_c = ExceptionList;
  if ((param_2 <= param_1) && (param_1 <= param_3)) {
    return;
  }
  ExceptionList = &local_c;
  uVar2 = FUN_00463d20(local_6c,param_3);
  local_4 = 0;
  uVar3 = FUN_00463d20(local_1c,param_2);
  local_4._0_1_ = 1;
  uVar4 = FUN_00463d20(local_ec,param_1);
  local_4._0_1_ = 2;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = &DAT_004f40a4;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f40a4,~uVar7 - 1);
  local_4._0_1_ = 3;
  uVar5 = FUN_00463d20(local_4c,0xa6);
  local_4._0_1_ = 4;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = s_D__work_rcsk_Code_game_Hud_Utils_004f40ac;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Utils_004f40ac,~uVar7 - 1);
  local_4._0_1_ = 5;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = s_HeadUp_Display_exception_in__004f40d4;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f40d4,~uVar7 - 1);
  local_4._0_1_ = 6;
  uVar6 = FUN_00459040(local_cc,local_138,local_158);
  local_4._0_1_ = 7;
  uVar6 = FUN_0041b630(local_10c,uVar6,&DAT_004f40a8);
  local_4._0_1_ = 8;
  uVar5 = FUN_00459040(local_ac,uVar6,uVar5);
  local_4._0_1_ = 9;
  uVar5 = FUN_00459040(local_2c,uVar5,local_148);
  local_4._0_1_ = 10;
  uVar5 = FUN_0041b630(local_8c,uVar5,s_Illegal_value_004f4094);
  local_4._0_1_ = 0xb;
  uVar4 = FUN_00459040(local_fc,uVar5,uVar4);
  local_4._0_1_ = 0xc;
  uVar4 = FUN_0041b630(local_dc,uVar4,s_for_range___004f4084);
  local_4._0_1_ = 0xd;
  uVar3 = FUN_00459040(local_bc,uVar4,uVar3);
  local_4._0_1_ = 0xe;
  uVar3 = FUN_0041b630(local_9c,uVar3,&DAT_004f4080);
  local_4._0_1_ = 0xf;
  uVar2 = FUN_00459040(local_7c,uVar3,uVar2);
  local_4._0_1_ = 0x10;
  uVar2 = FUN_0041b630(local_5c,uVar2,&DAT_004f407c);
  local_4._0_1_ = 0x11;
  uVar2 = FUN_0041b630(local_3c,uVar2,&DAT_004f4078);
  local_4 = CONCAT31(local_4._1_3_,0x12);
  FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_128,&DAT_004d6580);
}

