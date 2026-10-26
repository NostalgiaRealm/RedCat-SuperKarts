/*
 * FUN_00465990 at 00465990
 * undefined FUN_00465990(void)
 * Address ranges: 00465990-00465c77
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00465990(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  char *pcVar7;
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined1 local_68 [28];
  undefined1 local_4c [20];
  undefined1 local_38 [16];
  undefined1 local_28 [19];
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004cf86a;
  local_10 = ExceptionList;
  local_14 = &stack0xffffff1c;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = s_BonusObject_004f440c;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_BonusObject_004f440c,~uVar6 - 1);
  local_8._0_1_ = 1;
  uVar2 = FUN_00461470(local_28);
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  local_8._0_1_ = 0;
  FUN_0040b4f0(1);
  FUN_004513c0();
  uVar2 = FUN_00452190();
  *(undefined4 *)(param_1 + 0x34) = uVar2;
  local_38[0] = local_15;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = s_D__work_rcsk_Code_game_Rco_Bonus_004f4418;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Bonus_004f4418,~uVar6 - 1);
  local_8._0_1_ = 2;
  local_28[0] = local_15;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = s_Element_BonusObject_not_found_in_004f4440;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_Element_BonusObject_not_found_in_004f4440,~uVar6 - 1);
  local_8._0_1_ = 3;
  FUN_00464530(*(undefined4 *)(param_1 + 0x30),local_28,local_38,0x3f);
  local_8._0_1_ = 2;
  FUN_0040b4f0(1);
  local_8._0_1_ = 0;
  FUN_0040b4f0(1);
  FUN_00458460(0);
  puVar3 = (undefined4 *)FUN_004583d0();
  *(undefined4 *)(param_1 + 0x18) = *puVar3;
  *(undefined4 *)(param_1 + 0x1c) = puVar3[1];
  *(undefined4 *)(param_1 + 0x20) = puVar3[2];
  iVar4 = FUN_004500c0();
  if (iVar4 != -1) {
    FUN_00459990(iVar4);
    local_8 = 0xffffffff;
    uVar2 = FUN_0044ff80();
    *(undefined4 *)(param_1 + 0x3c) = uVar2;
    uVar2 = FUN_004500b0();
    *(undefined4 *)(param_1 + 0x40) = uVar2;
    uVar2 = FUN_004503c0();
    *(undefined4 *)(param_1 + 0x48) = uVar2;
    ExceptionList = local_10;
    return;
  }
  local_4c[0] = local_15;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = &DAT_004f449c;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f449c,~uVar6 - 1);
  local_8._0_1_ = 4;
  uVar2 = FUN_00463d20(local_d8,0x4a);
  local_8._0_1_ = 5;
  local_38[0] = local_15;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = s_D__work_rcsk_Code_game_Rco_Bonus_004f44a4;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Bonus_004f44a4,~uVar6 - 1);
  local_28[0] = local_15;
  local_8._0_1_ = 6;
  FUN_0040b4f0(0);
  uVar6 = 0xffffffff;
  pcVar7 = s_HeadUp_Display_exception_in__004f44cc;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f44cc,~uVar6 - 1);
  local_8._0_1_ = 7;
  uVar5 = FUN_00459040(local_78,local_28,local_38);
  local_8._0_1_ = 8;
  uVar5 = FUN_0041b630(local_c8,uVar5,&DAT_004f44a0);
  local_8._0_1_ = 9;
  uVar2 = FUN_00459040(local_a8,uVar5,uVar2);
  local_8._0_1_ = 10;
  uVar2 = FUN_00459040(local_88,uVar2,local_4c);
  local_8._0_1_ = 0xb;
  uVar2 = FUN_0041b630(local_98,uVar2,s_Unable_to_add_c_object3d_instanc_004f4470);
  local_8._0_1_ = 0xc;
  uVar2 = FUN_0041b630(local_b8,uVar2,&DAT_004f446c);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_68,&DAT_004d6580);
}

