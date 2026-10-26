/*
 * FUN_00469690 at 00469690
 * undefined FUN_00469690(void)
 * Address ranges: 00469690-004698e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00469690(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
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
  puStack_8 = &LAB_004cfe6e;
  local_c = ExceptionList;
  switch(param_1) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    return 2;
  case 3:
    return 3;
  case 4:
    return 4;
  case 5:
    return 5;
  default:
    ExceptionList = &local_c;
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar5 = &DAT_004f51d8;
  }
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f51d8,~uVar4 - 1);
  local_4 = 0;
  uVar2 = FUN_00463d20(local_1c,0x212);
  local_4._0_1_ = 1;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = s_D__work_rcsk_Code_game_Rco_Overl_004f51e0;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Overl_004f51e0,~uVar4 - 1);
  local_4._0_1_ = 2;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = s_HeadUp_Display_exception_in__004f5208;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f5208,~uVar4 - 1);
  local_4._0_1_ = 3;
  uVar3 = FUN_00459040(local_7c,local_c8,local_a8);
  local_4._0_1_ = 4;
  uVar3 = FUN_0041b630(local_2c,uVar3,&DAT_004f51dc);
  local_4._0_1_ = 5;
  uVar2 = FUN_00459040(local_4c,uVar3,uVar2);
  local_4._0_1_ = 6;
  uVar2 = FUN_00459040(local_6c,uVar2,local_b8);
  local_4._0_1_ = 7;
  uVar2 = FUN_0041b630(local_5c,uVar2,s_Unreachable_code_004f51c4);
  local_4._0_1_ = 8;
  uVar2 = FUN_0041b630(local_3c,uVar2,&DAT_004f51c0);
  local_4 = CONCAT31(local_4._1_3_,9);
  FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_98,&DAT_004d6580);
}

