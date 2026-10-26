/*
 * FUN_0045c4d0 at 0045c4d0
 * undefined FUN_0045c4d0(void)
 * Address ranges: 0045c4d0-0045ca98
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0045c4d0(int param_1,int *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  char *pcVar8;
  float10 fVar9;
  float *pfVar10;
  float local_fc;
  float local_f8;
  float local_f4;
  int local_f0;
  undefined1 local_ec [16];
  undefined1 local_dc [16];
  undefined1 local_cc [16];
  int local_bc;
  undefined1 local_b8 [16];
  undefined1 local_a8 [4];
  undefined1 *local_a4;
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
  puStack_8 = &LAB_004ce6d0;
  local_c = ExceptionList;
  local_fc = 0.0;
  local_f8 = 0.0;
  local_f4 = 0.0;
  ExceptionList = &local_c;
  FUN_0045cd10(param_2);
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = s_Position_004f2cec;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_Position_004f2cec,~uVar7 - 1);
  pfVar10 = &local_fc;
  puVar3 = local_cc;
  local_4 = 0;
  uVar2 = FUN_004583c0(puVar3,pfVar10);
  cVar1 = FUN_0045d470(uVar2,puVar3,pfVar10);
  local_4 = 0xffffffff;
  FUN_0040b4f0(1);
  if (cVar1 == '\0') {
    ExceptionList = local_c;
    return;
  }
  local_bc = 0;
  local_f0 = 0;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = s_Alignment_004f2d58;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_Alignment_004f2d58,~uVar7 - 1);
  local_4 = 1;
  uVar2 = FUN_004583c0(local_cc);
  FUN_00464150(local_a8,uVar2);
  local_4._0_1_ = 3;
  FUN_0040b4f0(1);
  puVar3 = local_a4;
  if (local_a4 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  iVar4 = FUN_004b1f60(puVar3,&DAT_004f312c);
  iVar5 = local_bc;
  if (iVar4 == 2) {
    FUN_00464060(local_dc,0);
    local_4._0_1_ = 4;
    iVar5 = FUN_0045fd70(local_dc);
    FUN_00464060(local_ec,1);
    local_4._0_1_ = 5;
    local_f0 = FUN_0045ffe0(local_ec);
    local_4._0_1_ = 4;
    FUN_0040b4f0(1);
    local_4._0_1_ = 3;
    FUN_0040b4f0(1);
  }
  local_fc = local_fc / *(float *)(param_1 + 0x1c);
  local_fc = (local_fc + local_fc) - *(float *)(param_1 + 0x18) / *(float *)(param_1 + 0x1c);
  if (iVar5 == 0) {
    fVar9 = (float10)(**(code **)(*param_2 + 0x34))();
    fVar9 = ((float10)*(float *)(param_1 + 0x18) / (float10)*(float *)(param_1 + 0x1c)) * fVar9 +
            (float10)local_fc;
LAB_0045c86b:
    local_fc = (float)fVar9;
  }
  else if (iVar5 != 1) {
    if (iVar5 != 2) {
      FUN_0040b4f0(0);
      uVar7 = 0xffffffff;
      pcVar8 = &DAT_004f3150;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(&DAT_004f3150,~uVar7 - 1);
      local_4._0_1_ = 6;
      uVar2 = FUN_00463d20(local_4c,0x1a8);
      local_4._0_1_ = 7;
      FUN_0040b4f0(0);
      uVar7 = 0xffffffff;
      pcVar8 = s_D__work_rcsk_Code_game_Hud_IniFi_004f3158;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f3158,~uVar7 - 1);
      local_4._0_1_ = 8;
      FUN_0040b4f0(0);
      uVar7 = 0xffffffff;
      pcVar8 = s_HeadUp_Display_exception_in__004f3184;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_HeadUp_Display_exception_in__004f3184,~uVar7 - 1);
      local_4._0_1_ = 9;
      uVar6 = FUN_00459040(local_1c,local_dc,local_b8);
      local_4._0_1_ = 10;
      uVar6 = FUN_0041b630(local_2c,uVar6,&DAT_004f3154);
      local_4._0_1_ = 0xb;
      uVar2 = FUN_00459040(local_7c,uVar6,uVar2);
      local_4._0_1_ = 0xc;
      uVar2 = FUN_00459040(local_6c,uVar2,local_ec);
      local_4._0_1_ = 0xd;
      uVar2 = FUN_0041b630(local_5c,uVar2,s_Unreachable_code_reached_004f3134);
      local_4._0_1_ = 0xe;
      uVar2 = FUN_0041b630(local_3c,uVar2,&DAT_004f3130);
      local_4 = CONCAT31(local_4._1_3_,0xf);
      FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_98,&DAT_004d6580);
    }
    fVar9 = (float10)(**(code **)(*param_2 + 0x34))();
    fVar9 = (float10)local_fc -
            ((float10)*(float *)(param_1 + 0x18) / (float10)*(float *)(param_1 + 0x1c)) * fVar9;
    goto LAB_0045c86b;
  }
  local_f8 = local_f8 / *(float *)(param_1 + 0x1c);
  local_f8 = 1.0 - (local_f8 + local_f8);
  if (local_f0 == 0) {
    fVar9 = (float10)(**(code **)(*param_2 + 0x38))();
    fVar9 = (float10)local_f8 - fVar9;
  }
  else {
    if (local_f0 == 1) goto LAB_0045ca43;
    if (local_f0 != 2) {
      FUN_0040b4f0(0);
      uVar7 = 0xffffffff;
      pcVar8 = &DAT_004f31c4;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(&DAT_004f31c4,~uVar7 - 1);
      local_4._0_1_ = 0x10;
      uVar2 = FUN_00463d20(local_3c,0x1bb);
      local_4._0_1_ = 0x11;
      FUN_0040b4f0(0);
      uVar7 = 0xffffffff;
      pcVar8 = s_D__work_rcsk_Code_game_Hud_IniFi_004f31cc;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f31cc,~uVar7 - 1);
      local_4._0_1_ = 0x12;
      FUN_0040b4f0(0);
      uVar7 = 0xffffffff;
      pcVar8 = s_HeadUp_Display_exception_in__004f31f8;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_HeadUp_Display_exception_in__004f31f8,~uVar7 - 1);
      local_4._0_1_ = 0x13;
      uVar6 = FUN_00459040(local_5c,local_dc,local_ec);
      local_4._0_1_ = 0x14;
      uVar6 = FUN_0041b630(local_6c,uVar6,&DAT_004f31c8);
      local_4._0_1_ = 0x15;
      uVar2 = FUN_00459040(local_7c,uVar6,uVar2);
      local_4._0_1_ = 0x16;
      uVar2 = FUN_00459040(local_2c,uVar2,local_b8);
      local_4._0_1_ = 0x17;
      uVar2 = FUN_0041b630(local_1c,uVar2,s_Unreachable_code_reached_004f31a8);
      local_4._0_1_ = 0x18;
      uVar2 = FUN_0041b630(local_4c,uVar2,&DAT_004f31a4);
      local_4 = CONCAT31(local_4._1_3_,0x19);
      FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_98,&DAT_004d6580);
    }
    fVar9 = (float10)(**(code **)(*param_2 + 0x38))();
    fVar9 = fVar9 + (float10)local_f8;
  }
  local_f8 = (float)fVar9;
LAB_0045ca43:
  local_f4 = local_f4 / *(float *)(param_1 + 0x20);
  FUN_00458400(&local_fc);
  if (local_a4 != (undefined1 *)0x0) {
    cVar1 = local_a4[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_a4 + -1);
    }
    else {
      local_a4[-1] = cVar1 + -1;
    }
  }
  ExceptionList = local_c;
  return;
}

