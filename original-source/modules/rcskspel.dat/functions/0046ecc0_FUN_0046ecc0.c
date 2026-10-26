/*
 * FUN_0046ecc0 at 0046ecc0
 * undefined FUN_0046ecc0(void)
 * Address ranges: 0046ecc0-0046f060
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046ecc0(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  char *pcVar8;
  float10 fVar9;
  undefined1 local_11c [16];
  undefined1 local_10c [16];
  undefined1 local_fc [16];
  undefined1 local_ec [16];
  undefined1 local_dc [16];
  undefined1 local_cc [16];
  undefined1 local_bc [16];
  undefined1 local_ac [16];
  undefined1 local_9c [16];
  undefined1 local_8c [28];
  undefined1 local_70 [20];
  undefined1 local_5c [16];
  undefined1 local_4c;
  int local_48;
  float local_3c;
  undefined1 local_38 [16];
  undefined1 local_28 [4];
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004d0738;
  local_10 = ExceptionList;
  local_14 = &stack0xfffffed8;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_0046f250();
  puVar3 = (undefined1 *)FUN_00463b10();
  local_4c = *puVar3;
  FUN_0040b4f0(0);
  FUN_00412870(puVar3,0,0xffffffff);
  local_8._0_1_ = 1;
  uVar7 = DAT_0053ba18 + 1U;
  if ((int)DAT_0053ba1c <= (int)(DAT_0053ba18 + 1U)) {
    uVar7 = DAT_0053ba1c;
  }
  uVar4 = FUN_00463d20(local_38,uVar7 & ((int)uVar7 < 0) - 1);
  local_8._0_1_ = 2;
  (**(code **)(**(int **)(param_1 + 0x10) + 0x50))(uVar4);
  local_8._0_1_ = 1;
  FUN_0040b4f0(1);
  local_28[0] = local_15;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = &DAT_004f5ec8;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f5ec8,~uVar7 - 1);
  local_8._0_1_ = 3;
  uVar2 = (undefined1)local_8;
  local_8._0_1_ = 3;
  if (DAT_0053ba0c != 0xfffffff) {
    uVar4 = FUN_0046f5f0(local_38,DAT_0053ba0c);
    local_8._0_1_ = 4;
    FUN_00412870(uVar4,0,0xffffffff);
    local_8._0_1_ = 3;
    FUN_0040b4f0(1);
    uVar2 = (undefined1)local_8;
  }
  local_8._0_1_ = uVar2;
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x50))(local_28);
  if (*(int *)(param_1 + 0xc) == -1) {
    uVar4 = FUN_0042a4d0(0);
    uVar4 = FUN_0046f5f0(local_38,uVar4);
    local_8._0_1_ = 5;
    FUN_00412870(uVar4,0,0xffffffff);
    local_8._0_1_ = 3;
    FUN_0040b4f0(1);
    (**(code **)(**(int **)(param_1 + 0x18) + 0x50))(local_28);
  }
  else {
    fVar9 = (float10)FUN_0048f4d0();
    local_3c = (float)fVar9;
    if ((float10)3.0 <= fVar9 - (float10)*(int *)(param_1 + 0xc)) {
      *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    }
  }
  switch(*(undefined4 *)(param_1 + 8)) {
  case 1:
    FUN_0046f0b0();
  case 0:
  case 2:
  case 3:
  case 4:
  case 5:
    if (local_24 != 0) {
      cVar1 = *(char *)(local_24 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(local_24 + -1);
      }
      else {
        *(char *)(local_24 + -1) = cVar1 + -1;
      }
    }
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    if (local_48 != 0) {
      cVar1 = *(char *)(local_48 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(local_48 + -1);
        ExceptionList = local_10;
        return;
      }
      *(char *)(local_48 + -1) = cVar1 + -1;
    }
    ExceptionList = local_10;
    return;
  default:
    uVar4 = FUN_00463d20(local_9c,*(undefined4 *)(param_1 + 8));
    local_8._0_1_ = 6;
    local_38[0] = local_15;
    FUN_0040b4f0(0);
    uVar7 = 0xffffffff;
    pcVar8 = &DAT_004f5eec;
  }
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f5eec,~uVar7 - 1);
  local_8._0_1_ = 7;
  uVar5 = FUN_00463d20(local_11c,0x93);
  local_70[0] = local_15;
  local_8._0_1_ = 8;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = s_D__work_rcsk_Code_game_Rco_Stati_004f5ef4;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Stati_004f5ef4,~uVar7 - 1);
  local_8._0_1_ = 9;
  local_5c[0] = local_15;
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar8 = s_HeadUp_Display_exception_in__004f5f20;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f5f20,~uVar7 - 1);
  local_8._0_1_ = 10;
  uVar6 = FUN_00459040(local_ec,local_5c,local_70);
  local_8._0_1_ = 0xb;
  uVar6 = FUN_0041b630(local_cc,uVar6,&DAT_004f5ef0);
  local_8._0_1_ = 0xc;
  uVar5 = FUN_00459040(local_10c,uVar6,uVar5);
  local_8._0_1_ = 0xd;
  uVar5 = FUN_00459040(local_ac,uVar5,local_38);
  local_8._0_1_ = 0xe;
  uVar5 = FUN_0041b630(local_bc,uVar5,s_Unknown_race_type_004f5ed8);
  local_8._0_1_ = 0xf;
  uVar4 = FUN_00459040(local_dc,uVar5,uVar4);
  local_8._0_1_ = 0x10;
  uVar4 = FUN_0041b630(local_fc,uVar4,&DAT_004f5ed4);
  local_8 = CONCAT31(local_8._1_3_,0x11);
  FUN_00459dc0(uVar4);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_8c,&DAT_004d6580);
}

