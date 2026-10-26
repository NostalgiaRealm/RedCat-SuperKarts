/*
 * FUN_00465570 at 00465570
 * undefined FUN_00465570(void)
 * Address ranges: 00465570-00465817
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00465570(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  uint uVar7;
  char *pcVar8;
  float10 fVar9;
  uint local_cc;
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [28];
  undefined1 local_7c [16];
  undefined1 local_6c [16];
  undefined1 local_5c [16];
  undefined1 local_4c [16];
  undefined1 local_3c [16];
  undefined1 local_2c [16];
  undefined1 local_1c [12];
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cf7d7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0x14) == 2) {
    if (*(float *)(param_1 + 0x20) <= 0.0) {
      ExceptionList = &local_c;
      FUN_00465820();
      ExceptionList = local_c;
      return;
    }
    ExceptionList = &local_c;
    fVar9 = (float10)FUN_0048f4e0();
    *(float *)(param_1 + 0x20) = (float)((float10)*(float *)(param_1 + 0x20) - fVar9);
  }
  fVar9 = (float10)FUN_0048f4d0();
  if ((float10)0.071428575 <= fVar9 - (float10)*(float *)(param_1 + 0x1c)) {
    *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) + 0.071428575;
    if (*(int *)(param_1 + 0x10) == 1) {
      iVar4 = *(int *)(param_1 + 0x18) + 1;
      *(int *)(param_1 + 0x18) = iVar4;
      if (iVar4 == 0xd) {
        *(undefined4 *)(param_1 + 0x10) = 2;
      }
    }
    else {
      if (*(int *)(param_1 + 0x10) != 2) {
        FUN_0040b4f0(0);
        uVar7 = 0xffffffff;
        pcVar8 = &DAT_004f4384;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        FUN_0040b540(&DAT_004f4384,~uVar7 - 1);
        local_4 = 0;
        uVar2 = FUN_00463d20(local_1c,0xb8);
        local_4._0_1_ = 1;
        FUN_0040b4f0(0);
        uVar7 = 0xffffffff;
        pcVar8 = s_D__work_rcsk_Code_game_Rco_Arrow_004f438c;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Arrow_004f438c,~uVar7 - 1);
        local_4._0_1_ = 2;
        FUN_0040b4f0(0);
        uVar7 = 0xffffffff;
        pcVar8 = s_HeadUp_Display_exception_in__004f43b4;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        FUN_0040b540(s_HeadUp_Display_exception_in__004f43b4,~uVar7 - 1);
        local_4._0_1_ = 3;
        uVar3 = FUN_00459040(local_7c,local_a8,local_c8);
        local_4._0_1_ = 4;
        uVar3 = FUN_0041b630(local_2c,uVar3,&DAT_004f4388);
        local_4._0_1_ = 5;
        uVar2 = FUN_00459040(local_4c,uVar3,uVar2);
        local_4._0_1_ = 6;
        uVar2 = FUN_00459040(local_6c,uVar2,local_b8);
        local_4._0_1_ = 7;
        uVar2 = FUN_0041b630(local_5c,uVar2,s_Unreachable_code_reached__invali_004f435c);
        local_4._0_1_ = 8;
        uVar2 = FUN_0041b630(local_3c,uVar2,&DAT_004f4358);
        local_4 = CONCAT31(local_4._1_3_,9);
        FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_98,&DAT_004d6580);
      }
      iVar4 = *(int *)(param_1 + 0x18) + -1;
      *(int *)(param_1 + 0x18) = iVar4;
      if (iVar4 == 0) {
        *(undefined4 *)(param_1 + 0x10) = 1;
      }
    }
  }
  FUN_00465880();
  puVar5 = (uint *)FUN_00458590();
  uVar7 = *puVar5;
  iVar4 = __ftol();
  local_cc = iVar4 << 0x18 | uVar7 & 0xffffff;
  piVar6 = (int *)FUN_00465880();
  (**(code **)(*piVar6 + 0x28))(&local_cc);
  ExceptionList = pvStack_10;
  return;
}

