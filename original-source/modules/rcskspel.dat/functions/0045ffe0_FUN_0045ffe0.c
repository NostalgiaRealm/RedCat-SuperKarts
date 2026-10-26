/*
 * FUN_0045ffe0 at 0045ffe0
 * undefined FUN_0045ffe0(void)
 * Address ranges: 0045ffe0-00460249
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0045ffe0(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
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
  undefined1 local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cef40;
  local_c = ExceptionList;
  pcVar2 = *(char **)(param_1 + 4);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = "";
  }
  ExceptionList = &local_c;
  iVar3 = __strcmpi(pcVar2,(char *)&PTR_DAT_004f3888);
  if (iVar3 == 0) {
    ExceptionList = local_c;
    return 0;
  }
  pcVar2 = *(char **)(param_1 + 4);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = "";
  }
  iVar3 = __strcmpi(pcVar2,s_CENTER_004f388c);
  if (iVar3 == 0) {
    ExceptionList = local_c;
    return 1;
  }
  pcVar2 = *(char **)(param_1 + 4);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = "";
  }
  iVar3 = __strcmpi(pcVar2,s_BOTTOM_004f3894);
  if (iVar3 == 0) {
    ExceptionList = local_c;
    return 2;
  }
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar2 = &DAT_004f38bc;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f38bc,~uVar6 - 1);
  local_4 = 0;
  uVar4 = FUN_00463d20(local_6c,0x453);
  local_4._0_1_ = 1;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar2 = s_D__work_rcsk_Code_game_Hud_IniFi_004f38c4;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f38c4,~uVar6 - 1);
  local_4._0_1_ = 2;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar2 = s_HeadUp_Display_exception_in__004f38f0;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f38f0,~uVar6 - 1);
  local_4._0_1_ = 3;
  uVar5 = FUN_00459040(local_1c,local_d8,local_b8);
  local_4._0_1_ = 4;
  uVar5 = FUN_0041b630(local_8c,uVar5,&DAT_004f38c0);
  local_4._0_1_ = 5;
  uVar4 = FUN_00459040(local_2c,uVar5,uVar4);
  local_4._0_1_ = 6;
  uVar4 = FUN_00459040(local_4c,uVar4,local_c8);
  local_4._0_1_ = 7;
  uVar4 = FUN_0041b630(local_7c,uVar4,s_Wrong_vertical_alignment_004f38a0);
  local_4._0_1_ = 8;
  uVar4 = FUN_00459040(local_5c,uVar4,param_1);
  local_4._0_1_ = 9;
  uVar4 = FUN_0041b630(local_3c,uVar4,&DAT_004f389c);
  local_4 = CONCAT31(local_4._1_3_,10);
  FUN_00459dc0(uVar4);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_a8,&DAT_004d6580);
}

