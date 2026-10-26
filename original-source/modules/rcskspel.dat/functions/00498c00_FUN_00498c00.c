/*
 * FUN_00498c00 at 00498c00
 * undefined FUN_00498c00(void)
 * Address ranges: 00498c00-00499498
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00498c00(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float *pfVar10;
  float *pfVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [64];
  
  if (*(int *)(param_1 + 0x7c) == 1) {
    FUN_004afce0(s_FOLLOW_MODE_is_ON__004fb7a8);
    pfVar1 = (float *)(param_1 + 8);
    pfVar10 = (float *)(*(int *)(param_1 + 0xec) + *(int *)(param_1 + 0xe8) * 0xc);
    *pfVar1 = *pfVar10;
    *(float *)(param_1 + 0xc) = pfVar10[1];
    *(float *)(param_1 + 0x10) = pfVar10[2];
    puVar13 = (undefined4 *)(*(int *)(param_1 + 0xe8) * 0x40 + *(int *)(param_1 + 0x132));
    puVar16 = (undefined4 *)(param_1 + 0x14);
    for (iVar14 = 0x10; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar16 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar16 = puVar16 + 1;
    }
    iVar14 = DAT_006a5c38 + *(int *)(param_1 + 0xd8) * 0xa9;
    *pfVar10 = *(float *)(iVar14 + 0x50);
    pfVar10[1] = *(float *)(iVar14 + 0x54);
    pfVar10[2] = *(float *)(iVar14 + 0x58);
    puVar13 = (undefined4 *)(DAT_006a5c38 + *(int *)(param_1 + 0xd8) * 0xa9 + 0x10);
    puVar16 = (undefined4 *)(*(int *)(param_1 + 0xe8) * 0x40 + *(int *)(param_1 + 0x132));
    for (iVar14 = 0x10; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar16 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar16 = puVar16 + 1;
    }
    iVar14 = *(int *)(param_1 + 0xe8) + 1;
    *(int *)(param_1 + 0xe8) = iVar14;
    if (4 < iVar14) {
      *(undefined4 *)(param_1 + 0xe8) = 0;
    }
    pfVar10 = (float *)FUN_004a25f0(&local_4c,param_1 + 0xdc,(undefined4 *)(param_1 + 0x14));
    fVar2 = pfVar10[1];
    fVar3 = pfVar10[2];
    *pfVar1 = *pfVar10 + *pfVar1;
    *(float *)(param_1 + 0xc) = fVar2 + *(float *)(param_1 + 0xc);
    *(float *)(param_1 + 0x10) = fVar3 + *(float *)(param_1 + 0x10);
  }
  else {
    if (*(int *)(param_1 + 0x74) == 1) {
      FUN_004afce0(s_POSITION_LOCK_is_ON__004fb790);
      if (*(int *)(param_1 + 0xb8) == -1) {
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0xbc);
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0xc0);
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0xc4);
      }
      else {
        pfVar1 = (float *)(param_1 + 8);
        iVar14 = *(int *)(param_1 + 0xb8) * 0xa9;
        pfVar10 = (float *)(iVar14 + 0x50 + DAT_006a5c38);
        *pfVar1 = *pfVar10;
        *(float *)(param_1 + 0xc) = pfVar10[1];
        *(float *)(param_1 + 0x10) = pfVar10[2];
        puVar13 = (undefined4 *)(iVar14 + 0x10 + DAT_006a5c38);
        puVar16 = (undefined4 *)(param_1 + 0x14);
        for (iVar15 = 0x10; iVar15 != 0; iVar15 = iVar15 + -1) {
          *puVar16 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar16 = puVar16 + 1;
        }
        pfVar10 = (float *)FUN_004a25f0(&local_4c,param_1 + 0xbc,(undefined4 *)(param_1 + 0x14));
        fVar2 = pfVar10[1];
        fVar3 = pfVar10[2];
        *pfVar1 = *pfVar10 + *pfVar1;
        *(float *)(param_1 + 0xc) = fVar2 + *(float *)(param_1 + 0xc);
        *(float *)(param_1 + 0x10) = fVar3 + *(float *)(param_1 + 0x10);
      }
    }
    pfVar1 = (float *)(param_1 + 0x54);
    pfVar11 = (float *)FUN_004a23d0(&local_4c,param_1 + 0x14);
    pfVar10 = (float *)(param_1 + 8);
    *pfVar1 = *pfVar11;
    *(float *)(param_1 + 0x58) = pfVar11[1];
    *(float *)(param_1 + 0x5c) = pfVar11[2];
    *pfVar1 = *pfVar10 + *pfVar1;
    *(float *)(param_1 + 0x58) = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x58);
    *(float *)(param_1 + 0x5c) = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0x5c);
    if (*(int *)(param_1 + 0x78) == 1) {
      FUN_004afce0(s_TARGET_LOCK_is_ON__004fb77c);
      if (*(int *)(param_1 + 200) == -1) {
        *pfVar1 = *(float *)(param_1 + 0xcc);
        *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0xd0);
        *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0xd4);
      }
      else {
        pfVar11 = (float *)FUN_004a25f0(&local_4c,param_1 + 0xcc,
                                        DAT_006a5c38 + *(int *)(param_1 + 200) * 0xa9 + 0x10);
        iVar15 = *(int *)(param_1 + 200);
        fVar5 = pfVar11[1];
        fVar4 = pfVar11[2];
        iVar14 = DAT_006a5c38 + iVar15 + 0x50 + iVar15 * 0xa8;
        fVar2 = *(float *)(iVar14 + 4);
        fVar3 = *(float *)(iVar14 + 8);
        *pfVar1 = *pfVar11 + *(float *)(DAT_006a5c38 + iVar15 + 0x50 + iVar15 * 0xa8);
        *(float *)(param_1 + 0x58) = fVar5 + fVar2;
        *(float *)(param_1 + 0x5c) = fVar4 + fVar3;
      }
    }
    if ((DAT_00680c54 & 1) == 0) {
      DAT_00680c54 = DAT_00680c54 | 1;
      FUN_004be654(&DAT_004994e0);
    }
    if ((DAT_00680c54 & 2) == 0) {
      DAT_00680c54 = DAT_00680c54 | 2;
      FUN_004be654(&DAT_004994d0);
    }
    if ((DAT_00680c54 & 4) == 0) {
      DAT_00680c54 = DAT_00680c54 | 4;
      FUN_004be654(&DAT_004994c0);
    }
    if ((DAT_00680c54 & 8) == 0) {
      DAT_00680c54 = DAT_00680c54 | 8;
      FUN_004be654(&DAT_004994b0);
    }
    if ((DAT_00680c54 & 0x10) == 0) {
      DAT_00680c54 = DAT_00680c54 | 0x10;
      FUN_004be654(&DAT_004994a0);
    }
    if (*(int *)(param_1 + 0x6c) == 1) {
      FUN_004afce0(s_DAMPENING_is_ON__004fb768);
      _DAT_00680c18 = *pfVar10 - *(float *)(param_1 + 0xa0);
      _DAT_00680c1c = *(float *)(param_1 + 0xc) - *(float *)(param_1 + 0xa4);
      _DAT_00680c20 = *(float *)(param_1 + 0x10) - *(float *)(param_1 + 0xa8);
      uVar12 = FUN_004a2660(local_40,DAT_006a5c38 + *(int *)(param_1 + 200) * 0xa9 + 0x10);
      pfVar11 = (float *)FUN_004a25f0(&local_4c,&DAT_00680c18,uVar12);
      _DAT_00680c58 = *pfVar11 * *(float *)(param_1 + 0x88);
      _DAT_00680c5c = pfVar11[1] * *(float *)(param_1 + 0x8c);
      _DAT_00680c60 = pfVar11[2] * *(float *)(param_1 + 0x90);
      pfVar11 = (float *)FUN_004a25f0(&local_4c,&DAT_00680c58,
                                      DAT_006a5c38 + *(int *)(param_1 + 200) * 0xa9 + 0x10);
      _DAT_00680c48 = *pfVar11;
      _DAT_00680c4c = pfVar11[1];
      _DAT_00680c50 = pfVar11[2];
      fVar2 = _DAT_00680c4c + *(float *)(param_1 + 0xa4);
      fVar3 = _DAT_00680c50 + *(float *)(param_1 + 0xa8);
      *pfVar10 = _DAT_00680c48 + *(float *)(param_1 + 0xa0);
      *(float *)(param_1 + 0xc) = fVar2;
      *(float *)(param_1 + 0x10) = fVar3;
    }
    if (*(int *)(param_1 + 0x70) == 1) {
      _DAT_00680c18 = *pfVar1 - *(float *)(param_1 + 0xac);
      _DAT_00680c1c = *(float *)(param_1 + 0x58) - *(float *)(param_1 + 0xb0);
      _DAT_00680c20 = *(float *)(param_1 + 0x5c) - *(float *)(param_1 + 0xb4);
      _DAT_00680c48 = _DAT_00680c18 * *(float *)(param_1 + 0x94);
      _DAT_00680c4c = _DAT_00680c1c * *(float *)(param_1 + 0x98);
      _DAT_00680c50 = _DAT_00680c20 * *(float *)(param_1 + 0x9c);
      fVar2 = _DAT_00680c48 + *(float *)(param_1 + 0xac);
      fVar3 = _DAT_00680c4c + *(float *)(param_1 + 0xb0);
      fVar5 = _DAT_00680c50 + *(float *)(param_1 + 0xb4);
      _DAT_00680c58 = _DAT_00680c48;
      _DAT_00680c5c = _DAT_00680c4c;
      _DAT_00680c60 = _DAT_00680c50;
      *pfVar1 = fVar2;
      *(float *)(param_1 + 0xac) = fVar2;
      *(float *)(param_1 + 0xb0) = fVar3;
      *(float *)(param_1 + 0x58) = fVar3;
      *(float *)(param_1 + 0xb4) = fVar5;
      *(float *)(param_1 + 0x5c) = fVar5;
    }
    if (*(int *)(param_1 + 0x80) == 1) {
      puVar13 = (undefined4 *)FUN_004a2390(&local_4c,param_1 + 0x14);
      *(undefined4 *)(param_1 + 0x60) = *puVar13;
      *(undefined4 *)(param_1 + 100) = puVar13[1];
      *(undefined4 *)(param_1 + 0x68) = puVar13[2];
    }
    else {
      *(undefined4 *)(param_1 + 0x60) = 0;
      *(undefined4 *)(param_1 + 100) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x68) = 0;
    }
    fVar4 = *pfVar1 - *pfVar10;
    fVar7 = *(float *)(param_1 + 0x58) - *(float *)(param_1 + 0xc);
    fVar2 = *(float *)(param_1 + 0x60);
    fVar3 = *(float *)(param_1 + 0x68);
    fVar5 = *(float *)(param_1 + 100);
    fVar8 = *(float *)(param_1 + 0x5c) - *(float *)(param_1 + 0x10);
    fVar6 = SQRT(fVar7 * fVar7 + fVar8 * fVar8 + fVar4 * fVar4);
    fVar4 = fVar4 / fVar6;
    fVar7 = fVar7 / fVar6;
    fVar8 = fVar8 / fVar6;
    fVar6 = SQRT(fVar5 * fVar5 + fVar3 * fVar3 + fVar2 * fVar2);
    fVar9 = (fVar5 / fVar6) * fVar8 - (fVar3 / fVar6) * fVar7;
    fVar3 = (fVar3 / fVar6) * fVar4 - fVar8 * (fVar2 / fVar6);
    fVar5 = fVar7 * (fVar2 / fVar6) - (fVar5 / fVar6) * fVar4;
    fVar2 = SQRT(fVar9 * fVar9 + fVar3 * fVar3 + fVar5 * fVar5);
    fVar9 = fVar9 / fVar2;
    iVar14 = param_1 + 0x14;
    fVar3 = fVar3 / fVar2;
    fVar5 = fVar5 / fVar2;
    local_4c = fVar5 * fVar7 - fVar3 * fVar8;
    local_48 = fVar8 * fVar9 - fVar5 * fVar4;
    local_44 = fVar3 * fVar4 - fVar7 * fVar9;
    fVar2 = SQRT(local_4c * local_4c + local_48 * local_48 + local_44 * local_44);
    local_4c = local_4c / fVar2;
    local_48 = local_48 / fVar2;
    local_44 = local_44 / fVar2;
    FUN_004a2410(iVar14,fVar9,fVar3,fVar5);
    FUN_004a2430(iVar14,local_4c,local_48,local_44);
    FUN_004a2450(iVar14,fVar4,fVar7,fVar8);
  }
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x10);
  return;
}

