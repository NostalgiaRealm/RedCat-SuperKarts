/*
 * FUN_00494f40 at 00494f40
 * undefined FUN_00494f40(void)
 * Address ranges: 00494f40-00495ca7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_00494f40(undefined4 *param_1,float *param_2,int *param_3,float *param_4,float *param_5,
            int *param_6,int param_7,int *param_8,int param_9)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  int iVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  int iVar14;
  float *pfVar15;
  undefined4 *puVar16;
  int iVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  float *local_68;
  float *local_64;
  int local_60;
  int local_5c;
  undefined4 local_30 [4];
  undefined4 local_20 [8];
  
  local_5c = (int)param_3;
  uVar9 = FUN_00496610();
  *param_1 = uVar9;
  if (0 < (int)param_3) {
    local_68 = (float *)(param_1 + 0xc1);
    param_3 = (int *)param_2;
    local_64 = (float *)(param_1 + 99);
    do {
      puVar16 = local_30;
      param_2 = (float *)0x4;
      iVar10 = *param_3 * 0x8c;
      iVar17 = iVar10;
      do {
        puVar18 = (undefined4 *)(DAT_006a5ba0 + iVar17);
        puVar19 = local_20;
        for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar19 = *puVar18;
          puVar18 = puVar18 + 1;
          puVar19 = puVar19 + 1;
        }
        uVar9 = FUN_004968a0(local_20);
        *puVar16 = uVar9;
        iVar17 = iVar17 + 0x20;
        puVar16 = puVar16 + 1;
        param_2 = (float *)((int)param_2 + -1);
      } while (param_2 != (float *)0x0);
      param_2 = local_68;
      local_68 = local_68 + 2;
      pfVar15 = local_64 + 6;
      local_60 = 2;
      do {
        iVar17 = FUN_00496620(local_30[*(short *)(DAT_006a5ba0 + 0x80 + iVar10)],
                              local_30[*(short *)(DAT_006a5ba0 + 0x82 + iVar10)],
                              local_30[*(short *)(DAT_006a5ba0 + 0x84 + iVar10)]);
        iVar17 = iVar17 + -3;
        pfVar11 = (float *)FUN_00496870(iVar17,1);
        pfVar12 = (float *)FUN_00496870(iVar17,0);
        fVar1 = *pfVar11;
        fVar2 = *pfVar12;
        iVar14 = FUN_00496870(iVar17,1);
        iVar13 = FUN_00496870(iVar17,0);
        fVar5 = *(float *)(iVar14 + 4) - *(float *)(iVar13 + 4);
        iVar14 = FUN_00496870(iVar17,1);
        iVar13 = FUN_00496870(iVar17,0);
        fVar6 = *(float *)(iVar14 + 8) - *(float *)(iVar13 + 8);
        pfVar11 = (float *)FUN_00496870(iVar17,2);
        pfVar12 = (float *)FUN_00496870(iVar17,0);
        fVar3 = *pfVar11;
        fVar4 = *pfVar12;
        iVar14 = FUN_00496870(iVar17,2);
        iVar13 = FUN_00496870(iVar17,0);
        fVar7 = *(float *)(iVar14 + 4) - *(float *)(iVar13 + 4);
        iVar14 = FUN_00496870(iVar17,2);
        iVar13 = FUN_00496870(iVar17,0);
        fVar8 = *(float *)(iVar14 + 8) - *(float *)(iVar13 + 8);
        pfVar11 = local_64 + -2;
        *pfVar11 = fVar8 * fVar5 - fVar7 * fVar6;
        local_64[-1] = (fVar3 - fVar4) * fVar6 - fVar8 * (fVar1 - fVar2);
        fVar1 = fVar7 * (fVar1 - fVar2) - (fVar3 - fVar4) * fVar5;
        *local_64 = fVar1;
        fVar2 = SQRT(local_64[-1] * local_64[-1] + *pfVar11 * *pfVar11 + fVar1 * fVar1);
        *pfVar11 = *pfVar11 / fVar2;
        local_64[-1] = local_64[-1] / fVar2;
        *local_64 = fVar1 / fVar2;
        iVar14 = FUN_00496870(iVar17,0);
        fVar1 = *(float *)(iVar14 + 4);
        fVar2 = local_64[-1];
        iVar14 = FUN_00496870(iVar17,0);
        fVar3 = *(float *)(iVar14 + 8);
        fVar4 = *local_64;
        pfVar12 = (float *)FUN_00496870(iVar17,0);
        local_64 = local_64 + 3;
        iVar10 = iVar10 + 6;
        *param_2 = *pfVar12 * *pfVar11 + fVar3 * fVar4 + fVar1 * fVar2;
        param_2 = param_2 + 1;
        local_60 = local_60 + -1;
      } while (local_60 != 0);
      param_3 = param_3 + 1;
      local_5c = local_5c + -1;
      local_64 = pfVar15;
    } while (local_5c != 0);
  }
  uVar9 = FUN_00496610();
  param_1[1] = uVar9;
  uVar9 = FUN_00496670();
  param_1[2] = uVar9;
  FUN_004afce0(s_Start__d_004fb0f8,uVar9);
  if (0 < (int)param_5) {
    param_3 = (int *)param_4;
    local_60 = (int)param_5;
    param_4 = (float *)(param_1 + 0xe3);
    param_5 = (float *)(param_1 + 0x171);
    do {
      puVar16 = local_30;
      param_2 = (float *)0x4;
      iVar10 = *param_3 * 0x8c;
      iVar17 = iVar10;
      do {
        puVar18 = (undefined4 *)(DAT_006a5ba0 + iVar17);
        puVar19 = local_20;
        for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar19 = *puVar18;
          puVar18 = puVar18 + 1;
          puVar19 = puVar19 + 1;
        }
        uVar9 = FUN_004967f0(local_20);
        *puVar16 = uVar9;
        iVar17 = iVar17 + 0x20;
        puVar16 = puVar16 + 1;
        param_2 = (float *)((int)param_2 + -1);
      } while (param_2 != (float *)0x0);
      param_2 = param_5;
      param_5 = param_5 + 2;
      pfVar15 = param_4 + 6;
      local_5c = 2;
      do {
        iVar17 = FUN_00496680(local_30[*(short *)(DAT_006a5ba0 + 0x80 + iVar10)],
                              local_30[*(short *)(DAT_006a5ba0 + 0x82 + iVar10)],
                              local_30[*(short *)(DAT_006a5ba0 + 0x84 + iVar10)]);
        iVar17 = iVar17 + -3;
        pfVar11 = (float *)FUN_004967c0(iVar17,1);
        pfVar12 = (float *)FUN_004967c0(iVar17,0);
        fVar1 = *pfVar11;
        fVar2 = *pfVar12;
        iVar14 = FUN_004967c0(iVar17,1);
        iVar13 = FUN_004967c0(iVar17,0);
        fVar5 = *(float *)(iVar14 + 4) - *(float *)(iVar13 + 4);
        iVar14 = FUN_004967c0(iVar17,1);
        iVar13 = FUN_004967c0(iVar17,0);
        fVar6 = *(float *)(iVar14 + 8) - *(float *)(iVar13 + 8);
        pfVar11 = (float *)FUN_004967c0(iVar17,2);
        pfVar12 = (float *)FUN_004967c0(iVar17,0);
        fVar3 = *pfVar11;
        fVar4 = *pfVar12;
        iVar14 = FUN_004967c0(iVar17,2);
        iVar13 = FUN_004967c0(iVar17,0);
        fVar7 = *(float *)(iVar14 + 4) - *(float *)(iVar13 + 4);
        iVar14 = FUN_004967c0(iVar17,2);
        iVar13 = FUN_004967c0(iVar17,0);
        fVar8 = *(float *)(iVar14 + 8) - *(float *)(iVar13 + 8);
        pfVar11 = param_4 + -2;
        *pfVar11 = fVar8 * fVar5 - fVar7 * fVar6;
        param_4[-1] = (fVar3 - fVar4) * fVar6 - fVar8 * (fVar1 - fVar2);
        fVar1 = fVar7 * (fVar1 - fVar2) - (fVar3 - fVar4) * fVar5;
        *param_4 = fVar1;
        fVar2 = SQRT(param_4[-1] * param_4[-1] + *pfVar11 * *pfVar11 + fVar1 * fVar1);
        *pfVar11 = *pfVar11 / fVar2;
        param_4[-1] = param_4[-1] / fVar2;
        *param_4 = fVar1 / fVar2;
        iVar14 = FUN_004967c0(iVar17,0);
        fVar1 = *(float *)(iVar14 + 4);
        fVar2 = param_4[-1];
        iVar14 = FUN_004967c0(iVar17,0);
        fVar3 = *(float *)(iVar14 + 8);
        fVar4 = *param_4;
        pfVar12 = (float *)FUN_004967c0(iVar17,0);
        param_4 = param_4 + 3;
        iVar10 = iVar10 + 6;
        *param_2 = *pfVar12 * *pfVar11 + fVar3 * fVar4 + fVar1 * fVar2;
        param_2 = param_2 + 1;
        local_5c = local_5c + -1;
      } while (local_5c != 0);
      param_3 = param_3 + 1;
      local_60 = local_60 + -1;
      param_4 = pfVar15;
    } while (local_60 != 0);
  }
  uVar9 = FUN_00496670();
  param_1[3] = uVar9;
  FUN_004afce0(s_End__d_004fb0f0,uVar9);
  uVar9 = FUN_004966e0();
  param_1[4] = uVar9;
  if (0 < param_9) {
    param_5 = (float *)(param_1 + 0x1e9);
    param_3 = param_8;
    param_8 = (int *)param_9;
    param_4 = (float *)(param_1 + 0x1a1);
    do {
      puVar16 = local_30;
      param_2 = (float *)0x4;
      iVar10 = *param_3 * 0x8c;
      iVar17 = iVar10;
      do {
        puVar18 = (undefined4 *)(iVar17 + DAT_006a5ba0);
        puVar19 = local_20;
        for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar19 = *puVar18;
          puVar18 = puVar18 + 1;
          puVar19 = puVar19 + 1;
        }
        uVar9 = FUN_00496940(local_20);
        *puVar16 = uVar9;
        iVar17 = iVar17 + 0x20;
        puVar16 = puVar16 + 1;
        param_2 = (float *)((int)param_2 + -1);
      } while (param_2 != (float *)0x0);
      param_2 = param_5;
      param_5 = param_5 + 2;
      pfVar15 = param_4 + 6;
      param_9 = 2;
      do {
        iVar17 = FUN_004966f0(local_30[*(short *)(iVar10 + 0x80 + DAT_006a5ba0)],
                              local_30[*(short *)(iVar10 + 0x82 + DAT_006a5ba0)],
                              local_30[*(short *)(iVar10 + 0x84 + DAT_006a5ba0)]);
        iVar17 = iVar17 + -3;
        pfVar11 = (float *)FUN_00496910(iVar17,1);
        pfVar12 = (float *)FUN_00496910(iVar17,0);
        fVar1 = *pfVar11;
        fVar2 = *pfVar12;
        iVar14 = FUN_00496910(iVar17,1);
        iVar13 = FUN_00496910(iVar17,0);
        fVar5 = *(float *)(iVar14 + 4) - *(float *)(iVar13 + 4);
        iVar14 = FUN_00496910(iVar17,1);
        iVar13 = FUN_00496910(iVar17,0);
        fVar6 = *(float *)(iVar14 + 8) - *(float *)(iVar13 + 8);
        pfVar11 = (float *)FUN_00496910(iVar17,2);
        pfVar12 = (float *)FUN_00496910(iVar17,0);
        fVar3 = *pfVar11;
        fVar4 = *pfVar12;
        iVar14 = FUN_00496910(iVar17,2);
        iVar13 = FUN_00496910(iVar17,0);
        fVar7 = *(float *)(iVar14 + 4) - *(float *)(iVar13 + 4);
        iVar14 = FUN_00496910(iVar17,2);
        iVar13 = FUN_00496910(iVar17,0);
        fVar8 = *(float *)(iVar14 + 8) - *(float *)(iVar13 + 8);
        *param_4 = fVar8 * fVar5 - fVar7 * fVar6;
        param_4[1] = (fVar3 - fVar4) * fVar6 - fVar8 * (fVar1 - fVar2);
        fVar1 = fVar7 * (fVar1 - fVar2) - (fVar3 - fVar4) * fVar5;
        param_4[2] = fVar1;
        fVar2 = SQRT(*param_4 * *param_4 + param_4[1] * param_4[1] + fVar1 * fVar1);
        *param_4 = *param_4 / fVar2;
        param_4[1] = param_4[1] / fVar2;
        param_4[2] = fVar1 / fVar2;
        iVar14 = FUN_00496910(iVar17,0);
        fVar1 = *(float *)(iVar14 + 8);
        fVar2 = param_4[2];
        iVar14 = FUN_00496910(iVar17,0);
        fVar3 = *(float *)(iVar14 + 4);
        fVar4 = param_4[1];
        pfVar11 = (float *)FUN_00496910(iVar17,0);
        *param_2 = *pfVar11 * *param_4 + fVar3 * fVar4 + fVar1 * fVar2;
        param_2 = param_2 + 1;
        param_4 = param_4 + 3;
        iVar10 = iVar10 + 6;
        param_9 = param_9 + -1;
      } while (param_9 != 0);
      param_3 = param_3 + 1;
      param_8 = (int *)((int)param_8 + -1);
      param_4 = pfVar15;
    } while (param_8 != (int *)0x0);
  }
  uVar9 = FUN_004966e0();
  param_1[5] = uVar9;
  uVar9 = FUN_00496740();
  param_1[6] = uVar9;
  if (0 < param_7) {
    param_5 = (float *)(param_1 + 0x249);
    param_3 = param_6;
    param_8 = (int *)param_7;
    param_4 = (float *)(param_1 + 0x201);
    do {
      puVar16 = local_30;
      param_2 = (float *)0x4;
      iVar10 = *param_3 * 0x8c;
      iVar17 = iVar10;
      do {
        puVar18 = (undefined4 *)(iVar17 + DAT_006a5ba0);
        puVar19 = local_20;
        for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar19 = *puVar18;
          puVar18 = puVar18 + 1;
          puVar19 = puVar19 + 1;
        }
        uVar9 = FUN_004969e0(local_20);
        *puVar16 = uVar9;
        iVar17 = iVar17 + 0x20;
        puVar16 = puVar16 + 1;
        param_2 = (float *)((int)param_2 + -1);
      } while (param_2 != (float *)0x0);
      param_2 = param_5;
      param_5 = param_5 + 2;
      pfVar15 = param_4 + 6;
      param_9 = 2;
      do {
        iVar17 = FUN_00496750(local_30[*(short *)(iVar10 + 0x80 + DAT_006a5ba0)],
                              local_30[*(short *)(iVar10 + 0x82 + DAT_006a5ba0)],
                              local_30[*(short *)(iVar10 + 0x84 + DAT_006a5ba0)]);
        iVar17 = iVar17 + -3;
        pfVar11 = (float *)FUN_004969b0(iVar17,1);
        pfVar12 = (float *)FUN_004969b0(iVar17,0);
        fVar1 = *pfVar11;
        fVar2 = *pfVar12;
        iVar14 = FUN_004969b0(iVar17,1);
        iVar13 = FUN_004969b0(iVar17,0);
        fVar5 = *(float *)(iVar14 + 4) - *(float *)(iVar13 + 4);
        iVar14 = FUN_004969b0(iVar17,1);
        iVar13 = FUN_004969b0(iVar17,0);
        fVar6 = *(float *)(iVar14 + 8) - *(float *)(iVar13 + 8);
        pfVar11 = (float *)FUN_004969b0(iVar17,2);
        pfVar12 = (float *)FUN_004969b0(iVar17,0);
        fVar3 = *pfVar11;
        fVar4 = *pfVar12;
        iVar14 = FUN_004969b0(iVar17,2);
        iVar13 = FUN_004969b0(iVar17,0);
        fVar7 = *(float *)(iVar14 + 4) - *(float *)(iVar13 + 4);
        iVar14 = FUN_004969b0(iVar17,2);
        iVar13 = FUN_004969b0(iVar17,0);
        fVar8 = *(float *)(iVar14 + 8) - *(float *)(iVar13 + 8);
        *param_4 = fVar8 * fVar5 - fVar7 * fVar6;
        param_4[1] = (fVar3 - fVar4) * fVar6 - fVar8 * (fVar1 - fVar2);
        fVar1 = fVar7 * (fVar1 - fVar2) - (fVar3 - fVar4) * fVar5;
        param_4[2] = fVar1;
        fVar2 = SQRT(param_4[1] * param_4[1] + fVar1 * fVar1 + *param_4 * *param_4);
        *param_4 = *param_4 / fVar2;
        param_4[1] = param_4[1] / fVar2;
        param_4[2] = fVar1 / fVar2;
        iVar14 = FUN_004969b0(iVar17,0);
        fVar1 = *(float *)(iVar14 + 8);
        fVar2 = param_4[2];
        iVar14 = FUN_004969b0(iVar17,0);
        fVar3 = *(float *)(iVar14 + 4);
        fVar4 = param_4[1];
        pfVar11 = (float *)FUN_004969b0(iVar17,0);
        *param_2 = *pfVar11 * *param_4 + fVar3 * fVar4 + fVar1 * fVar2;
        param_2 = param_2 + 1;
        param_4 = param_4 + 3;
        iVar10 = iVar10 + 6;
        param_9 = param_9 + -1;
      } while (param_9 != 0);
      param_3 = param_3 + 1;
      param_8 = (int *)((int)param_8 + -1);
      param_4 = pfVar15;
    } while (param_8 != (int *)0x0);
  }
  uVar9 = FUN_00496740();
  param_1[7] = uVar9;
  return;
}

