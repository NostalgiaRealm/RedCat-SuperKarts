/*
 * FUN_00486ea0 at 00486ea0
 * undefined FUN_00486ea0(void)
 * Address ranges: 00486ea0-0048773f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00486ea0(int param_1)

{
  float fVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  float fVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined *puVar14;
  char *pcVar15;
  float10 fVar16;
  float10 fVar17;
  undefined1 *puVar18;
  undefined1 uStack_61d;
  undefined4 *local_61c;
  float local_618;
  char *local_614;
  float local_610;
  uint uStack_60c;
  int local_608;
  undefined1 auStack_604 [4];
  char *pcStack_600;
  uint uStack_5fc;
  uint uStack_5f8;
  float local_5f4;
  undefined4 local_5f0;
  float local_5ec;
  undefined4 local_5e8;
  undefined4 local_5e4;
  undefined4 local_5e0;
  undefined4 local_5dc;
  undefined4 local_5d8;
  float local_5d4;
  undefined4 local_5d0;
  undefined1 local_5cc [64];
  undefined4 local_58c [16];
  undefined4 local_54c [16];
  undefined4 local_50c [16];
  undefined4 local_4cc [16];
  undefined4 local_48c [16];
  undefined4 local_44c [16];
  undefined4 local_40c [16];
  undefined4 local_3cc [16];
  undefined4 local_38c [16];
  undefined4 local_34c [16];
  undefined4 local_30c [16];
  undefined4 local_2cc [16];
  undefined4 local_28c [16];
  undefined4 local_24c [16];
  undefined4 local_20c [16];
  undefined1 local_1cc [64];
  undefined1 local_18c [64];
  undefined1 local_14c [64];
  undefined1 local_10c [64];
  undefined1 local_cc [64];
  undefined1 local_8c [64];
  undefined1 local_4c [64];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d14b1;
  pvStack_c = ExceptionList;
  puVar3 = (undefined4 *)
           (DAT_006a5c38 + *(int *)(*(int *)(param_1 + 0x720) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 +
           0x10);
  puVar13 = local_54c;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar13 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar13 = puVar13 + 1;
  }
  ExceptionList = &pvStack_c;
  fVar16 = (float10)FUN_0048f4e0();
  iVar6 = *(int *)(param_1 + 0x770);
  fVar17 = ((float10)60.0 / ((float10)1.0 / fVar16)) * (float10)(byte)((-(iVar6 != 8) & 10U) + 0x23)
  ;
  fVar16 = fVar17 + (float10)*(float *)(param_1 + 0x778);
  *(float *)(param_1 + 0x778) = (float)fVar16;
  if ((float10)4096.0 < fVar16) {
    *(float *)(param_1 + 0x778) = (float)(fVar16 - (float10)4096.0);
  }
  fVar17 = fVar17 + (float10)*(float *)(param_1 + 0x774);
  *(float *)(param_1 + 0x774) = (float)fVar17;
  if ((float10)4096.0 < fVar17) {
    *(float *)(param_1 + 0x774) = (float)(fVar17 - (float10)4096.0);
  }
  local_618 = 0.0;
  local_614 = (char *)0x0;
  local_610 = 0.0;
  local_5f0 = 0;
  local_5ec = *(float *)(param_1 + 0x76c);
  local_5e8 = 0;
  if ((iVar6 < 8) && (512.0 < *(float *)(param_1 + 0x774))) {
    *(int *)(param_1 + 0x770) = iVar6 + 1;
    *(float *)(param_1 + 0x774) = *(float *)(param_1 + 0x774) - 512.0;
  }
  puVar3 = (undefined4 *)
           FUN_004a2510(local_5cc,*(undefined4 *)(param_1 + 0x74c),*(undefined4 *)(param_1 + 0x74c),
                        0x3f800000);
  puVar13 = local_50c;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar13 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar13 = puVar13 + 1;
  }
  puVar3 = (undefined4 *)FUN_004a24c0(local_5cc,param_1 + 0x728);
  puVar13 = local_58c;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar13 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar13 = puVar13 + 1;
  }
  puVar3 = (undefined4 *)FUN_004a24c0(local_5cc,&local_5f0);
  puVar13 = local_40c;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar13 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar13 = puVar13 + 1;
  }
  puVar3 = (undefined4 *)FUN_004a2560(local_5cc,local_50c,local_40c);
  local_5d4 = local_5ec + 0.5;
  puVar13 = local_4cc;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar13 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar13 = puVar13 + 1;
  }
  local_5d8 = local_5f0;
  local_5d0 = local_5e8;
  puVar3 = (undefined4 *)FUN_004a24c0(local_5cc,&local_5d8);
  puVar13 = local_3cc;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar13 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar13 = puVar13 + 1;
  }
  puVar3 = (undefined4 *)FUN_004a2560(local_5cc,local_50c,local_3cc);
  iVar6 = *(int *)(param_1 + 0x770);
  puVar13 = local_24c;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar13 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar13 = puVar13 + 1;
  }
  local_608 = 0;
  if (0 < iVar6) {
    local_61c = (undefined4 *)(param_1 + 0x308);
    do {
      local_5f4 = 4096.0 - ((float)local_608 * 512.0 + *(float *)(param_1 + 0x778));
      uVar4 = __ftol();
      puVar3 = (undefined4 *)FUN_004a22e0(local_5cc,uVar4);
      puVar13 = local_30c;
      for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar13 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar13 = puVar13 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_1cc,local_58c,local_30c);
      puVar13 = local_28c;
      for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar13 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar13 = puVar13 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_8c,local_28c,local_4cc);
      puVar13 = local_38c;
      for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar13 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar13 = puVar13 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_10c,local_54c,local_38c);
      puVar13 = local_48c;
      for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar13 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar13 = puVar13 + 1;
      }
      uVar4 = __ftol();
      puVar3 = (undefined4 *)FUN_004a22e0(local_18c,uVar4);
      puVar13 = local_20c;
      for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar13 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar13 = puVar13 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_14c,local_58c,local_20c);
      puVar13 = local_2cc;
      for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar13 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar13 = puVar13 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_cc,local_2cc,local_24c);
      puVar13 = local_34c;
      for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar13 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar13 = puVar13 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_4c,local_54c,local_34c);
      iVar6 = *(int *)(param_1 + 0x734);
      iVar12 = 0;
      puVar13 = local_44c;
      for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar13 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar13 = puVar13 + 1;
      }
      if (0 < iVar6) {
        puVar14 = &DAT_005450d0;
        puVar3 = local_61c;
        do {
          FUN_004a19e0(&local_5e4,puVar14,local_48c);
          puVar3[-2] = local_5e4;
          puVar3[-1] = local_5e0;
          *puVar3 = local_5dc;
          FUN_004a19e0(&local_5e4,puVar14,local_44c);
          puVar3[-0xc2] = local_5e4;
          puVar3[-0xc1] = local_5e0;
          puVar3[-0xc0] = local_5dc;
          iVar12 = iVar12 + 1;
          puVar3 = puVar3 + 8;
          puVar14 = puVar14 + 0xc;
        } while (iVar12 < *(int *)(param_1 + 0x734));
      }
      local_608 = local_608 + 1;
      local_61c = local_61c + 0x18;
    } while (local_608 < *(int *)(param_1 + 0x770));
  }
  pfVar5 = (float *)FUN_0044fbf0();
  local_618 = *pfVar5;
  local_614 = (char *)pfVar5[1];
  local_610 = pfVar5[2];
  iVar6 = *(int *)(*(int *)(param_1 + 0x720) * 0xd0 + 0xc + DAT_0067ee20);
  fVar9 = *(float *)(DAT_006a5c38 + iVar6 + 0x50 + iVar6 * 0xa8) - local_618;
  fVar1 = *(float *)(DAT_006a5c38 + iVar6 + 0x58 + iVar6 * 0xa8) - local_610;
  fVar9 = (fVar9 * fVar9 + fVar1 * fVar1) / *(float *)(param_1 + 0x77c);
  *(float *)(param_1 + 0x76c) = fVar9 * 1.5;
  if (*(int *)(param_1 + 0x720) != DAT_0053be28) goto LAB_004876fb;
  fVar16 = (float10)FUN_0048f4e0();
  fVar16 = fVar16 + (float10)*(float *)(param_1 + 0x780);
  *(float *)(param_1 + 0x780) = (float)fVar16;
  if (fVar16 <= (float10)0.1) goto LAB_004876fb;
  *(float *)(param_1 + 0x780) = (float)(fVar16 - (float10)0.1);
  FUN_004371f0();
  local_608 = FUN_00437ea0(DAT_00508610);
  if (fVar9 <= 0.7) {
    if (0.4 < fVar9) {
      local_618 = (float)CONCAT31(local_618._1_3_,uStack_61d);
      uVar8 = 0xffffffff;
      local_614 = (char *)0x0;
      pcVar11 = s_ARMBEEP2_004f9db0;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar2 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar2 != '\0');
      uVar10 = ~uVar8 - 1;
      local_610 = 0.0;
      uStack_60c = 0;
      uVar8 = FUN_00412a70();
      if (uVar8 < uVar10) {
        FUN_004bc15b();
      }
      if (((local_614 == (char *)0x0) || (cVar2 = local_614[-1], cVar2 == '\0')) || (cVar2 == -1)) {
        if (uVar10 != 0) {
          if ((0x1f < uStack_60c) || (uStack_60c < uVar10)) {
            FUN_0040b4f0(1);
            goto LAB_004875a5;
          }
          goto LAB_004875b3;
        }
        FUN_0040b4f0(1);
      }
      else if (uVar10 == 0) {
        local_614[-1] = cVar2 + -1;
        FUN_0040b4f0(0);
      }
      else {
LAB_004875a5:
        FUN_0040b720(uVar10);
LAB_004875b3:
        pcVar11 = s_ARMBEEP2_004f9db0;
        pcVar15 = local_614;
        for (uVar8 = uVar10 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar11;
          pcVar11 = pcVar11 + 4;
          pcVar15 = pcVar15 + 4;
        }
        for (uVar8 = uVar10 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pcVar15 = *pcVar11;
          pcVar11 = pcVar11 + 1;
          pcVar15 = pcVar15 + 1;
        }
        FUN_0040b5e0(uVar10);
      }
      pfVar5 = &local_618;
      uStack_4 = 1;
      iVar6 = local_608;
      FUN_004371f0(local_608,pfVar5);
      FUN_00437b10(iVar6,pfVar5);
      goto LAB_004874e3;
    }
    uVar8 = 0xffffffff;
    pcVar11 = s_ARMBEEP1_004f9dbc;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar2 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar2 != '\0');
    uVar8 = ~uVar8 - 1;
    pcStack_600 = (char *)0x0;
    uStack_5fc = 0;
    uStack_5f8 = 0;
    if (((uVar8 < 0xfffffffe) || (FUN_004bc15b(), pcStack_600 == (char *)0x0)) ||
       ((cVar2 = pcStack_600[-1], cVar2 == '\0' || (cVar2 == -1)))) {
      if (uVar8 != 0) {
        if ((0x1f < uStack_5f8) || (uStack_5f8 < uVar8)) {
          FUN_0040b4f0(1);
          goto LAB_00487680;
        }
        goto LAB_0048768e;
      }
      FUN_0040b4f0(1);
    }
    else if (uVar8 == 0) {
      pcStack_600[-1] = cVar2 + -1;
      FUN_0040b4f0(0);
    }
    else {
LAB_00487680:
      FUN_0040b720(uVar8);
LAB_0048768e:
      pcVar11 = s_ARMBEEP1_004f9dbc;
      pcVar15 = pcStack_600;
      for (uVar10 = uVar8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar15 = *(undefined4 *)pcVar11;
        pcVar11 = pcVar11 + 4;
        pcVar15 = pcVar15 + 4;
      }
      for (uVar10 = uVar8 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar15 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        pcVar15 = pcVar15 + 1;
      }
      pcStack_600[uVar8] = '\0';
      uStack_5fc = uVar8;
    }
    puVar18 = auStack_604;
    uStack_4 = 2;
    iVar6 = local_608;
    FUN_004371f0(local_608,puVar18);
    FUN_00437b10(iVar6,puVar18);
    if (pcStack_600 == (char *)0x0) goto LAB_004876fb;
    pcVar11 = pcStack_600 + -1;
    cVar2 = pcStack_600[-1];
    if ((cVar2 != '\0') && (cVar2 != -1)) {
      *pcVar11 = cVar2 + -1;
      goto LAB_004876fb;
    }
  }
  else {
    local_618 = (float)CONCAT31(local_618._1_3_,uStack_61d);
    uVar8 = 0xffffffff;
    pcVar11 = (char *)&DAT_004f9da4;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar2 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar2 != '\0');
    fVar9 = (float)(~uVar8 - 1);
    local_614 = (char *)0x0;
    local_610 = 0.0;
    uStack_60c = 0;
    cVar2 = FUN_0040b600(fVar9,1);
    if (cVar2 != '\0') {
      pcVar11 = (char *)&DAT_004f9da4;
      pcVar15 = local_614;
      for (uVar8 = (uint)fVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar15 = *(undefined4 *)pcVar11;
        pcVar11 = pcVar11 + 4;
        pcVar15 = pcVar15 + 4;
      }
      for (uVar8 = (uint)fVar9 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar15 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        pcVar15 = pcVar15 + 1;
      }
      local_614[(int)fVar9] = '\0';
      local_610 = fVar9;
    }
    pfVar5 = &local_618;
    uStack_4 = 0;
    iVar6 = local_608;
    FUN_004371f0(local_608,pfVar5);
    FUN_00437b10(iVar6,pfVar5);
LAB_004874e3:
    if (local_614 == (char *)0x0) goto LAB_004876fb;
    pcVar11 = local_614 + -1;
    cVar2 = local_614[-1];
    if ((cVar2 != '\0') && (cVar2 != -1)) {
      *pcVar11 = cVar2 + -1;
      goto LAB_004876fb;
    }
  }
  FUN_004bc150(pcVar11);
LAB_004876fb:
  if (1.51 < *(float *)(param_1 + 0x76c)) {
    *(undefined1 *)(param_1 + 0x724) = 0;
    *(undefined4 *)(param_1 + 0x76c) = 0x3fc00000;
  }
  ExceptionList = pvStack_c;
  return;
}

