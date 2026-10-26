/*
 * FUN_004a8a40 at 004a8a40
 * undefined FUN_004a8a40(void)
 * Address ranges: 004a8a40-004a9002
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004a8a40(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  short *psVar9;
  void *pvVar10;
  int iVar11;
  int iVar12;
  float *pfVar13;
  uint uVar14;
  uint uVar15;
  float *pfVar16;
  undefined2 *puVar17;
  undefined1 uVar18;
  int iVar19;
  int *piVar20;
  undefined4 *puVar21;
  int iVar22;
  int local_f8;
  int local_f4;
  int local_f0;
  float local_ec [8];
  void *pvStack_cc;
  int iStack_c8;
  int iStack_c4;
  float local_c0 [16];
  float local_80 [16];
  float local_40 [16];
  
  iVar6 = DAT_004fe930 / 2;
  pfVar8 = (float *)&DAT_006a61dc;
  pfVar16 = local_40;
  for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
    *pfVar16 = *pfVar8;
    pfVar8 = pfVar8 + 1;
    pfVar16 = pfVar16 + 1;
  }
  iVar11 = DAT_004fe934 / 2;
  pfVar8 = (float *)&DAT_006a619c;
  pfVar16 = local_80;
  for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
    *pfVar16 = *pfVar8;
    pfVar8 = pfVar8 + 1;
    pfVar16 = pfVar16 + 1;
  }
  pfVar8 = (float *)&DAT_006a5cd8;
  pfVar16 = local_c0;
  for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
    *pfVar16 = *pfVar8;
    pfVar8 = pfVar8 + 1;
    pfVar16 = pfVar16 + 1;
  }
  iVar12 = 0;
  do {
    pfVar16 = local_80;
    pfVar8 = (float *)((int)local_c0 + iVar12);
    local_f8 = 4;
    do {
      fVar1 = *pfVar8;
      pfVar13 = (float *)((int)local_40 + iVar12);
      iVar19 = 4;
      pfVar7 = pfVar16;
      do {
        fVar2 = *pfVar13;
        fVar3 = *pfVar7;
        pfVar7 = pfVar7 + 4;
        pfVar13 = pfVar13 + 1;
        iVar19 = iVar19 + -1;
        fVar1 = fVar2 * fVar3 + fVar1;
      } while (iVar19 != 0);
      *pfVar8 = fVar1;
      pfVar8 = pfVar8 + 1;
      pfVar16 = pfVar16 + 1;
      local_f8 = local_f8 + -1;
    } while (local_f8 != 0);
    iVar12 = iVar12 + 0x10;
  } while (iVar12 < 0x40);
  pfVar8 = local_c0;
  pfVar16 = local_c0;
  for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
    *pfVar16 = *pfVar8;
    pfVar8 = pfVar8 + 1;
    pfVar16 = pfVar16 + 1;
  }
  pfVar8 = (float *)&DAT_006a615c;
  pfVar16 = local_40;
  for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
    *pfVar16 = *pfVar8;
    pfVar8 = pfVar8 + 1;
    pfVar16 = pfVar16 + 1;
  }
  pfVar8 = (float *)&DAT_006a5cd8;
  pfVar16 = local_80;
  for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
    *pfVar16 = *pfVar8;
    pfVar8 = pfVar8 + 1;
    pfVar16 = pfVar16 + 1;
  }
  iVar12 = 0;
  do {
    pfVar16 = local_40;
    pfVar8 = (float *)((int)local_80 + iVar12);
    local_f8 = 4;
    do {
      fVar1 = *pfVar8;
      pfVar13 = (float *)((int)local_c0 + iVar12);
      iVar19 = 4;
      pfVar7 = pfVar16;
      do {
        fVar2 = *pfVar13;
        fVar3 = *pfVar7;
        pfVar7 = pfVar7 + 4;
        pfVar13 = pfVar13 + 1;
        iVar19 = iVar19 + -1;
        fVar1 = fVar2 * fVar3 + fVar1;
      } while (iVar19 != 0);
      *pfVar8 = fVar1;
      pfVar8 = pfVar8 + 1;
      pfVar16 = pfVar16 + 1;
      local_f8 = local_f8 + -1;
    } while (local_f8 != 0);
    iVar12 = iVar12 + 0x10;
  } while (iVar12 < 0x40);
  pfVar8 = local_80;
  pfVar16 = local_c0;
  for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
    *pfVar16 = *pfVar8;
    pfVar8 = pfVar8 + 1;
    pfVar16 = pfVar16 + 1;
  }
  uVar15 = param_1[0x23];
  iVar12 = 0;
  puVar21 = (undefined4 *)param_1[0x24];
  for (uVar14 = uVar15 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
    *puVar21 = 0;
    puVar21 = puVar21 + 1;
  }
  local_f8 = 0;
  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
    *(undefined1 *)puVar21 = 0;
    puVar21 = (undefined4 *)((int)puVar21 + 1);
  }
  uVar15 = param_1[0x23];
  puVar21 = (undefined4 *)param_1[0x25];
  for (uVar14 = uVar15 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
    *puVar21 = 0;
    puVar21 = puVar21 + 1;
  }
  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
    *(undefined1 *)puVar21 = 0;
    puVar21 = (undefined4 *)((int)puVar21 + 1);
  }
  if (0 < param_1[0x23]) {
    do {
      uVar18 = 1;
      if (*param_1 == 2) {
        iVar19 = param_1[0x20];
      }
      else {
        iVar19 = param_1[0x1e];
      }
      pfVar8 = (float *)(iVar19 + iVar12);
      local_ec[3] = 1.0;
      local_ec[0] = *pfVar8;
      local_ec[1] = pfVar8[1];
      local_ec[2] = pfVar8[2];
      local_ec[4] = 0.0;
      local_ec[5] = 0.0;
      local_ec[6] = 0.0;
      local_ec[7] = 1.0;
      iVar19 = 0;
      do {
        fVar1 = 0.0;
        pfVar16 = local_ec;
        pfVar8 = (float *)((int)local_c0 + iVar19);
        iVar22 = 4;
        do {
          fVar2 = *pfVar16;
          fVar3 = *pfVar8;
          pfVar8 = pfVar8 + 4;
          pfVar16 = pfVar16 + 1;
          iVar22 = iVar22 + -1;
          fVar1 = fVar2 * fVar3 + fVar1;
        } while (iVar22 != 0);
        *(float *)((int)local_ec + iVar19 + 0x10) = fVar1;
        iVar19 = iVar19 + 4;
      } while (iVar19 < 0x10);
      fVar2 = (float)iVar6 / local_ec[7];
      local_ec[0] = local_ec[4];
      local_ec[2] = local_ec[6];
      local_ec[1] = local_ec[5];
      local_ec[3] = local_ec[7];
      *(float *)(iVar12 + param_1[0x22]) = local_ec[4] * fVar2 + (float)iVar6;
      fVar1 = *(float *)(iVar12 + param_1[0x22]);
      if ((fVar1 < 0.0) || ((float)DAT_004fe930 < fVar1)) {
        uVar18 = 0;
      }
      *(float *)(iVar12 + param_1[0x22] + 4) = local_ec[5] * fVar2 + (float)iVar11;
      fVar1 = *(float *)(iVar12 + 4 + param_1[0x22]);
      *(float *)(iVar12 + param_1[0x22] + 8) = local_ec[6];
      if ((fVar1 < 0.0) || ((float)DAT_004fe934 < fVar1)) {
        uVar18 = 0;
      }
      if (local_ec[7] < 1.0) {
        uVar18 = 0;
        fVar1 = local_ec[7];
        if (0.0 <= local_ec[7]) {
          fVar1 = 1.0;
        }
        if ((-1.0 <= fVar1) && (fVar1 < 0.0)) {
          local_ec[3] = -1.0;
        }
      }
      *(float *)(iVar12 + 0xc + param_1[0x22]) = fVar2;
      if (*param_1 == 2) {
        *(undefined4 *)(iVar12 + 0x10 + param_1[0x22]) =
             *(undefined4 *)(param_1[0x20] + 0x10 + iVar12);
        *(undefined4 *)(iVar12 + 0x14 + param_1[0x22]) =
             *(undefined4 *)(param_1[0x20] + 0x14 + iVar12);
        *(undefined4 *)(iVar12 + 0x18 + param_1[0x22]) =
             *(undefined4 *)(param_1[0x20] + 0x18 + iVar12);
        iVar19 = param_1[0x20];
      }
      else {
        *(undefined4 *)(iVar12 + 0x10 + param_1[0x22]) = 0xffffff;
        *(undefined4 *)(iVar12 + 0x14 + param_1[0x22]) = 0xff000000;
        *(undefined4 *)(iVar12 + 0x18 + param_1[0x22]) =
             *(undefined4 *)(param_1[0x1e] + 0x18 + iVar12);
        iVar19 = param_1[0x1e];
      }
      *(undefined4 *)(iVar12 + 0x1c + param_1[0x22]) = *(undefined4 *)(iVar19 + 0x1c + iVar12);
      iVar12 = iVar12 + 0x20;
      *(undefined1 *)(param_1[0x24] + local_f8) = uVar18;
      local_f8 = local_f8 + 1;
    } while (local_f8 < param_1[0x23]);
  }
  local_f4 = param_1[0x27] / 3;
  if (local_f4 * 3 != param_1[0x27]) {
    FUN_004afee0(s__s__d____illegal_index_count_004fd27c);
  }
  if (DAT_006a625c == 0) {
    local_f8 = 0;
    pvVar10 = operator_new(local_f4 * 0x10);
    iVar6 = 0;
    if (0 < local_f4) {
      local_f0 = 0;
      piVar20 = (int *)((int)pvVar10 + 8);
      do {
        iVar6 = param_1[0x24];
        iStack_c8 = (int)*(short *)(local_f0 + 2 + param_1[0x26]);
        psVar9 = (short *)(local_f0 + param_1[0x26]);
        iStack_c4 = (int)*psVar9;
        iVar11 = (int)psVar9[2];
        if ((uint)*(byte *)(iVar6 + iVar11) + (uint)*(byte *)(iVar6 + iStack_c8) +
            (uint)*(byte *)(iVar6 + iStack_c4) != 0) {
          piVar20[-2] = iStack_c4;
          piVar20[-1] = iStack_c8;
          *piVar20 = iVar11;
          local_f8 = local_f8 + 1;
          piVar20[1] = *(int *)(iVar11 * 0x20 + 8 + param_1[0x22]);
          piVar20 = piVar20 + 4;
        }
        local_f0 = local_f0 + 6;
        local_f4 = local_f4 + -1;
        iVar6 = local_f8;
      } while (local_f4 != 0);
    }
    pvStack_cc = pvVar10;
    FUN_004bf5b9(pvVar10,iVar6,0x10,FUN_004a89f0);
    iVar11 = 0;
    if (0 < iVar6) {
      puVar17 = (undefined2 *)((int)pvVar10 + 8);
      do {
        *(undefined2 *)(param_1[0x28] + iVar11 * 2) = puVar17[-4];
        *(undefined2 *)(param_1[0x28] + (iVar11 + 1) * 2) = puVar17[-2];
        *(undefined2 *)(param_1[0x28] + (iVar11 + 2) * 2) = *puVar17;
        iVar11 = iVar11 + 3;
        iVar6 = iVar6 + -1;
        puVar17 = puVar17 + 8;
      } while (iVar6 != 0);
    }
    param_1[0x29] = iVar11;
    FUN_004bc150(pvVar10);
    return;
  }
  iVar6 = 0;
  if (0 < local_f4) {
    local_f8 = 0;
    local_f0 = local_f4;
    do {
      psVar9 = (short *)(local_f8 + param_1[0x26]);
      sVar4 = psVar9[2];
      sVar5 = psVar9[1];
      iVar11 = param_1[0x24];
      if ((uint)*(byte *)(iVar11 + sVar4) + (uint)*(byte *)(iVar11 + sVar5) +
          (uint)*(byte *)(iVar11 + *psVar9) != 0) {
        *(short *)(param_1[0x28] + -2 + (iVar6 + 1) * 2) = *psVar9;
        *(short *)(param_1[0x28] + (iVar6 + 1) * 2) = sVar5;
        *(short *)(param_1[0x28] + (iVar6 + 2) * 2) = sVar4;
        iVar6 = iVar6 + 3;
      }
      local_f8 = local_f8 + 6;
      local_f0 = local_f0 + -1;
    } while (local_f0 != 0);
  }
  param_1[0x29] = iVar6;
  return;
}

