/*
 * FUN_0046a3f0 at 0046a3f0
 * undefined FUN_0046a3f0(void)
 * Address ranges: 0046a3f0-0046a705
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0046a3f0(int param_1)

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
  puStack_8 = &LAB_004cffb7;
  local_c = ExceptionList;
  _DAT_00544b1c = 0x3fa00000;
  _DAT_00544b18 = 0x3fa00000;
  _DAT_00544b20 = 0x3a83126f;
  _DAT_00544b28 = 0x3ea3d70a;
  _DAT_00544b24 = 0x3ecccccd;
  ExceptionList = &local_c;
  uVar2 = FUN_0042abc0();
  *(undefined4 *)(param_1 + 0x80) = uVar2;
  FUN_0046aa80();
  FUN_0046a9d0();
  FUN_0046b5e0();
  switch(*(undefined4 *)(param_1 + 0x80)) {
  case 0:
    FUN_0046a9e0();
    ExceptionList = local_c;
    return;
  case 1:
    FUN_0046a9f0();
    ExceptionList = local_c;
    return;
  case 2:
    FUN_0046aa00();
    ExceptionList = local_c;
    return;
  case 3:
    FUN_0046aa10();
    ExceptionList = local_c;
    return;
  case 4:
    FUN_0046aa20();
    ExceptionList = local_c;
    return;
  case 5:
    ExceptionList = local_c;
    return;
  default:
    uVar2 = FUN_00463d20(local_4c,*(undefined4 *)(param_1 + 0x80));
    local_4 = 0;
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar6 = &DAT_004f5430;
  }
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f5430,~uVar5 - 1);
  local_4._0_1_ = 1;
  uVar3 = FUN_00463d20(local_1c,0x13b);
  local_4._0_1_ = 2;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_D__work_rcsk_Code_game_Rco_Portr_004f5438;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Portr_004f5438,~uVar5 - 1);
  local_4._0_1_ = 3;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_HeadUp_Display_exception_in__004f5464;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f5464,~uVar5 - 1);
  local_4._0_1_ = 4;
  uVar4 = FUN_00459040(local_9c,local_c8,local_e8);
  local_4._0_1_ = 5;
  uVar4 = FUN_0041b630(local_6c,uVar4,&DAT_004f5434);
  local_4._0_1_ = 6;
  uVar3 = FUN_00459040(local_2c,uVar4,uVar3);
  local_4._0_1_ = 7;
  uVar3 = FUN_00459040(local_8c,uVar3,local_d8);
  local_4._0_1_ = 8;
  uVar3 = FUN_0041b630(local_7c,uVar3,s_Unknown_race_type_004f541c);
  local_4._0_1_ = 9;
  uVar2 = FUN_00459040(local_5c,uVar3,uVar2);
  local_4._0_1_ = 10;
  uVar2 = FUN_0041b630(local_3c,uVar2,&DAT_004f5418);
  local_4 = CONCAT31(local_4._1_3_,0xb);
  FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_b8,&DAT_004d6580);
}

