/*
 * FUN_0046cfb0 at 0046cfb0
 * undefined FUN_0046cfb0(void)
 * Address ranges: 0046cfb0-0046d209
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046cfb0(int param_1)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  char *local_44;
  int local_34;
  int local_24;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004d0490;
  pvStack_c = ExceptionList;
  bVar2 = false;
  bVar1 = false;
  ExceptionList = &pvStack_c;
  if (*(float *)(param_1 + 0x68) < *(float *)(param_1 + 100)) {
    ExceptionList = &pvStack_c;
    __ftol();
    FUN_0046c510();
    uVar4 = FUN_00463b10();
    FUN_0042eab0(uVar4);
    FUN_0046bbd0();
    local_4 = 0;
    if ((*(int *)(param_1 + 0x60) == 0) || (*(int *)(param_1 + 0x40) == *(int *)(param_1 + 0x38))) {
      FUN_0046d800();
    }
    iVar5 = *(int *)(param_1 + 0x40) + -0x1c;
    *(int *)(param_1 + 0x40) = iVar5;
    local_4 = CONCAT31(local_4._1_3_,1);
    if (iVar5 != 0) {
      FUN_0046db50();
    }
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
    local_4 = 0xffffffff;
    if (local_24 != 0) {
      cVar3 = *(char *)(local_24 + -1);
      if ((cVar3 == '\0') || (cVar3 == -1)) {
        FUN_004bc150();
      }
      else {
        *(char *)(local_24 + -1) = cVar3 + -1;
      }
    }
  }
  if (*(int *)(param_1 + 8) != 1) {
    iVar5 = -1;
    local_34 = 0;
    pcVar8 = s_D__work_rcsk_Code_game_Rco_Speci_004f5be0;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar3 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar3 != '\0');
    FUN_0040b540();
    local_4 = 2;
    FUN_0040b4f0();
    uVar6 = 0xffffffff;
    pcVar8 = s_m_State____ST_MOVING_004f5c10;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar3 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar3 != '\0');
    uVar6 = ~uVar6 - 1;
    cVar3 = FUN_0040b600();
    if (cVar3 != '\0') {
      pcVar8 = s_m_State____ST_MOVING_004f5c10;
      pcVar9 = local_44;
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
      local_44[uVar6] = '\0';
    }
    bVar2 = true;
    bVar1 = true;
    local_4 = 3;
    FUN_00464610();
  }
  if ((bVar1) && (local_44 != (char *)0x0)) {
    cVar3 = local_44[-1];
    if ((cVar3 == '\0') || (cVar3 == -1)) {
      FUN_004bc150();
    }
    else {
      local_44[-1] = cVar3 + -1;
    }
  }
  local_4 = 0xffffffff;
  if ((bVar2) && (local_34 != 0)) {
    cVar3 = *(char *)(local_34 + -1);
    if ((cVar3 == '\0') || (cVar3 == -1)) {
      FUN_004bc150();
    }
    else {
      *(char *)(local_34 + -1) = cVar3 + -1;
    }
  }
  FUN_00467370();
  FUN_0046c510();
  FUN_00458460();
  ExceptionList = pvStack_c;
  return;
}

