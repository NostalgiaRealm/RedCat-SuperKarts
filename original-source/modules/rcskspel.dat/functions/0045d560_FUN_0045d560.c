/*
 * FUN_0045d560 at 0045d560
 * undefined FUN_0045d560(void)
 * Address ranges: 0045d560-0045d5ff;0045d7cf-0045d975
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045d560(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  char *pcVar8;
  undefined1 local_1bc [16];
  undefined1 local_1ac [16];
  undefined1 local_19c [32];
  undefined1 local_17c [16];
  undefined1 local_16c [16];
  undefined1 local_15c [16];
  undefined1 local_14c [16];
  undefined1 local_13c [32];
  undefined1 local_11c [32];
  undefined1 local_fc [16];
  undefined1 local_ec [60];
  undefined1 local_b0 [60];
  undefined1 local_74 [32];
  undefined1 local_54 [32];
  undefined1 local_34 [32];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004ce8f4;
  local_10 = ExceptionList;
  local_14 = &stack0xfffffdf8;
  puVar2 = *(undefined1 **)(param_1 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  ExceptionList = &local_10;
  iVar3 = FUN_004b1f60(puVar2,&DAT_004f2cb0);
  if ((iVar3 < 4) && (1 < iVar3)) {
    local_8 = 0xe;
    FUN_00463f20(0,param_2);
    FUN_00463f20(1,param_3);
    if (iVar3 == 3) {
      FUN_00463f20(2,param_4);
    }
    ExceptionList = local_10;
    return;
  }
  uVar4 = FUN_00463d20(local_14c,iVar3);
  local_8 = 0;
  local_74[0] = param_1._3_1_;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = &DAT_004f32c8;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f32c8,~uVar7 - 1);
  local_8._0_1_ = 1;
  uVar5 = FUN_00463d20(local_1ac,0x285);
  local_8._0_1_ = 2;
  local_34[0] = param_1._3_1_;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = s_D__work_rcsk_Code_game_Hud_IniFi_004f32d0;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f32d0,~uVar7 - 1);
  local_8._0_1_ = 3;
  local_54[0] = param_1._3_1_;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = s_HeadUp_Display_exception_in__004f32fc;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f32fc,~uVar7 - 1);
  local_8._0_1_ = 4;
  uVar6 = FUN_00459040(local_16c,local_54,local_34);
  local_8._0_1_ = 5;
  uVar6 = FUN_0041b630(local_ec,uVar6,&DAT_004f32cc);
  local_8._0_1_ = 6;
  uVar5 = FUN_00459040(local_fc,uVar6,uVar5);
  local_8._0_1_ = 7;
  uVar5 = FUN_00459040(local_11c,uVar5,local_74);
  local_8._0_1_ = 8;
  uVar5 = FUN_0041b630(local_13c,uVar5,s_Invalid_no_of_X_Y_Z_arguments___004f32a8);
  local_8._0_1_ = 9;
  uVar4 = FUN_00459040(local_15c,uVar5,uVar4);
  local_8._0_1_ = 10;
  uVar4 = FUN_0041b630(local_17c,uVar4,s_for_line_004f329c);
  local_8._0_1_ = 0xb;
  uVar4 = FUN_00459040(local_19c,uVar4,param_1);
  local_8._0_1_ = 0xc;
  uVar4 = FUN_0041b630(local_1bc,uVar4,&DAT_004f3298);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  FUN_00459dc0(uVar4);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_b0,&DAT_004d6580);
}

