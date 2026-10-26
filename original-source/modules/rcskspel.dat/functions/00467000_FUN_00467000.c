/*
 * FUN_00467000 at 00467000
 * undefined FUN_00467000(void)
 * Address ranges: 00467000-004671e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00467000(int *param_1)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  float10 fVar10;
  undefined1 auStack_38 [12];
  undefined1 local_2c [4];
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  char *local_18;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cfa56;
  pvStack_c = ExceptionList;
  bVar3 = false;
  bVar2 = false;
  ExceptionList = &pvStack_c;
  if (param_1[2] != 1) {
    uVar6 = 0xffffffff;
    pcVar8 = s_D__work_rcsk_Code_game_Rco_Movin_004f4ab4;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar4 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar4 != '\0');
    uVar6 = ~uVar6 - 1;
    local_18 = (char *)0x0;
    local_14 = 0;
    local_10 = (void *)0x0;
    ExceptionList = &pvStack_c;
    cVar4 = FUN_0040b600(uVar6,1);
    if (cVar4 != '\0') {
      pcVar8 = s_D__work_rcsk_Code_game_Rco_Movin_004f4ab4;
      pcVar9 = local_18;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      FUN_0040b5e0(uVar6);
    }
    uVar6 = 0xffffffff;
    local_4 = 0;
    pcVar8 = s_m_State____ST_MOVING_004f4ae4;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar4 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar4 != '\0');
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    FUN_0040b540(s_m_State____ST_MOVING_004f4ae4,~uVar6 - 1);
    bVar3 = true;
    bVar2 = true;
    local_4 = 1;
    FUN_00464610(local_2c,local_1c,0x37);
  }
  if (bVar2) {
    if (local_28 != 0) {
      cVar4 = *(char *)(local_28 + -1);
      if ((cVar4 == '\0') || (cVar4 == -1)) {
        FUN_004bc150((char *)(local_28 + -1));
      }
      else {
        *(char *)(local_28 + -1) = cVar4 + -1;
      }
    }
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
  }
  local_4 = 0xffffffff;
  if ((bVar3) && (local_18 != (char *)0x0)) {
    cVar4 = local_18[-1];
    if ((cVar4 == '\0') || (cVar4 == -1)) {
      FUN_004bc150(local_18 + -1);
    }
    else {
      local_18[-1] = cVar4 + -1;
    }
  }
  fVar10 = (float10)FUN_0048f4e0();
  fVar10 = fVar10 * (float10)1000.0 + (float10)(float)param_1[9];
  param_1[9] = (int)(float)fVar10;
  if ((float10)(float)param_1[10] <= fVar10) {
    (**(code **)(*param_1 + 0x20))(param_1 + 6);
    (**(code **)(*param_1 + 0x14))();
    ExceptionList = local_10;
    return;
  }
  iVar1 = *param_1;
  uVar5 = FUN_004676d0(auStack_38,param_1[0xb],param_1 + 3,param_1 + 6,
                       (float)(fVar10 / (float10)(float)param_1[10]));
  (**(code **)(iVar1 + 0x20))(uVar5);
  ExceptionList = local_10;
  return;
}

