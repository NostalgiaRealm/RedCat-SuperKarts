/*
 * FUN_00463750 at 00463750
 * undefined FUN_00463750(void)
 * Address ranges: 00463750-004639c9;004639cb-004639e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall
FUN_00463750(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  undefined1 local_e1;
  undefined1 local_e0 [16];
  undefined1 local_d0 [16];
  void *local_c0;
  undefined1 local_bc [16];
  undefined4 *local_ac;
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
  puStack_8 = &LAB_004cf56f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_ac = param_1;
  FUN_004585e0(param_2);
  local_4 = 0;
  param_1[0x21] = &PTR_FUN_004d291c;
  local_c0 = operator_new(0x10);
  local_4._0_1_ = 1;
  if (local_c0 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00480370(&local_e1);
  }
  param_1[0x22] = uVar2;
  param_1[0x26] = param_3;
  param_1[0x23] = param_4;
  param_1[0x24] = param_5;
  param_1[0x25] = 0x3f800000;
  local_4._0_1_ = 2;
  *(undefined1 *)(param_1 + 0x27) = local_e1;
  FUN_0040b4f0(0);
  local_4._0_1_ = 3;
  *param_1 = &PTR_FUN_004d292c;
  if (0 < (int)param_1[0x26]) {
    ExceptionList = local_c;
    return param_1;
  }
  local_bc[0] = local_e1;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = &DAT_004f3ff8;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f3ff8,~uVar4 - 1);
  local_4._0_1_ = 4;
  uVar2 = FUN_00463d20(local_1c,0x21);
  local_4._0_1_ = 5;
  local_e0[0] = local_e1;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = s_D__work_rcsk_Code_game_Hud_Strin_004f4000;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Strin_004f4000,~uVar4 - 1);
  local_4._0_1_ = 6;
  local_d0[0] = local_e1;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = s_HeadUp_Display_exception_in__004f4028;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f4028,~uVar4 - 1);
  local_4._0_1_ = 7;
  uVar3 = FUN_00459040(local_8c,local_d0,local_e0);
  local_4._0_1_ = 8;
  uVar3 = FUN_0041b630(local_6c,uVar3,&DAT_004f3ffc);
  local_4._0_1_ = 9;
  uVar2 = FUN_00459040(local_2c,uVar3,uVar2);
  local_4._0_1_ = 10;
  uVar2 = FUN_00459040(local_4c,uVar2,local_bc);
  local_4._0_1_ = 0xb;
  uVar2 = FUN_0041b630(local_7c,uVar2,s_Empty_string_004f3fe8);
  local_4._0_1_ = 0xc;
  uVar2 = FUN_00459040(local_5c,uVar2,param_2);
  local_4._0_1_ = 0xd;
  uVar2 = FUN_0041b630(local_3c,uVar2,&DAT_004f3fe4);
  local_4 = CONCAT31(local_4._1_3_,0xe);
  FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_a8,&DAT_004d6580);
}

