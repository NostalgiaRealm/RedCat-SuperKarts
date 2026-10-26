/*
 * FUN_0046b5e0 at 0046b5e0
 * undefined FUN_0046b5e0(void)
 * Address ranges: 0046b5e0-0046bacc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0046b5e0(int param_1)

{
  float fVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  float local_108;
  int local_104;
  int *local_fc;
  undefined1 local_f4 [4];
  char *local_f0;
  undefined4 local_e4;
  float local_e0;
  undefined4 local_dc;
  undefined1 local_d8 [4];
  char *local_d4;
  undefined1 local_c8 [4];
  undefined4 *local_c4;
  undefined1 local_b8 [4];
  char *local_b4;
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
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0261;
  local_c = ExceptionList;
  iVar11 = 0;
  ExceptionList = &local_c;
  if (DAT_00508610 != -1 && -1 < DAT_00508610 + 1) {
    piVar9 = &DAT_005081b8;
    piVar10 = (int *)(param_1 + 0x6c);
    ExceptionList = &local_c;
    do {
      cVar2 = FUN_00417e90(iVar11);
      iVar3 = DAT_0053be60;
      if (cVar2 == '\0') {
        iVar3 = *piVar9;
      }
      *piVar10 = iVar3;
      iVar11 = iVar11 + 1;
      piVar10 = piVar10 + 1;
      piVar9 = piVar9 + 0x1c;
    } while (iVar11 < DAT_00508610 + 1);
  }
  local_104 = 0;
  if (DAT_00508610 != -1 && -1 < DAT_00508610 + 1) {
    local_fc = &DAT_005081b8;
    piVar10 = (int *)(param_1 + 0x6c);
    do {
      iVar11 = *piVar10;
      iVar3 = *(int *)(param_1 + 0x6c + *(int *)(param_1 + 0x84) * 4);
      fVar1 = (float)iVar11;
      if (iVar11 < iVar3) {
        local_108 = (fVar1 + 0.5) * _DAT_00544b28;
LAB_0046b6c2:
        fVar1 = _DAT_004f5228 * _DAT_00544b28;
      }
      else {
        if (iVar11 != iVar3) {
          local_108 = (fVar1 - 0.5) * _DAT_00544b28 + _DAT_00544b24;
          goto LAB_0046b6c2;
        }
        local_108 = _DAT_00544b24 * 0.5 + fVar1 * _DAT_00544b28;
        fVar1 = _DAT_004f522c * _DAT_00544b24;
      }
      FUN_0040b4f0(0);
      uVar7 = 0xffffffff;
      pcVar12 = s_D__work_rcsk_Code_game_Rco_Portr_004f5820;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar2 = *pcVar12;
        pcVar12 = pcVar12 + 1;
      } while (cVar2 != '\0');
      uVar7 = ~uVar7 - 1;
      cVar2 = FUN_0040b600(uVar7,1);
      if (cVar2 != '\0') {
        pcVar12 = s_D__work_rcsk_Code_game_Rco_Portr_004f5820;
        pcVar13 = local_f0;
        for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
          pcVar12 = pcVar12 + 4;
          pcVar13 = pcVar13 + 4;
        }
        for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pcVar13 = *pcVar12;
          pcVar12 = pcVar12 + 1;
          pcVar13 = pcVar13 + 1;
        }
        FUN_0040b5e0(uVar7);
      }
      local_4 = 0;
      FUN_0040b4f0(0);
      uVar7 = 0xffffffff;
      pcVar12 = s_m_Portraits_index__004f584c;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar2 = *pcVar12;
        pcVar12 = pcVar12 + 1;
      } while (cVar2 != '\0');
      FUN_0040b540(s_m_Portraits_index__004f584c,~uVar7 - 1);
      local_4._0_1_ = 1;
      FUN_00464530(piVar10[-0x19],local_a8,local_f4,0x279);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0040b4f0(1);
      local_4 = 0xffffffff;
      FUN_0040b4f0(1);
      piVar9 = (int *)piVar10[-0x19];
      if (piVar9[2] == 1) {
        (**(code **)(*piVar9 + 0x10))();
      }
      else {
        if (piVar9[2] != 2) {
          FUN_0040b4f0(0);
          uVar7 = 0xffffffff;
          pcVar12 = (char *)&DAT_004f5880;
          goto code_r0x0046b8d0;
        }
        cVar2 = FUN_00417e90(local_104);
        iVar11 = DAT_0053be60;
        if (cVar2 == '\0') {
          iVar11 = *local_fc;
        }
        if (iVar11 == piVar9[0xf]) {
          if (0.01 < ABS(((float)piVar9[7] - 1.0) + local_108)) {
            piVar9[7] = (int)(1.0 - local_108);
            FUN_0046a270();
          }
        }
        else {
          piVar9[7] = (int)(1.0 - local_108);
          FUN_0046a1f0(*piVar10);
        }
      }
      puVar4 = (undefined4 *)FUN_004583d0();
      local_e4 = *puVar4;
      local_e0 = 1.0 - (fVar1 + local_108);
      local_dc = puVar4[2];
      FUN_00458400(&local_e4);
      local_104 = local_104 + 1;
      piVar10 = piVar10 + 1;
      local_fc = local_fc + 0x1c;
    } while (local_104 < DAT_00508610 + 1);
  }
  ExceptionList = local_c;
  return;
  while( true ) {
    uVar7 = uVar7 - 1;
    cVar2 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    if (cVar2 == '\0') break;
code_r0x0046b8d0:
    if (uVar7 == 0) break;
  }
  uVar7 = ~uVar7 - 1;
  cVar2 = FUN_0040b600(uVar7,1);
  if (cVar2 != '\0') {
    puVar4 = &DAT_004f5880;
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *local_c4 = *puVar4;
      puVar4 = puVar4 + 1;
      local_c4 = local_c4 + 1;
    }
    for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined1 *)local_c4 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      local_c4 = (undefined4 *)((int)local_c4 + 1);
    }
    FUN_0040b5e0(uVar7);
  }
  local_4 = 2;
  uVar5 = FUN_00463d20(local_2c,0x293);
  local_4 = CONCAT31(local_4._1_3_,3);
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar12 = s_D__work_rcsk_Code_game_Rco_Portr_004f5888;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar2 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar2 != '\0');
  uVar7 = ~uVar7 - 1;
  cVar2 = FUN_0040b600(uVar7,1);
  if (cVar2 != '\0') {
    pcVar12 = s_D__work_rcsk_Code_game_Rco_Portr_004f5888;
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)local_b4 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      local_b4 = local_b4 + 4;
    }
    for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *local_b4 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      local_b4 = local_b4 + 1;
    }
    FUN_0040b5e0(uVar7);
  }
  local_4 = CONCAT31(local_4._1_3_,4);
  FUN_0040b4f0(0);
  uVar7 = 0xffffffff;
  pcVar12 = s_HeadUp_Display_exception_in__004f58b4;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar2 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar2 != '\0');
  uVar7 = ~uVar7 - 1;
  cVar2 = FUN_0040b600(uVar7,1);
  if (cVar2 != '\0') {
    pcVar12 = s_HeadUp_Display_exception_in__004f58b4;
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)local_d4 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      local_d4 = local_d4 + 4;
    }
    for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *local_d4 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      local_d4 = local_d4 + 1;
    }
    FUN_0040b5e0(uVar7);
  }
  local_4._0_1_ = 5;
  uVar6 = FUN_00459040(local_1c,local_d8,local_b8);
  local_4._0_1_ = 6;
  uVar6 = FUN_0041b630(local_7c,uVar6,&DAT_004f5884);
  local_4._0_1_ = 7;
  uVar5 = FUN_00459040(local_4c,uVar6,uVar5);
  local_4._0_1_ = 8;
  uVar5 = FUN_00459040(local_6c,uVar5,local_c8);
  local_4._0_1_ = 9;
  uVar5 = FUN_0041b630(local_5c,uVar5,s_Unreachable_code_reached_004f5864);
  local_4._0_1_ = 10;
  uVar5 = FUN_0041b630(local_3c,uVar5,&DAT_004f5860);
  local_4 = CONCAT31(local_4._1_3_,0xb);
  FUN_00459dc0(uVar5);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_98,&DAT_004d6580);
}

