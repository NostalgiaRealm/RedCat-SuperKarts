/*
 * FUN_0040c370 at 0040c370
 * undefined FUN_0040c370(void)
 * Address ranges: 0040c370-0040c78a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040c370(int param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *unaff_EBP;
  char *pcVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined1 auStack_28 [4];
  char *pcStack_24;
  undefined4 local_1c;
  char *local_18;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cccc0;
  pvStack_c = ExceptionList;
  if ((param_2 < -999) || (999 < param_2)) {
    if (-1 < param_2) {
      ExceptionList = &pvStack_c;
      FUN_0040f350(param_1);
      local_1c = CONCAT31(local_1c._1_3_,(undefined1)param_1);
      FUN_0040b4f0(0);
      uVar3 = 0xffffffff;
      pcVar5 = s_IDLE_LEFT_004deed8;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3 - 1;
      cVar1 = FUN_0040b600(uVar3,1);
      if (cVar1 != '\0') {
        pcVar5 = s_IDLE_LEFT_004deed8;
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined4 *)local_18 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          local_18 = local_18 + 4;
        }
        for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *local_18 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          local_18 = local_18 + 1;
        }
        FUN_0040b5e0(uVar3);
      }
      local_4 = 4;
      piVar2 = (int *)FUN_0044a700(param_1);
      iVar9 = 3;
      (**(code **)(*piVar2 + 0xc))(&local_1c,0);
      uStack_10 = 0xffffffff;
      FUN_0040b4f0(1);
      FUN_0040b4f0(0);
      uVar3 = 0xffffffff;
      pcVar5 = (char *)&DAT_004deed0;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3 - 1;
      cVar1 = FUN_0040b600(uVar3,1);
      if (cVar1 != '\0') {
        puVar6 = &DAT_004deed0;
        puVar8 = unaff_EBP;
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar8 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
        }
        for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        *(undefined1 *)((int)unaff_EBP + uVar3) = 0;
      }
      uStack_10 = 5;
      piVar2 = (int *)FUN_0044a700(param_1);
      (**(code **)(*piVar2 + 0xc))(&stack0xffffffc8,3,3);
      if (iVar9 != 0) {
        cVar1 = *(char *)(iVar9 + -1);
        if ((cVar1 != '\0') && (cVar1 != -1)) {
          *(char *)(iVar9 + -1) = cVar1 + -1;
          ExceptionList = pcStack_24;
          return;
        }
        FUN_004bc150((char *)(iVar9 + -1));
      }
      ExceptionList = pcStack_24;
      return;
    }
    ExceptionList = &pvStack_c;
    FUN_0040f320();
    local_1c = CONCAT31(local_1c._1_3_,(undefined1)param_1);
    FUN_0040b4f0(0);
    uVar3 = 0xffffffff;
    pcVar5 = s_IDLE_RIGHT_004deeec;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      pcVar5 = s_IDLE_RIGHT_004deeec;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)local_18 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        local_18 = local_18 + 4;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *local_18 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        local_18 = local_18 + 1;
      }
      FUN_0040b5e0(uVar3);
    }
    local_4 = 2;
    piVar2 = (int *)FUN_0044a700(param_1);
    (**(code **)(*piVar2 + 0xc))(&local_1c,0,4);
    uStack_10 = 0xffffffff;
    FUN_0040b4f0(1);
    auStack_28[0] = puStack_8._0_1_;
    FUN_0040b4f0(0);
    uVar3 = 0xffffffff;
    pcVar5 = s_RIGHT_004deee4;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      pcVar5 = s_RIGHT_004deee4;
      pcVar7 = pcStack_24;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar7 = pcVar7 + 1;
      }
      FUN_0040b5e0(uVar3);
    }
    uStack_10 = 3;
    piVar2 = (int *)FUN_0044a700(param_1);
    (**(code **)(*piVar2 + 0xc))(auStack_28,4,4);
    local_1c = 0xffffffff;
    FUN_0040b4f0(1);
    ExceptionList = pcStack_24;
    return;
  }
  local_1c = CONCAT31(local_1c._1_3_,(undefined1)param_1);
  ExceptionList = &pvStack_c;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_RIGHT_IDLE_004def04;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_RIGHT_IDLE_004def04;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)local_18 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      local_18 = local_18 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *local_18 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      local_18 = local_18 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  local_4 = 0;
  piVar2 = (int *)FUN_0044a700(param_1);
  (**(code **)(*piVar2 + 0xc))(&local_1c,4,0);
  uStack_10 = 0xffffffff;
  FUN_0040b4f0(1);
  auStack_28[0] = puStack_8._0_1_;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar5 = s_LEFT_IDLE_004deef8;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar5 = s_LEFT_IDLE_004deef8;
    pcVar7 = pcStack_24;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
    FUN_0040b5e0(uVar3);
  }
  uStack_10 = 1;
  piVar2 = (int *)FUN_0044a700(param_1);
  (**(code **)(*piVar2 + 0xc))(auStack_28,3,0);
  local_1c = 0xffffffff;
  FUN_0040b4f0(1);
  FUN_0040f380(param_1);
  *(undefined4 *)(&DAT_00503f34 + param_1 * 0x11c) = 1;
  ExceptionList = pcStack_24;
  return;
}

