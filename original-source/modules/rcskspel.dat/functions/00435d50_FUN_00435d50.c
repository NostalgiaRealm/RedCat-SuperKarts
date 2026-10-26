/*
 * FUN_00435d50 at 00435d50
 * undefined FUN_00435d50(void)
 * Address ranges: 00435d50-004362d1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00435d50(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *unaff_EBX;
  float fVar6;
  undefined4 unaff_ESI;
  float fVar7;
  char *pcVar8;
  float *pfVar9;
  char *pcVar10;
  undefined1 local_9c [4];
  char *local_98;
  undefined1 auStack_94 [4];
  char *pcStack_90;
  float local_8c;
  float local_78;
  int local_74 [20];
  void *pvStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd2cf;
  pvStack_c = ExceptionList;
  piVar2 = local_74 + 1;
  iVar3 = 9;
  do {
    piVar2[-1] = 32000;
    piVar2[-2] = 0x4b18967f;
    *piVar2 = -1;
    piVar2 = piVar2 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  fVar7 = 0.0;
  local_8c = 9999999.0;
  fVar6 = -NAN;
  ExceptionList = &pvStack_c;
  if (0 < DAT_00508610) {
    pfVar9 = &local_78;
    ExceptionList = &pvStack_c;
    do {
      pfVar9[2] = fVar7;
      FUN_00435c60();
      if (*pfVar9 < local_8c) {
        local_8c = *pfVar9;
        fVar6 = fVar7;
      }
      fVar7 = (float)((int)fVar7 + 1);
      pfVar9 = pfVar9 + 3;
    } while ((int)fVar7 < DAT_00508610);
    if ((fVar6 != -NAN) && (local_8c != 9999999.0)) {
      if (local_74[(int)fVar6 * 3] < -400) {
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar8 = s_IDLE_LEFT_004ebda4;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4 - 1;
        cVar1 = FUN_0040b600(uVar4,1);
        if (cVar1 != '\0') {
          pcVar8 = s_IDLE_LEFT_004ebda4;
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined4 *)local_98 = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
            local_98 = local_98 + 4;
          }
          for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *local_98 = *pcVar8;
            pcVar8 = pcVar8 + 1;
            local_98 = local_98 + 1;
          }
          FUN_0040b5e0(uVar4);
        }
        local_4 = 0;
        piVar2 = (int *)FUN_0044a700(DAT_00508610);
        (**(code **)(*piVar2 + 0xc))(local_9c,0,3);
        uStack_10 = 0xffffffff;
        FUN_0040b4f0(1);
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar8 = (char *)&DAT_004ebdb0;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4 - 1;
        cVar1 = FUN_0040b600(uVar4,1);
        if (cVar1 != '\0') {
          pcVar8 = (char *)&DAT_004ebdb0;
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined4 *)unaff_EBX = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
            unaff_EBX = unaff_EBX + 4;
          }
          for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *unaff_EBX = *pcVar8;
            pcVar8 = pcVar8 + 1;
            unaff_EBX = unaff_EBX + 1;
          }
          FUN_0040b5e0(uVar4);
        }
        uStack_10 = 1;
        piVar2 = (int *)FUN_0044a700(DAT_00508610);
        (**(code **)(*piVar2 + 0xc))(&stack0xffffff58,3,3);
      }
      else if (local_74[(int)fVar6 * 3] < 0x191) {
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar8 = s_RIGHT_IDLE_004ebdcc;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4 - 1;
        cVar1 = FUN_0040b600(uVar4,1);
        if (cVar1 != '\0') {
          pcVar8 = s_RIGHT_IDLE_004ebdcc;
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined4 *)local_98 = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
            local_98 = local_98 + 4;
          }
          for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *local_98 = *pcVar8;
            pcVar8 = pcVar8 + 1;
            local_98 = local_98 + 1;
          }
          FUN_0040b5e0(uVar4);
        }
        local_4 = 4;
        piVar2 = (int *)FUN_0044a700(DAT_00508610);
        (**(code **)(*piVar2 + 0xc))(local_9c,4,0);
        uStack_10 = 0xffffffff;
        FUN_0040b4f0(1);
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar8 = s_LEFT_IDLE_004ebdd8;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4 - 1;
        cVar1 = FUN_0040b600(uVar4,1);
        if (cVar1 != '\0') {
          pcVar8 = s_LEFT_IDLE_004ebdd8;
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined4 *)unaff_EBX = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
            unaff_EBX = unaff_EBX + 4;
          }
          for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *unaff_EBX = *pcVar8;
            pcVar8 = pcVar8 + 1;
            unaff_EBX = unaff_EBX + 1;
          }
          FUN_0040b5e0(uVar4);
        }
        uStack_10 = 5;
        piVar2 = (int *)FUN_0044a700(DAT_00508610);
        (**(code **)(*piVar2 + 0xc))(&stack0xffffff58,3,0);
      }
      else {
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar8 = s_IDLE_RIGHT_004ebdb8;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4 - 1;
        cVar1 = FUN_0040b600(uVar4,1);
        if (cVar1 != '\0') {
          pcVar8 = s_IDLE_RIGHT_004ebdb8;
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined4 *)local_98 = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
            local_98 = local_98 + 4;
          }
          for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *local_98 = *pcVar8;
            pcVar8 = pcVar8 + 1;
            local_98 = local_98 + 1;
          }
          FUN_0040b5e0(uVar4);
        }
        local_4 = 2;
        piVar2 = (int *)FUN_0044a700(DAT_00508610);
        (**(code **)(*piVar2 + 0xc))(local_9c,0,4);
        uStack_10 = 0xffffffff;
        FUN_0040b4f0(1);
        FUN_0040b4f0(0);
        uVar4 = 0xffffffff;
        pcVar8 = s_RIGHT_004ebdc4;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4 - 1;
        cVar1 = FUN_0040b600(uVar4,1);
        if (cVar1 != '\0') {
          pcVar8 = s_RIGHT_004ebdc4;
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined4 *)unaff_EBX = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
            unaff_EBX = unaff_EBX + 4;
          }
          for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *unaff_EBX = *pcVar8;
            pcVar8 = pcVar8 + 1;
            unaff_EBX = unaff_EBX + 1;
          }
          FUN_0040b5e0(uVar4);
        }
        uStack_10 = 3;
        piVar2 = (int *)FUN_0044a700(DAT_00508610);
        (**(code **)(*piVar2 + 0xc))(&stack0xffffff58,4,4);
      }
      goto LAB_004362b4;
    }
  }
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar8 = s_RIGHT_IDLE_004ebde4;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4 - 1;
  cVar1 = FUN_0040b600(uVar4,1);
  if (cVar1 != '\0') {
    pcVar8 = s_RIGHT_IDLE_004ebde4;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)local_98 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      local_98 = local_98 + 4;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *local_98 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      local_98 = local_98 + 1;
    }
    FUN_0040b5e0(uVar4);
  }
  local_4 = 6;
  piVar2 = (int *)FUN_0044a700(DAT_00508610);
  (**(code **)(*piVar2 + 0xc))(local_9c,4,0);
  uStack_10 = 0xffffffff;
  FUN_0040b4f0(1);
  auStack_94[0] = (char)((uint)unaff_ESI >> 0x18);
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar8 = s_LEFT_IDLE_004ebdf0;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  fVar6 = (float)(~uVar4 - 1);
  cVar1 = FUN_0040b600(fVar6,1);
  if (cVar1 != '\0') {
    pcVar8 = s_LEFT_IDLE_004ebdf0;
    pcVar10 = pcStack_90;
    for (uVar4 = (uint)fVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar4 = (uint)fVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar10 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar10 = pcVar10 + 1;
    }
    pcStack_90[(int)fVar6] = '\0';
    local_8c = fVar6;
  }
  uStack_10 = 7;
  piVar2 = (int *)FUN_0044a700(DAT_00508610);
  (**(code **)(*piVar2 + 0xc))(auStack_94,3,0);
LAB_004362b4:
  uStack_1c = 0xffffffff;
  FUN_0040b4f0(1);
  ExceptionList = pvStack_24;
  return;
}

