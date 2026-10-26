/*
 * FUN_00467e30 at 00467e30
 * undefined FUN_00467e30(void)
 * Address ranges: 00467e30-0046807f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00467e30(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
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
  puStack_8 = &LAB_004cfc3d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004680a0();
  FUN_00468220();
  FUN_00468560();
  FUN_004683c0();
  FUN_00468560();
  FUN_004686e0();
  FUN_00468860();
  FUN_00468b80();
  uVar2 = FUN_0042abc0();
  switch(uVar2) {
  case 0:
  case 1:
  case 3:
  case 4:
  case 5:
    ExceptionList = local_c;
    return;
  case 2:
    FUN_00468a00();
    ExceptionList = local_c;
    return;
  default:
    uVar2 = FUN_0042abc0();
    uVar2 = FUN_00463d20(local_4c,uVar2);
    local_4 = 0;
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar6 = &DAT_004f4d64;
  }
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f4d64,~uVar5 - 1);
  local_4._0_1_ = 1;
  uVar3 = FUN_00463d20(local_1c,0xab);
  local_4._0_1_ = 2;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_D__work_rcsk_Code_game_Rco_Overl_004f4d6c;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Overl_004f4d6c,~uVar5 - 1);
  local_4._0_1_ = 3;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_HeadUp_Display_exception_in__004f4d94;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f4d94,~uVar5 - 1);
  local_4._0_1_ = 4;
  uVar4 = FUN_00459040(local_9c,local_e8,local_c8);
  local_4._0_1_ = 5;
  uVar4 = FUN_0041b630(local_6c,uVar4,&DAT_004f4d68);
  local_4._0_1_ = 6;
  uVar3 = FUN_00459040(local_2c,uVar4,uVar3);
  local_4._0_1_ = 7;
  uVar3 = FUN_00459040(local_8c,uVar3,local_d8);
  local_4._0_1_ = 8;
  uVar3 = FUN_0041b630(local_7c,uVar3,s_Unknown_race_type_004f4d50);
  local_4._0_1_ = 9;
  uVar2 = FUN_00459040(local_5c,uVar3,uVar2);
  local_4._0_1_ = 10;
  uVar2 = FUN_0041b630(local_3c,uVar2,&DAT_004f4d4c);
  local_4 = CONCAT31(local_4._1_3_,0xb);
  FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_b8,&DAT_004d6580);
}

