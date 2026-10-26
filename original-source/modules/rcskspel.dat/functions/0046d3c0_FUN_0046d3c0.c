/*
 * FUN_0046d3c0 at 0046d3c0
 * undefined FUN_0046d3c0(void)
 * Address ranges: 0046d3c0-0046d5c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046d3c0(int param_1)

{
  int iVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int *piVar6;
  float *pfVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  float10 fVar12;
  undefined1 local_2c [4];
  char *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d04c8;
  pvStack_c = ExceptionList;
  bVar4 = false;
  bVar3 = false;
  ExceptionList = &pvStack_c;
  if (*(float *)(param_1 + 100) == 0.0) {
    uVar8 = 0xffffffff;
    pcVar10 = s_D__work_rcsk_Code_game_Rco_Speci_004f5c28;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar5 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar5 != '\0');
    uVar8 = ~uVar8 - 1;
    local_28 = (char *)0x0;
    local_24 = 0;
    local_20 = 0;
    ExceptionList = &pvStack_c;
    cVar5 = FUN_0040b600(uVar8,1);
    if (cVar5 != '\0') {
      pcVar10 = s_D__work_rcsk_Code_game_Rco_Speci_004f5c28;
      pcVar11 = local_28;
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
      FUN_0040b5e0(uVar8);
    }
    uVar8 = 0xffffffff;
    local_4 = 0;
    pcVar10 = s_m_OverallTime____0_0f_004f5c58;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar5 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar5 != '\0');
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    FUN_0040b540(s_m_OverallTime____0_0f_004f5c58,~uVar8 - 1);
    bVar4 = true;
    bVar3 = true;
    local_4 = 1;
    FUN_00464610(local_1c,local_2c,0x200);
  }
  if (bVar3) {
    if (local_18 != 0) {
      cVar5 = *(char *)(local_18 + -1);
      if ((cVar5 == '\0') || (cVar5 == -1)) {
        FUN_004bc150((char *)(local_18 + -1));
      }
      else {
        *(char *)(local_18 + -1) = cVar5 + -1;
      }
    }
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
  }
  local_4 = 0xffffffff;
  if (bVar4) {
    if (local_28 != (char *)0x0) {
      cVar5 = local_28[-1];
      if ((cVar5 == '\0') || (cVar5 == -1)) {
        FUN_004bc150(local_28 + -1);
      }
      else {
        local_28[-1] = cVar5 + -1;
      }
    }
    local_28 = (char *)0x0;
    local_24 = 0;
    local_20 = 0;
  }
  fVar2 = *(float *)(param_1 + 0x68) / *(float *)(param_1 + 100);
  if (0.5 < fVar2) {
    piVar6 = (int *)FUN_0046c510();
    iVar1 = *piVar6;
    fVar12 = (float10)(**(code **)(iVar1 + 0x34))();
    (**(code **)(iVar1 + 0x3c))((float)(fVar12 * (float10)1.1));
    pfVar7 = (float *)(**(code **)(*piVar6 + 0x20))();
    FUN_0046d650(*pfVar7 * 1.1);
    FUN_0046d680(1.0 - (fVar2 * 1.333 - 0.333));
  }
  ExceptionList = pvStack_c;
  return;
}

