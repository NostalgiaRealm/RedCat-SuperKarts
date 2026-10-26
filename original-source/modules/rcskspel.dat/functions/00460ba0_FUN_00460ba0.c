/*
 * FUN_00460ba0 at 00460ba0
 * undefined FUN_00460ba0(void)
 * Address ranges: 00460ba0-00460dd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00460ba0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  undefined1 local_dc [16];
  undefined1 local_cc [16];
  undefined1 local_bc [16];
  void *local_ac;
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
  puStack_8 = &LAB_004cf0af;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_ac = operator_new(0x84);
  local_4 = 0;
  if (local_ac == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004585e0(param_2);
  }
  local_4 = 0xffffffff;
  if (iVar2 != 0) {
    FUN_00460de0(param_1,iVar2);
    ExceptionList = local_c;
    return iVar2;
  }
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = &DAT_004f3a10;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f3a10,~uVar5 - 1);
  local_4 = 1;
  uVar3 = FUN_00463d20(local_1c,0x93);
  local_4._0_1_ = 2;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_D__work_rcsk_Code_game_Hud_Manag_004f3a18;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Manag_004f3a18,~uVar5 - 1);
  local_4._0_1_ = 3;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_HeadUp_Display_exception_in__004f3a40;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f3a40,~uVar5 - 1);
  local_4._0_1_ = 4;
  uVar4 = FUN_00459040(local_8c,local_cc,local_dc);
  local_4._0_1_ = 5;
  uVar4 = FUN_0041b630(local_6c,uVar4,&DAT_004f3a14);
  local_4._0_1_ = 6;
  uVar3 = FUN_00459040(local_2c,uVar4,uVar3);
  local_4._0_1_ = 7;
  uVar3 = FUN_00459040(local_4c,uVar3,local_bc);
  local_4._0_1_ = 8;
  uVar3 = FUN_0041b630(local_7c,uVar3,s_Unable_to_create_CHudComposite_004f39f0);
  local_4._0_1_ = 9;
  uVar3 = FUN_00459040(local_5c,uVar3,param_2);
  local_4._0_1_ = 10;
  uVar3 = FUN_0041b630(local_3c,uVar3,&DAT_004f39ec);
  local_4 = CONCAT31(local_4._1_3_,0xb);
  FUN_00459dc0(uVar3);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_a8,&DAT_004d6580);
}

