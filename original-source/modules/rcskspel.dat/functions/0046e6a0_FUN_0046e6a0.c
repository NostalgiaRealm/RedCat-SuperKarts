/*
 * FUN_0046e6a0 at 0046e6a0
 * undefined FUN_0046e6a0(void)
 * Address ranges: 0046e6a0-0046ea99
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046e6a0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 unaff_EBX;
  char *pcVar6;
  undefined1 uVar7;
  undefined1 local_108 [12];
  undefined1 auStack_fc [16];
  undefined1 auStack_ec [16];
  undefined1 auStack_dc [20];
  undefined1 local_c8 [12];
  undefined1 auStack_bc [28];
  undefined1 auStack_a0 [16];
  undefined1 auStack_90 [16];
  undefined1 auStack_80 [16];
  undefined1 auStack_70 [16];
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [16];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0661;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar2 = FUN_0042abc0();
  *(undefined4 *)(param_1 + 8) = uVar2;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = "STRING_LAP_VALUE";
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540("STRING_LAP_VALUE",~uVar5 - 1);
  local_4 = 0;
  uVar2 = FUN_004621a0(local_108);
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = "STRING_LAPOF_VALUE";
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540("STRING_LAPOF_VALUE",~uVar5 - 1);
  local_4 = 1;
  uVar2 = FUN_004621a0(local_108);
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = "STRING_LAPTIME_VALUE";
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540("STRING_LAPTIME_VALUE",~uVar5 - 1);
  local_4 = 2;
  uVar2 = FUN_004621a0(local_108);
  *(undefined4 *)(param_1 + 0x18) = uVar2;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = "STRING_BESTLAP_VALUE";
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540("STRING_BESTLAP_VALUE",~uVar5 - 1);
  local_4 = 3;
  uVar2 = FUN_004621a0(local_108);
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0046f250();
  uVar2 = FUN_00463d20(local_c8,DAT_0053ba1c);
  local_4 = 4;
  uVar2 = FUN_00412710(local_108,&DAT_004f5e2c,uVar2);
  local_4 = CONCAT31(local_4._1_3_,5);
  (**(code **)(**(int **)(param_1 + 0x14) + 0x50))(uVar2);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,4);
  FUN_0040b4f0(1);
  puStack_8 = (undefined1 *)0xffffffff;
  FUN_0040b4f0(1);
  switch(*(undefined4 *)(param_1 + 8)) {
  case 0:
  case 2:
  case 3:
  case 4:
  case 5:
    ExceptionList = pvStack_10;
    return;
  case 1:
    FUN_0046eac0();
    ExceptionList = pvStack_10;
    return;
  default:
    uVar2 = FUN_00463d20(auStack_20,*(undefined4 *)(param_1 + 8));
    uVar7 = (undefined1)((uint)unaff_EBX >> 0x18);
    puStack_8 = (undefined1 *)0x6;
    auStack_ec[0] = uVar7;
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar6 = &DAT_004f5e48;
  }
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f5e48,~uVar5 - 1);
  puStack_8._0_1_ = 7;
  uVar3 = FUN_00463d20(auStack_a0,0x45);
  puStack_8._0_1_ = 8;
  auStack_dc[0] = uVar7;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_D__work_rcsk_Code_game_Rco_Stati_004f5e50;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Stati_004f5e50,~uVar5 - 1);
  puStack_8._0_1_ = 9;
  auStack_fc[0] = uVar7;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_HeadUp_Display_exception_in__004f5e7c;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f5e7c,~uVar5 - 1);
  puStack_8._0_1_ = 10;
  uVar4 = FUN_00459040(auStack_50,auStack_fc,auStack_dc);
  puStack_8._0_1_ = 0xb;
  uVar4 = FUN_0041b630(auStack_70,uVar4,&DAT_004f5e4c);
  puStack_8._0_1_ = 0xc;
  uVar3 = FUN_00459040(auStack_30,uVar4,uVar3);
  puStack_8._0_1_ = 0xd;
  uVar3 = FUN_00459040(auStack_90,uVar3,auStack_ec);
  puStack_8._0_1_ = 0xe;
  uVar3 = FUN_0041b630(auStack_80,uVar3,s_Unknown_race_type_004f5e34);
  puStack_8._0_1_ = 0xf;
  uVar2 = FUN_00459040(auStack_60,uVar3,uVar2);
  puStack_8._0_1_ = 0x10;
  uVar2 = FUN_0041b630(auStack_40,uVar2,&DAT_004f5e30);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,0x11);
  FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(auStack_bc,&DAT_004d6580);
}

