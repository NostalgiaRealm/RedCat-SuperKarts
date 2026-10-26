/*
 * FUN_0046b2a0 at 0046b2a0
 * undefined FUN_0046b2a0(void)
 * Address ranges: 0046b2a0-0046b5dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0046b2a0(int param_1,int param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  void *pvVar6;
  undefined4 uVar7;
  int iVar8;
  float *pfVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  undefined1 local_2c [4];
  char *local_28;
  uint uStack_24;
  undefined1 local_1c [4];
  char *local_18;
  uint uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d01e8;
  pvStack_c = ExceptionList;
  bVar4 = false;
  bVar3 = false;
  ExceptionList = &pvStack_c;
  if (DAT_00508610 + 1 <= param_2) {
    local_2c[0] = (undefined1)param_2;
    ExceptionList = &pvStack_c;
    FUN_0040b4f0(0);
    uVar10 = 0xffffffff;
    pcVar12 = s_D__work_rcsk_Code_game_Rco_Portr_004f5784;
    do {
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      cVar5 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar5 != '\0');
    uVar10 = ~uVar10 - 1;
    cVar5 = FUN_0040b600(uVar10,1);
    if (cVar5 != '\0') {
      pcVar12 = s_D__work_rcsk_Code_game_Rco_Portr_004f5784;
      pcVar13 = local_28;
      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar11 = uVar10 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *pcVar13 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar13 = pcVar13 + 1;
      }
      FUN_0040b5e0(uVar10);
    }
    local_4 = 0;
    local_1c[0] = (undefined1)param_2;
    FUN_0040b4f0(0);
    uVar10 = 0xffffffff;
    pcVar12 = s_a_Racer_<_g_NumberOfOpponents___1_004f57b0;
    do {
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      cVar5 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar5 != '\0');
    uVar10 = ~uVar10 - 1;
    cVar5 = FUN_0040b600(uVar10,1);
    if (cVar5 != '\0') {
      pcVar12 = s_a_Racer_<_g_NumberOfOpponents___1_004f57b0;
      pcVar13 = local_18;
      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar11 = uVar10 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *pcVar13 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar13 = pcVar13 + 1;
      }
      FUN_0040b5e0(uVar10);
    }
    bVar4 = true;
    bVar3 = true;
    local_4 = 1;
    FUN_00464610(local_1c,local_2c,0x23d);
  }
  local_4 = 0;
  if (bVar3) {
    FUN_0040b4f0(1);
  }
  local_4 = 0xffffffff;
  if (bVar4) {
    FUN_0040b4f0(1);
  }
  pvVar6 = operator_new(0x50);
  local_4 = 2;
  if (pvVar6 == (void *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar7 = FUN_00469990(*(undefined4 *)(param_1 + 4),param_3);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 8 + param_2 * 4) = uVar7;
  local_1c[0] = (undefined1)param_2;
  FUN_0040b4f0(0);
  uVar10 = 0xffffffff;
  pcVar12 = s_D__work_rcsk_Code_game_Rco_Portr_004f57d4;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar5 != '\0');
  uVar10 = ~uVar10 - 1;
  cVar5 = FUN_0040b600(uVar10,1);
  if (cVar5 != '\0') {
    pcVar12 = s_D__work_rcsk_Code_game_Rco_Portr_004f57d4;
    pcVar13 = local_18;
    for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar13 = pcVar13 + 4;
    }
    for (uVar11 = uVar10 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      *pcVar13 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar13 = pcVar13 + 1;
    }
    local_18[uVar10] = '\0';
    uStack_14 = uVar10;
  }
  local_2c[0] = (undefined1)param_2;
  local_4 = 3;
  FUN_0040b4f0(0);
  uVar10 = 0xffffffff;
  pcVar12 = s_Unable_to_create_new_portrait_004f5800;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar5 != '\0');
  uVar10 = ~uVar10 - 1;
  cVar5 = FUN_0040b600(uVar10,1);
  if (cVar5 != '\0') {
    pcVar12 = s_Unable_to_create_new_portrait_004f5800;
    pcVar13 = local_28;
    for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar13 = pcVar13 + 4;
    }
    for (uVar11 = uVar10 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      *pcVar13 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar13 = pcVar13 + 1;
    }
    local_28[uVar10] = '\0';
    uStack_24 = uVar10;
  }
  local_4._0_1_ = 4;
  FUN_00464530(*(undefined4 *)(param_1 + 8 + param_2 * 4),local_2c,local_1c,0x241);
  local_4 = CONCAT31(local_4._1_3_,3);
  FUN_0040b4f0(1);
  local_4 = 0xffffffff;
  if (local_18 != (char *)0x0) {
    cVar5 = local_18[-1];
    if ((cVar5 == '\0') || (cVar5 == -1)) {
      FUN_004bc150(local_18 + -1);
    }
    else {
      local_18[-1] = cVar5 + -1;
    }
  }
  (**(code **)(**(int **)(param_1 + 8 + param_2 * 4) + 4))();
  if (param_2 == *(int *)(param_1 + 0x84)) {
    iVar8 = FUN_0046a2c0();
    fVar1 = _DAT_00544b20 * *(float *)(iVar8 + 8);
    iVar8 = FUN_0046a2c0();
    fVar2 = _DAT_00544b1c * *(float *)(iVar8 + 4);
    pfVar9 = (float *)FUN_0046a2c0();
    fStack_38 = _DAT_00544b18 * *pfVar9;
    fStack_34 = fVar2;
    fStack_30 = fVar1;
    FUN_0046a290(&fStack_38);
  }
  FUN_0046a2e0(1);
  ExceptionList = pvStack_c;
  return;
}

