/*
 * FUN_0046cc70 at 0046cc70
 * undefined FUN_0046cc70(void)
 * Address ranges: 0046cc70-0046cfa4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046cc70(int param_1)

{
  undefined4 *puVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  undefined4 uVar12;
  undefined1 uStack_31;
  undefined1 auStack_2c [4];
  char *pcStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  int local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d043f;
  local_c = ExceptionList;
  bVar4 = false;
  bVar3 = false;
  if (*(int *)(param_1 + 8) != 1) {
    return;
  }
  ExceptionList = &local_c;
  FUN_00467370();
  if (*(int *)(param_1 + 0x60) == 0) {
    uVar12 = 0;
    FUN_0046c510(0);
    FUN_00458460(uVar12);
    ExceptionList = local_c;
    return;
  }
  puVar1 = (undefined4 *)(param_1 + 0x38);
  local_1c = *puVar1;
  local_18 = *(undefined4 *)(param_1 + 0x3c);
  uVar12 = *(undefined4 *)(param_1 + 0x40);
  local_10 = *(undefined4 *)(param_1 + 0x44);
  piVar6 = (int *)FUN_0046c510();
  (**(code **)(*piVar6 + 0x50))(uVar12);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x10);
  local_1c = *puVar1;
  local_18 = *(int *)(param_1 + 0x3c);
  fVar2 = (float)*(int *)(*(int *)(param_1 + 0x40) + 0x14);
  local_10 = *(undefined4 *)(param_1 + 0x44);
  *(float *)(param_1 + 100) = fVar2;
  if (0.1 <= fVar2) {
    local_1c = *puVar1;
    local_18 = *(int *)(param_1 + 0x3c);
    local_10 = *(undefined4 *)(param_1 + 0x44);
    if (fVar2 <= (float)*(int *)(*(int *)(param_1 + 0x40) + 0x18)) {
      uVar8 = 0xffffffff;
      pcVar10 = s_D__work_rcsk_Code_game_Rco_Speci_004f5b60;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar5 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      local_18 = 0;
      uVar9 = (uint)local_1c >> 8;
      local_1c = CONCAT31((int3)uVar9,uStack_31);
      uStack_14 = 0;
      local_10 = 0;
      FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Speci_004f5b60,~uVar8 - 1);
      uStack_4 = 0;
      FUN_0040b4f0(0);
      uVar8 = 0xffffffff;
      pcVar10 = s_m_OverallTime_<_0_1f____m_Waitin_004f5b90;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar5 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      uVar8 = ~uVar8 - 1;
      cVar5 = FUN_0040b600(uVar8,1);
      if (cVar5 != '\0') {
        pcVar10 = s_m_OverallTime_<_0_1f____m_Waitin_004f5b90;
        pcVar11 = pcStack_28;
        for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar9 = uVar8 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pcVar11 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar11 = pcVar11 + 1;
        }
        pcStack_28[uVar8] = '\0';
        uStack_24 = uVar8;
      }
      bVar4 = true;
      bVar3 = true;
      uStack_4 = 1;
      FUN_00464610(auStack_2c,&local_1c,0x161);
    }
  }
  if (bVar3) {
    if (pcStack_28 != (char *)0x0) {
      cVar5 = pcStack_28[-1];
      if ((cVar5 != '\0') && (cVar5 != -1)) {
        pcStack_28[-1] = cVar5 + -1;
        pcStack_28 = (char *)0x0;
        uStack_24 = 0;
        uStack_20 = 0;
        goto LAB_0046ce62;
      }
      FUN_004bc150(pcStack_28 + -1);
    }
    pcStack_28 = (char *)0x0;
    uStack_24 = 0;
    uStack_20 = 0;
  }
LAB_0046ce62:
  uStack_4 = 0xffffffff;
  if ((bVar4) && (local_18 != 0)) {
    cVar5 = *(char *)(local_18 + -1);
    if ((cVar5 == '\0') || (cVar5 == -1)) {
      FUN_004bc150((char *)(local_18 + -1));
    }
    else {
      *(char *)(local_18 + -1) = cVar5 + -1;
    }
  }
  local_1c = *(undefined4 *)(param_1 + 0x38);
  local_18 = *(undefined4 *)(param_1 + 0x3c);
  local_10 = *(undefined4 *)(param_1 + 0x44);
  FUN_0046c890((float)*(int *)(*(int *)(param_1 + 0x40) + 0x18));
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 0x1c;
  FUN_0040b4f0(1);
  iVar7 = *(int *)(param_1 + 0x60) + -1;
  *(int *)(param_1 + 0x60) = iVar7;
  if ((iVar7 != 0) && (*(int *)(param_1 + 0x40) != *(int *)(param_1 + 0x3c))) {
    ExceptionList = local_c;
    return;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x44);
  *(undefined4 **)(param_1 + 0x44) = puVar1 + 1;
  FUN_004bc150(*puVar1);
  if (*(int *)(param_1 + 0x60) == 0) {
    FUN_0043a8f0();
    *(undefined4 *)(param_1 + 0x38) = local_1c;
    *(int *)(param_1 + 0x3c) = local_18;
    *(undefined4 *)(param_1 + 0x40) = uStack_14;
    *(undefined4 *)(param_1 + 0x44) = local_10;
    *(undefined4 *)(param_1 + 0x48) = local_1c;
    *(int *)(param_1 + 0x4c) = local_18;
    *(undefined4 *)(param_1 + 0x50) = uStack_14;
    *(undefined4 *)(param_1 + 0x54) = local_10;
    FUN_004bc150(*(undefined4 *)(param_1 + 0x58));
    ExceptionList = local_c;
    return;
  }
  iVar7 = **(int **)(param_1 + 0x44);
  *(int *)(param_1 + 0x38) = iVar7;
  *(int *)(param_1 + 0x3c) = iVar7 + 0xff8;
  *(int *)(param_1 + 0x40) = iVar7;
  *(int **)(param_1 + 0x44) = *(int **)(param_1 + 0x44);
  ExceptionList = local_c;
  return;
}

