/*
 * FUN_00461870 at 00461870
 * undefined FUN_00461870(void)
 * Address ranges: 00461870-00461b48
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00461870(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 local_100;
  undefined1 local_fc [16];
  undefined1 local_ec [16];
  undefined1 local_dc [16];
  undefined1 local_cc [16];
  void *local_bc;
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
  puStack_8 = &LAB_004cf231;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_004616a0(param_2);
  if (iVar2 == 0) {
    local_bc = operator_new(0x818);
    local_4 = 0xb;
    if (local_bc == (void *)0x0) {
      local_100 = 0;
    }
    else {
      local_100 = FUN_0045ab00(param_2);
    }
    local_4 = 0xffffffff;
    FUN_0040b4f0(0);
    uVar5 = 0xffffffff;
    pcVar6 = s_D__work_rcsk_Code_game_Hud_Manag_004f3ccc;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Manag_004f3ccc,~uVar5 - 1);
    local_4 = 0xc;
    uVar3 = FUN_00412710(local_b8,s_Unable_to_create_new_font_004f3cf4,param_2);
    local_4._0_1_ = 0xd;
    FUN_00464530(local_100,uVar3,local_fc,0x19e);
    local_4 = CONCAT31(local_4._1_3_,0xc);
    FUN_0040b4f0(1);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    FUN_004629a0(*(undefined4 *)(*(int *)(param_1 + 0xc) + 8),&local_100);
    ExceptionList = local_c;
    return local_100;
  }
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = &DAT_004f3c7c;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f3c7c,~uVar5 - 1);
  local_4 = 0;
  uVar3 = FUN_00463d20(local_8c,0x19a);
  local_4._0_1_ = 1;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_D__work_rcsk_Code_game_Hud_Manag_004f3c84;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Manag_004f3c84,~uVar5 - 1);
  local_4._0_1_ = 2;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar6 = s_HeadUp_Display_exception_in__004f3cac;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f3cac,~uVar5 - 1);
  local_4._0_1_ = 3;
  uVar4 = FUN_00459040(local_1c,local_cc,local_ec);
  local_4._0_1_ = 4;
  uVar4 = FUN_0041b630(local_6c,uVar4,&DAT_004f3c80);
  local_4._0_1_ = 5;
  uVar3 = FUN_00459040(local_2c,uVar4,uVar3);
  local_4._0_1_ = 6;
  uVar3 = FUN_00459040(local_4c,uVar3,local_dc);
  local_4._0_1_ = 7;
  uVar3 = FUN_0041b630(local_7c,uVar3,s_Trying_to_add_font_with_duplicat_004f3c54);
  local_4._0_1_ = 8;
  uVar3 = FUN_00459040(local_5c,uVar3,param_2);
  local_4._0_1_ = 9;
  uVar3 = FUN_0041b630(local_3c,uVar3,&DAT_004f3c50);
  local_4 = CONCAT31(local_4._1_3_,10);
  FUN_00459dc0(uVar3);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_a8,&DAT_004d6580);
}

