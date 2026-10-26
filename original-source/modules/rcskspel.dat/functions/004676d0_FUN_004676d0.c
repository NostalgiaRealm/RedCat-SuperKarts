/*
 * FUN_004676d0 at 004676d0
 * undefined FUN_004676d0(void)
 * Address ranges: 004676d0-00467a1e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004676d0(float *param_1,int param_2,float *param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  float fVar9;
  char *pcVar10;
  float10 extraout_ST0;
  float10 fVar11;
  undefined1 local_d1;
  undefined1 local_d0 [16];
  float local_c0;
  int local_bc;
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
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
  puStack_8 = &LAB_004cfb61;
  local_c = ExceptionList;
  if (param_2 == 0) {
    fVar3 = 1.0 - param_5;
    fVar1 = param_3[1];
    fVar2 = param_4[1];
    fVar9 = param_5 * param_4[2] + fVar3 * param_3[2];
    *param_1 = param_5 * *param_4 + fVar3 * *param_3;
    param_1[1] = param_5 * fVar2 + fVar3 * fVar1;
  }
  else {
    if (param_2 != 1) {
      ExceptionList = &local_c;
      FUN_0040b4f0(0);
      uVar7 = 0xffffffff;
      pcVar10 = &DAT_004f4be8;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar4 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar4 != '\0');
      FUN_0040b540(&DAT_004f4be8,~uVar7 - 1);
      local_4 = 0;
      uVar5 = FUN_00463d20(local_7c,0xb1);
      local_4._0_1_ = 1;
      FUN_0040b4f0(0);
      uVar7 = 0xffffffff;
      pcVar10 = s_D__work_rcsk_Code_game_Rco_Movin_004f4bf0;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar4 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar4 != '\0');
      FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Movin_004f4bf0,~uVar7 - 1);
      local_4._0_1_ = 2;
      local_d0[0] = local_d1;
      FUN_0040b4f0(0);
      uVar7 = 0xffffffff;
      pcVar10 = s_HeadUp_Display_exception_in__004f4c20;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar4 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar4 != '\0');
      FUN_0040b540(s_HeadUp_Display_exception_in__004f4c20,~uVar7 - 1);
      local_4._0_1_ = 3;
      uVar6 = FUN_00459040(local_1c,local_d0,local_b8);
      local_4._0_1_ = 4;
      uVar6 = FUN_0041b630(local_2c,uVar6,&DAT_004f4bec);
      local_4._0_1_ = 5;
      uVar5 = FUN_00459040(local_4c,uVar6,uVar5);
      local_4._0_1_ = 6;
      uVar5 = FUN_00459040(local_6c,uVar5,local_a8);
      local_4._0_1_ = 7;
      uVar5 = FUN_0041b630(local_5c,uVar5,s_Unreachable_code_reached_004f4bcc);
      local_4._0_1_ = 8;
      uVar5 = FUN_0041b630(local_3c,uVar5,&DAT_004f4bc8);
      local_4 = CONCAT31(local_4._1_3_,9);
      FUN_00459dc0(uVar5);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_98,&DAT_004d6580);
    }
    local_c0 = *param_4 - *param_3;
    fpatan((float10)param_4[1] - (float10)param_3[1],(float10)local_c0);
    ExceptionList = &local_c;
    local_bc = __ftol();
    local_bc = 0x400 - local_bc;
    uVar7 = __ftol();
    iVar8 = (DAT_004fc8f8 & uVar7) * 4;
    fVar11 = SQRT(extraout_ST0 * extraout_ST0 + (float10)local_c0 * (float10)local_c0) *
             (float10)0.5;
    fVar1 = param_4[1];
    fVar2 = param_3[1];
    fVar3 = *(float *)(iVar8 + DAT_006a5cd0);
    fVar9 = param_5 * param_4[2] + (1.0 - param_5) * param_3[2];
    *param_1 = (float)((float10)*(float *)(iVar8 + DAT_006a5c88) * fVar11 +
                      ((float10)*param_3 + (float10)*param_4) * (float10)0.5);
    param_1[1] = (float)((float10)fVar3 * fVar11 + (float10)((fVar1 + fVar2) * 0.5));
  }
  param_1[2] = fVar9;
  ExceptionList = local_c;
  return;
}

