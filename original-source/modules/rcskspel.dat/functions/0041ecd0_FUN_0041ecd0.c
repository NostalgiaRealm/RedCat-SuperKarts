/*
 * FUN_0041ecd0 at 0041ecd0
 * undefined FUN_0041ecd0(void)
 * Address ranges: 0041ecd0-0041f727
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041ecd0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  float *pfVar10;
  undefined4 *puVar11;
  undefined4 auStack_228 [5];
  undefined4 uStack_214;
  undefined1 *puStack_210;
  undefined4 *puStack_20c;
  undefined4 *puStack_208;
  undefined1 *puStack_204;
  float *pfStack_200;
  undefined4 *puStack_1fc;
  float *pfStack_1f8;
  undefined4 *local_1f4;
  float *local_1f0;
  undefined4 *local_1ec;
  float local_1cc;
  float local_1c8;
  float local_1c4;
  float local_1bc;
  float local_1b8;
  float local_1b4;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a4;
  float local_1a0;
  float local_19c;
  float local_198;
  float local_194;
  float local_190;
  float local_18c;
  float local_188;
  float local_184;
  undefined4 local_180 [12];
  float local_150;
  float local_14c;
  float local_148;
  float local_140 [16];
  undefined4 local_100 [16];
  float local_c0 [16];
  undefined1 local_80 [64];
  undefined4 local_40 [16];
  
  iVar8 = (&DAT_00508620)[DAT_00508670];
  local_1ec = (undefined4 *)0x55;
  local_1f0 = (float *)0x41eced;
  iVar4 = FUN_004b3830();
  if (iVar4 != 0) {
    local_1ec = (undefined4 *)0x55;
    local_1f0 = (float *)0x41ecff;
    iVar4 = FUN_004b3830();
    while (iVar4 != 0) {
      local_1ec = (undefined4 *)0x55;
      local_1f0 = (float *)0x41ed0d;
      iVar4 = FUN_004b3830();
    }
    DAT_004e306c = DAT_004e306c ^ 1;
    if (DAT_004e306c == 0) {
      iVar4 = DAT_00680ba0 + 8 + iVar8 * 0x178;
      DAT_00508678 = *(float *)(DAT_00680ba0 + 8 + iVar8 * 0x178);
      DAT_0050867c = *(float *)(iVar4 + 4);
      DAT_00508680 = *(float *)(iVar4 + 8);
    }
    else {
      iVar4 = DAT_00680ba0 + 8 + iVar8 * 0x178;
      local_1a4 = *(float *)(DAT_00680ba0 + 8 + iVar8 * 0x178);
      local_1a0 = *(float *)(iVar4 + 4);
      local_19c = *(float *)(iVar4 + 8);
      DAT_00508678 = local_1a4 -
                     *(float *)(DAT_006a5c38 + DAT_00508684 + 0x50 + DAT_00508684 * 0xa8);
      iVar4 = DAT_006a5c38 + DAT_00508684 + 0x50 + DAT_00508684 * 0xa8;
      DAT_0050867c = local_1a0 - *(float *)(iVar4 + 4);
      DAT_00508680 = local_19c - *(float *)(iVar4 + 8);
      local_198 = DAT_00508678;
      local_194 = DAT_0050867c;
      local_190 = DAT_00508680;
    }
  }
  local_1cc = DAT_00508678;
  iVar8 = iVar8 * 0x178;
  local_1ac = DAT_0050867c;
  pfVar5 = (float *)(iVar8 + 0x14 + DAT_00680ba0);
  pfVar10 = local_c0;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar10 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar10 = pfVar10 + 1;
  }
  local_1a8 = DAT_00508680;
  local_1ec = local_c0;
  local_1f0 = &local_1bc;
  local_1b0 = DAT_00508678;
  local_1f4 = (undefined4 *)0x41ee20;
  pfVar5 = (float *)FUN_004a2350();
  local_198 = *pfVar5;
  local_1f4 = local_c0;
  local_194 = pfVar5[1];
  pfStack_1f8 = &local_1bc;
  local_190 = pfVar5[2];
  puStack_1fc = (undefined4 *)0x41ee46;
  pfVar5 = (float *)FUN_004a2390();
  local_1a4 = *pfVar5;
  puStack_1fc = local_c0;
  local_1a0 = pfVar5[1];
  pfStack_200 = &local_1bc;
  local_19c = pfVar5[2];
  puStack_204 = (undefined1 *)0x41ee6c;
  pfVar5 = (float *)FUN_004a23d0();
  local_18c = *pfVar5;
  local_188 = pfVar5[1];
  local_1c8 = local_1ac;
  local_184 = pfVar5[2];
  local_1c4 = local_1a8;
  local_1ec = (undefined4 *)0x41eea1;
  FUN_0048f4e0();
  fVar2 = DAT_004e2ac0;
  local_1ec = (undefined4 *)0x41eeb7;
  iVar4 = __ftol();
  local_1ec = (undefined4 *)0x49;
  local_1f0 = (float *)0x41eec0;
  iVar6 = FUN_004b3830();
  if (iVar6 != 0) {
    local_1b8 = local_188 * fVar2;
    local_1b4 = local_184 * fVar2;
    local_1cc = local_1b0 + local_18c * fVar2;
    local_1c8 = local_1ac + local_1b8;
    local_1c4 = local_1a8 + local_1b4;
  }
  local_1ec = (undefined4 *)0x4a;
  local_1f0 = (float *)0x41ef2a;
  iVar6 = FUN_004b3830();
  if (iVar6 != 0) {
    fVar1 = -fVar2;
    local_1bc = local_198 * fVar1;
    local_1b8 = local_194 * fVar1;
    local_1cc = local_1bc + local_1b0;
    local_1c8 = local_1b8 + local_1ac;
    local_1c4 = fVar1 * local_190 + local_1a8;
  }
  local_1ec = (undefined4 *)0x4b;
  local_1f0 = (float *)0x41ef8e;
  iVar6 = FUN_004b3830();
  if (iVar6 != 0) {
    fVar1 = -fVar2;
    local_1bc = local_18c * fVar1;
    local_1b8 = local_188 * fVar1;
    local_1cc = local_1bc + local_1b0;
    local_1c8 = local_1b8 + local_1ac;
    local_1c4 = fVar1 * local_184 + local_1a8;
  }
  local_1ec = (undefined4 *)0x4c;
  local_1f0 = (float *)0x41eff2;
  iVar6 = FUN_004b3830();
  if (iVar6 != 0) {
    local_1b8 = local_194 * fVar2;
    local_1b4 = local_190 * fVar2;
    local_1cc = local_198 * fVar2 + local_1b0;
    local_1c8 = local_1b8 + local_1ac;
    local_1c4 = local_1b4 + local_1a8;
  }
  local_1ec = (undefined4 *)0x41;
  local_1f0 = (float *)0x41f058;
  iVar6 = FUN_004b3830();
  if (iVar6 != 0) {
    local_1b8 = local_1a0 * fVar2;
    local_1b4 = local_19c * fVar2;
    local_1cc = local_1a4 * fVar2 + local_1b0;
    local_1c8 = local_1b8 + local_1ac;
    local_1c4 = local_1b4 + local_1a8;
  }
  local_1ec = (undefined4 *)0x5a;
  local_1f0 = (float *)0x41f0be;
  iVar6 = FUN_004b3830();
  if (iVar6 != 0) {
    fVar2 = -fVar2;
    local_1bc = local_1a4 * fVar2;
    local_1b8 = local_1a0 * fVar2;
    local_1cc = local_1bc + local_1b0;
    local_1c8 = local_1b8 + local_1ac;
    local_1c4 = fVar2 * local_19c + local_1a8;
  }
  local_1ec = (undefined4 *)0x21;
  local_1f0 = (float *)0x41f122;
  iVar6 = FUN_004b3830();
  if (iVar6 != 0) {
    local_1f0 = local_140;
    local_1f4 = (undefined4 *)0x41f137;
    local_1ec = (undefined4 *)iVar4;
    puVar7 = (undefined4 *)FUN_004a2200();
    local_1f4 = local_100;
    puVar9 = local_100;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    pfStack_1f8 = local_c0;
    puStack_1fc = local_140;
    pfStack_200 = (float *)0x41f164;
    puVar7 = (undefined4 *)FUN_004a2560();
    puVar9 = puVar7;
    puVar11 = local_180;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    puVar9 = auStack_228;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    FUN_004988f0();
  }
  local_1ec = (undefined4 *)0x22;
  local_1f0 = (float *)0x41f194;
  iVar6 = FUN_004b3830();
  if (iVar6 != 0) {
    local_1f0 = local_140;
    local_1ec = (undefined4 *)-iVar4;
    local_1f4 = (undefined4 *)0x41f1ad;
    puVar7 = (undefined4 *)FUN_004a2200();
    local_1f4 = local_100;
    puVar9 = local_100;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    pfStack_1f8 = local_c0;
    puStack_1fc = local_140;
    pfStack_200 = (float *)0x41f1da;
    puVar7 = (undefined4 *)FUN_004a2560();
    puVar9 = puVar7;
    puVar11 = local_180;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    puVar9 = auStack_228;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    FUN_004988f0();
  }
  local_1ec = (undefined4 *)0x24;
  local_1f0 = (float *)0x41f20a;
  iVar6 = FUN_004b3830();
  if (iVar6 != 0) {
    local_1f0 = local_140;
    local_1f4 = (undefined4 *)0x41f21f;
    local_1ec = (undefined4 *)iVar4;
    puVar7 = (undefined4 *)FUN_004a2270();
    pfStack_1f8 = local_c0;
    puVar9 = local_100;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    local_1f4 = local_100;
    puStack_1fc = local_140;
    pfStack_200 = (float *)0x41f24c;
    puVar7 = (undefined4 *)FUN_004a2560();
    puVar9 = puVar7;
    puVar11 = local_180;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    puVar9 = auStack_228;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    FUN_004988f0();
  }
  local_1ec = (undefined4 *)0x23;
  local_1f0 = (float *)0x41f27b;
  iVar6 = FUN_004b3830();
  if (iVar6 != 0) {
    local_1f0 = local_140;
    local_1ec = (undefined4 *)-iVar4;
    local_1f4 = (undefined4 *)0x41f294;
    puVar7 = (undefined4 *)FUN_004a2270();
    pfStack_1f8 = local_c0;
    puVar9 = local_100;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    local_1f4 = local_100;
    puStack_1fc = local_140;
    pfStack_200 = (float *)0x41f2c1;
    puVar7 = (undefined4 *)FUN_004a2560();
    puVar9 = puVar7;
    puVar11 = local_180;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    puVar9 = auStack_228;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    FUN_004988f0();
  }
  local_1ec = (undefined4 *)0x2d;
  local_1f0 = (float *)0x41f2f0;
  iVar6 = FUN_004b3830();
  if (iVar6 != 0) {
    local_1f0 = local_140;
    local_1f4 = (undefined4 *)0x41f305;
    local_1ec = (undefined4 *)iVar4;
    puVar7 = (undefined4 *)FUN_004a22e0();
    local_1f4 = local_100;
    puVar9 = local_100;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    pfStack_1f8 = local_c0;
    puStack_1fc = local_140;
    pfStack_200 = (float *)0x41f332;
    puVar7 = (undefined4 *)FUN_004a2560();
    puVar9 = puVar7;
    puVar11 = local_180;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    puVar9 = auStack_228;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    FUN_004988f0();
  }
  local_1ec = (undefined4 *)0x2e;
  local_1f0 = (float *)0x41f361;
  iVar6 = FUN_004b3830();
  if (iVar6 != 0) {
    local_1ec = (undefined4 *)-iVar4;
    local_1f0 = local_140;
    local_1f4 = (undefined4 *)0x41f378;
    puVar7 = (undefined4 *)FUN_004a22e0();
    local_1f4 = local_100;
    puVar9 = local_100;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    pfStack_1f8 = local_c0;
    puStack_1fc = local_140;
    pfStack_200 = (float *)0x41f3a5;
    puVar7 = (undefined4 *)FUN_004a2560();
    puVar9 = puVar7;
    puVar11 = local_180;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    puVar9 = auStack_228;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    FUN_004988f0();
  }
  local_1ec = (undefined4 *)0x41f3d3;
  FUN_00431750();
  local_1ec = (undefined4 *)0x41f3da;
  pfVar5 = (float *)FUN_00431830();
  local_1a4 = *pfVar5;
  local_1a0 = pfVar5[1];
  local_19c = pfVar5[2];
  if ((local_1a4 != 0.0) || (local_1a0 != 0.0)) {
    local_1ec = (undefined4 *)0x41f41d;
    local_1ec = (undefined4 *)__ftol();
    local_1f0 = (float *)local_80;
    local_1f4 = (undefined4 *)0x41f42b;
    pfVar5 = (float *)FUN_004a2200();
    pfVar10 = local_140;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pfVar10 = *pfVar5;
      pfVar5 = pfVar5 + 1;
      pfVar10 = pfVar10 + 1;
    }
    local_1f4 = (undefined4 *)0x41f446;
    local_1f4 = (undefined4 *)__ftol();
    pfStack_1f8 = (float *)local_80;
    puStack_1fc = (undefined4 *)0x41f454;
    puVar7 = (undefined4 *)FUN_004a2270();
    puStack_1fc = local_40;
    puVar9 = local_40;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    pfStack_200 = local_140;
    puStack_204 = local_80;
    puStack_208 = (undefined4 *)0x41f481;
    puVar7 = (undefined4 *)FUN_004a2560();
    puStack_208 = local_180;
    puVar9 = local_180;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    puStack_20c = local_c0;
    puStack_210 = local_80;
    uStack_214 = 0x41f4ae;
    puVar7 = (undefined4 *)FUN_004a2560();
    puVar9 = puVar7;
    puVar11 = local_180;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    puVar9 = auStack_228;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    FUN_004988f0();
  }
  DAT_00508678 = local_1cc;
  DAT_0050867c = local_1c8;
  DAT_00508680 = local_1c4;
  if (DAT_004e306c == 0) {
    local_1f4 = (undefined4 *)local_1cc;
    local_1f0 = (float *)local_1c8;
    local_1ec = (undefined4 *)local_1c4;
  }
  else {
    local_1f4 = (undefined4 *)
                (local_1cc + *(float *)(DAT_006a5c38 + DAT_00508684 + 0x50 + DAT_00508684 * 0xa8));
    iVar4 = DAT_006a5c38 + DAT_00508684 + 0x50 + DAT_00508684 * 0xa8;
    local_1f0 = (float *)(local_1c8 + *(float *)(iVar4 + 4));
    local_1ec = (undefined4 *)(local_1c4 + *(float *)(iVar4 + 8));
  }
  pfStack_1f8 = (float *)0x41f57c;
  FUN_004988a0();
  local_1ec = (undefined4 *)0x52;
  local_1f0 = (float *)0x41f583;
  iVar4 = FUN_004b3830();
  if (iVar4 != 0) {
    local_1ec = (undefined4 *)local_80;
    local_1f0 = (float *)0x41f59b;
    puVar7 = (undefined4 *)FUN_0041cdd0();
    puVar9 = local_180;
    for (iVar4 = 0x10; fVar3 = local_148, fVar1 = local_14c, fVar2 = local_150, iVar4 != 0;
        iVar4 = iVar4 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    local_150 = 0.0;
    local_14c = 0.0;
    local_148 = 0.0;
    if (DAT_004e306c == 0) {
      DAT_00508678 = fVar2;
      DAT_0050867c = fVar1;
      DAT_00508680 = fVar3;
    }
    else {
      DAT_00508678 = fVar2 - *(float *)(DAT_006a5c38 + DAT_00508684 + 0x50 + DAT_00508684 * 0xa8);
      iVar4 = DAT_006a5c38 + DAT_00508684 + 0x50 + DAT_00508684 * 0xa8;
      DAT_0050867c = fVar1 - *(float *)(iVar4 + 4);
      DAT_00508680 = fVar3 - *(float *)(iVar4 + 8);
    }
    puVar7 = local_180;
    puVar9 = auStack_228;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    FUN_004988f0();
    local_1f4 = (undefined4 *)fVar2;
    local_1f0 = (float *)fVar1;
    local_1ec = (undefined4 *)fVar3;
    pfStack_1f8 = (float *)0x41f6b3;
    FUN_004988a0();
  }
  local_1ec = (undefined4 *)0x54;
  local_1f0 = (float *)0x41f6ba;
  iVar4 = FUN_004b3830();
  if (iVar4 != 0) {
    puVar7 = (undefined4 *)(iVar8 + 0x14 + DAT_00680ba0);
    puVar9 = local_180;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar7 = (undefined4 *)(iVar8 + 8 + DAT_00680ba0);
    local_150 = (float)*puVar7;
    local_148 = (float)puVar7[2];
    local_14c = (float)puVar7[1];
    puVar7 = local_180;
    puVar9 = auStack_228;
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    FUN_0041d010();
  }
  return;
}

