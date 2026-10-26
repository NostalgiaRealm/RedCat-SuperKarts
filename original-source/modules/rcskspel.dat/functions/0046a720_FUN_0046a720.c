/*
 * FUN_0046a720 at 0046a720
 * undefined FUN_0046a720(void)
 * Address ranges: 0046a720-0046a95a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046a720(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  undefined1 local_fc [16];
  undefined1 local_ec [16];
  undefined1 local_dc [16];
  undefined1 local_cc [16];
  undefined1 local_bc [16];
  undefined1 local_ac [16];
  undefined1 local_9c [16];
  undefined1 local_8c [16];
  undefined1 local_7c [16];
  undefined1 local_6c [32];
  undefined1 local_4c [20];
  undefined1 local_38 [16];
  undefined1 local_28 [19];
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004d0039;
  local_10 = ExceptionList;
  local_14 = &stack0xfffffef8;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_0046b5e0();
  switch(*(undefined4 *)(param_1 + 0x80)) {
  case 0:
    FUN_0046aa30();
    ExceptionList = local_10;
    return;
  case 1:
    FUN_0046aa40();
    ExceptionList = local_10;
    return;
  case 2:
    FUN_0046aa50();
    ExceptionList = local_10;
    return;
  case 3:
    FUN_0046aa60();
    ExceptionList = local_10;
    return;
  case 4:
    FUN_0046aa70();
    ExceptionList = local_10;
    return;
  case 5:
    ExceptionList = local_10;
    return;
  default:
    uVar2 = FUN_00463d20(local_fc,*(undefined4 *)(param_1 + 0x80));
    local_4c[0] = local_15;
    local_8._0_1_ = 1;
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar6 = &DAT_004f549c;
  }
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f549c,~uVar5 - 1);
  local_8._0_1_ = 2;
  uVar3 = FUN_00463d20(local_7c,0x163);
  local_8._0_1_ = 3;
  local_28[0] = local_15;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_D__work_rcsk_Code_game_Rco_Portr_004f54a4;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Portr_004f54a4,~uVar5 - 1);
  local_38[0] = local_15;
  local_8._0_1_ = 4;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_HeadUp_Display_exception_in__004f54d0;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f54d0,~uVar5 - 1);
  local_8._0_1_ = 5;
  uVar4 = FUN_00459040(local_cc,local_38,local_28);
  local_8._0_1_ = 6;
  uVar4 = FUN_0041b630(local_ac,uVar4,&DAT_004f54a0);
  local_8._0_1_ = 7;
  uVar3 = FUN_00459040(local_ec,uVar4,uVar3);
  local_8._0_1_ = 8;
  uVar3 = FUN_00459040(local_8c,uVar3,local_4c);
  local_8._0_1_ = 9;
  uVar3 = FUN_0041b630(local_9c,uVar3,s_Unknown_race_type_004f5488);
  local_8._0_1_ = 10;
  uVar2 = FUN_00459040(local_bc,uVar3,uVar2);
  local_8._0_1_ = 0xb;
  uVar2 = FUN_0041b630(local_dc,uVar2,&DAT_004f5484);
  local_8 = CONCAT31(local_8._1_3_,0xc);
  FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_6c,&DAT_004d6580);
}

