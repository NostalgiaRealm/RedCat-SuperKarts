/*
 * FUN_0046c910 at 0046c910
 * undefined FUN_0046c910(void)
 * Address ranges: 0046c910-0046cc51
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046c910(int param_1)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  char *pcVar7;
  float10 fVar8;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined1 auStack_c8 [16];
  undefined1 auStack_b8 [16];
  undefined1 auStack_a8 [16];
  undefined1 auStack_98 [28];
  undefined1 auStack_7c [16];
  undefined1 auStack_6c [16];
  undefined1 auStack_5c [16];
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [16];
  undefined1 auStack_2c [16];
  undefined1 auStack_1c [16];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0407;
  pvStack_c = ExceptionList;
  bVar3 = false;
  bVar2 = false;
  ExceptionList = &pvStack_c;
  if (*(int *)(param_1 + 8) != 1) {
    ExceptionList = &pvStack_c;
    FUN_0040b4f0(0);
    uVar6 = 0xffffffff;
    pcVar7 = s_D__work_rcsk_Code_game_Rco_Speci_004f5aa0;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Speci_004f5aa0,~uVar6 - 1);
    local_4 = 0;
    FUN_0040b4f0(0);
    uVar6 = 0xffffffff;
    pcVar7 = s_m_State____ST_MOVING_004f5ad0;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    FUN_0040b540(s_m_State____ST_MOVING_004f5ad0,~uVar6 - 1);
    bVar3 = true;
    bVar2 = true;
    local_4 = 1;
    FUN_00464610(local_d8,local_e8,0x11d);
  }
  local_4 = 0;
  if (bVar2) {
    FUN_0040b4f0(1);
  }
  local_4 = 0xffffffff;
  if (bVar3) {
    FUN_0040b4f0(1);
  }
  fVar8 = (float10)FUN_0048f4e0();
  *(float *)(param_1 + 0x24) =
       (float)(fVar8 * (float10)1000.0 + (float10)*(float *)(param_1 + 0x24));
  fVar8 = (float10)FUN_0048f4e0();
  fVar8 = fVar8 * (float10)1000.0 + (float10)*(float *)(param_1 + 0x68);
  *(float *)(param_1 + 0x68) = (float)fVar8;
  if ((*(float *)(param_1 + 100) <= 0.1) || (fVar8 < (float10)*(float *)(param_1 + 100))) {
    if (*(float *)(param_1 + 0x28) <= *(float *)(param_1 + 0x24)) {
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    switch(*(undefined4 *)(param_1 + 0x6c)) {
    case 0:
      break;
    case 1:
      FUN_0046d210();
      break;
    case 2:
      FUN_0046d290();
      break;
    case 3:
      FUN_0046d320();
      break;
    case 4:
      FUN_0046d3c0();
      break;
    case 5:
      FUN_0046d5d0();
      break;
    default:
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar7 = &DAT_004f5b08;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(&DAT_004f5b08,~uVar6 - 1);
      local_4 = 2;
      uVar4 = FUN_00463d20(auStack_7c,0x142);
      local_4._0_1_ = 3;
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar7 = s_D__work_rcsk_Code_game_Rco_Speci_004f5b10;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Speci_004f5b10,~uVar6 - 1);
      local_4._0_1_ = 4;
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar7 = s_HeadUp_Display_exception_in__004f5b40;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_HeadUp_Display_exception_in__004f5b40,~uVar6 - 1);
      local_4._0_1_ = 5;
      uVar5 = FUN_00459040(auStack_1c,auStack_c8,auStack_a8);
      local_4._0_1_ = 6;
      uVar5 = FUN_0041b630(auStack_2c,uVar5,&DAT_004f5b0c);
      local_4._0_1_ = 7;
      uVar4 = FUN_00459040(auStack_4c,uVar5,uVar4);
      local_4._0_1_ = 8;
      uVar4 = FUN_00459040(auStack_6c,uVar4,auStack_b8);
      local_4._0_1_ = 9;
      uVar4 = FUN_0041b630(auStack_5c,uVar4,s_Unreachable_code_reached__004f5aec);
      local_4._0_1_ = 10;
      uVar4 = FUN_0041b630(auStack_3c,uVar4,&DAT_004f5ae8);
      local_4 = CONCAT31(local_4._1_3_,0xb);
      FUN_00459dc0(uVar4);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(auStack_98,&DAT_004d6580);
    }
  }
  else {
    FUN_0046cc70();
  }
  ExceptionList = pvStack_c;
  return;
}

