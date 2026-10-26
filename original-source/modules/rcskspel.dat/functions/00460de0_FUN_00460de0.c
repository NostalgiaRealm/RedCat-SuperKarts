/*
 * FUN_00460de0 at 00460de0
 * undefined FUN_00460de0(void)
 * Address ranges: 00460de0-00460ffd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00460de0(undefined4 param_1,int *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
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
  puStack_8 = &LAB_004cf11d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar2 = FUN_004583c0();
  iVar3 = FUN_004612e0(uVar2);
  if (iVar3 == 0) {
    iVar3 = *param_2;
    uVar2 = FUN_00458590();
    (**(code **)(iVar3 + 0x28))(uVar2);
    FUN_00458900(param_2);
    ExceptionList = pvStack_10;
    return;
  }
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = &DAT_004f3a84;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f3a84,~uVar5 - 1);
  local_4 = 0;
  uVar2 = FUN_00463d20(local_6c,0xaa);
  local_4._0_1_ = 1;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_D__work_rcsk_Code_game_Hud_Manag_004f3a8c;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Manag_004f3a8c,~uVar5 - 1);
  local_4._0_1_ = 2;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_HeadUp_Display_exception_in__004f3ab4;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f3ab4,~uVar5 - 1);
  local_4._0_1_ = 3;
  uVar4 = FUN_00459040(local_1c,local_d8,local_b8);
  local_4._0_1_ = 4;
  uVar4 = FUN_0041b630(local_8c,uVar4,&DAT_004f3a88);
  local_4._0_1_ = 5;
  uVar2 = FUN_00459040(local_2c,uVar4,uVar2);
  local_4._0_1_ = 6;
  uVar2 = FUN_00459040(local_4c,uVar2,local_c8);
  local_4._0_1_ = 7;
  uVar2 = FUN_0041b630(local_7c,uVar2,s_Component_name_already_exists__004f3a64);
  local_4._0_1_ = 8;
  uVar4 = FUN_004583c0();
  uVar2 = FUN_00459040(local_5c,uVar2,uVar4);
  local_4._0_1_ = 9;
  uVar2 = FUN_0041b630(local_3c,uVar2,&DAT_004f3a60);
  local_4 = CONCAT31(local_4._1_3_,10);
  FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_a8,&DAT_004d6580);
}

