/*
 * FUN_0045d160 at 0045d160
 * undefined FUN_0045d160(void)
 * Address ranges: 0045d160-0045d46c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045d160(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  uint local_fc;
  undefined1 local_f8 [4];
  undefined1 *local_f4;
  int local_f0;
  undefined1 local_e8 [16];
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
  puStack_8 = &LAB_004ce7c4;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0040b4f0(0);
  uVar8 = 0xffffffff;
  pcVar9 = &DAT_004f2d24;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f2d24,~uVar8 - 1);
  local_4 = 0;
  uVar2 = FUN_004583c0(local_e8);
  FUN_00464150(local_f8,uVar2);
  local_4._0_1_ = 2;
  FUN_0040b4f0(1);
  if (local_f0 == 0) {
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
  }
  else {
    puVar3 = local_f4;
    if (local_f4 == (undefined1 *)0x0) {
      puVar3 = &DAT_004d2404;
    }
    iVar4 = FUN_004b1f60(puVar3,&DAT_004f2cb0);
    if (iVar4 != 4) {
      FUN_0040b4f0(0);
      uVar8 = 0xffffffff;
      pcVar9 = &DAT_004f3244;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(&DAT_004f3244,~uVar8 - 1);
      local_4._0_1_ = 3;
      uVar2 = FUN_00463d20(local_8c,0x244);
      local_4._0_1_ = 4;
      FUN_0040b4f0(0);
      uVar8 = 0xffffffff;
      pcVar9 = s_D__work_rcsk_Code_game_Hud_IniFi_004f324c;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f324c,~uVar8 - 1);
      local_4._0_1_ = 5;
      FUN_0040b4f0(0);
      uVar8 = 0xffffffff;
      pcVar9 = s_HeadUp_Display_exception_in__004f3278;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_HeadUp_Display_exception_in__004f3278,~uVar8 - 1);
      local_4._0_1_ = 6;
      uVar5 = FUN_00459040(local_1c,local_d8,local_b8);
      local_4._0_1_ = 7;
      uVar5 = FUN_0041b630(local_6c,uVar5,&DAT_004f3248);
      local_4._0_1_ = 8;
      uVar2 = FUN_00459040(local_2c,uVar5,uVar2);
      local_4._0_1_ = 9;
      uVar2 = FUN_00459040(local_4c,uVar2,local_c8);
      local_4._0_1_ = 10;
      uVar2 = FUN_0041b630(local_7c,uVar2,s_Invalid_number_of_arguments_for_R_004f321c);
      local_4._0_1_ = 0xb;
      uVar5 = FUN_004583c0();
      uVar2 = FUN_00459040(local_5c,uVar2,uVar5);
      local_4._0_1_ = 0xc;
      uVar2 = FUN_0041b630(local_3c,uVar2,&DAT_004f3218);
      local_4 = CONCAT31(local_4._1_3_,0xd);
      FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_a8,&DAT_004d6580);
    }
    uVar8 = FUN_004b20c0(0);
    uVar6 = FUN_004b20c0(1);
    uVar7 = FUN_004b20c0(2);
    iVar4 = FUN_004b20c0(3);
    local_fc = ((iVar4 << 8 | uVar8) << 8 | uVar6) << 8 | uVar7;
    (**(code **)(*param_1 + 0x28))(&local_fc);
    (**(code **)(*param_1 + 0x14))();
    if (local_f4 != (undefined1 *)0x0) {
      cVar1 = local_f4[-1];
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(local_f4 + -1);
      }
      else {
        local_f4[-1] = cVar1 + -1;
      }
    }
  }
  ExceptionList = local_c;
  return;
}

