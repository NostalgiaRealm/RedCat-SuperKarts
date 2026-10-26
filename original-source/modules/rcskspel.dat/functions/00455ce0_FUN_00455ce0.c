/*
 * FUN_00455ce0 at 00455ce0
 * undefined FUN_00455ce0(void)
 * Address ranges: 00455ce0-0045609f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00455ce0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  char cVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  float *pfVar14;
  uint uVar15;
  float10 fVar16;
  undefined1 auStack_c [12];
  
  uVar11 = FUN_0044fb50();
  iVar12 = FUN_0044fbc0();
  iVar13 = FUN_00456ad0(uVar11,iVar12);
  if (*(float *)(iVar13 + 4) <= *(float *)(param_1 + 0x1c)) {
    FUN_00456440(1);
    return;
  }
  fVar4 = *(float *)(iVar13 + 0x10) + *(float *)(param_1 + 0x38);
  if ((*(int *)(param_1 + 0x24) == -2) || (iVar12 == 1)) {
    FUN_0044fff0();
    uVar15 = __ftol();
    iVar12 = FUN_0044fff0();
    fVar16 = (float10)FUN_0048f4e0();
    iVar13 = FUN_004504f0();
    *(float *)(iVar12 + 8) = (float)iVar13 * (float)fVar16 + *(float *)(iVar12 + 8);
    pfVar14 = (float *)FUN_0044ff90();
    fVar16 = (float10)FUN_0048f4e0();
    *pfVar14 = (float)((float10)*pfVar14 -
                      fVar16 * (float10)*(float *)(DAT_006a5c88 + (DAT_004fc8f8 & uVar15) * 4) *
                      (float10)fVar4);
    iVar12 = FUN_0044ff90();
    fVar16 = (float10)FUN_0048f4e0();
    *(float *)(iVar12 + 8) =
         (float)(fVar16 * (float10)*(float *)(DAT_006a5cd0 + (DAT_004fc8f8 & uVar15) * 4) *
                 (float10)fVar4 + (float10)*(float *)(iVar12 + 8));
  }
  else {
    cVar10 = FUN_00417e90(*(int *)(param_1 + 0x24));
    iVar12 = DAT_0053be28;
    if (cVar10 == '\0') {
      iVar12 = (&DAT_005081bc)[*(int *)(param_1 + 0x24) * 0x1c];
    }
    iVar5 = *(int *)(iVar12 * 0xd0 + 0xc + DAT_0067ee20);
    iVar12 = DAT_006a5c38 + iVar5 + 0x50 + iVar5 * 0xa8;
    fVar6 = *(float *)(DAT_006a5c38 + iVar5 + 0x50 + iVar5 * 0xa8);
    fVar7 = *(float *)(iVar12 + 4);
    fVar8 = *(float *)(iVar12 + 8);
    pfVar14 = (float *)FUN_0044ff90();
    fVar1 = *pfVar14;
    fVar2 = pfVar14[1];
    fVar3 = pfVar14[2];
    if (*(int *)(iVar13 + 0xc) < 0) {
      FUN_004afee0(s_Invalid_chunkrange__d___s___d__004f1f44,*(int *)(iVar13 + 0xc),
                   s_D__work_rcsk_Code_game_Bon_shotb_004f1f18,0x186);
    }
    fVar9 = (float)(*(int *)(iVar13 + 0xc) + 1);
    iVar12 = FUN_004500c0();
    pfVar14 = (float *)FUN_004a23d0(auStack_c,DAT_006a5c38 + iVar12 * 0xa9 + 0x10);
    fVar1 = (fVar6 - fVar1) / fVar9 + *pfVar14;
    fVar6 = (fVar7 - fVar2) / fVar9 + pfVar14[1];
    fVar3 = (fVar8 - fVar3) / fVar9 + pfVar14[2];
    fVar2 = SQRT(fVar1 * fVar1 + fVar6 * fVar6 + fVar3 * fVar3);
    iVar12 = FUN_004500c0();
    FUN_004a2450(DAT_006a5c38 + iVar12 * 0xa9 + 0x10,fVar1 / fVar2,fVar6 / fVar2,fVar3 / fVar2);
    iVar12 = FUN_0044fff0();
    fVar16 = (float10)FUN_0048f4e0();
    iVar13 = FUN_004504f0();
    *(float *)(iVar12 + 8) = (float)iVar13 * (float)fVar16 + *(float *)(iVar12 + 8);
    pfVar14 = (float *)FUN_0044ff90();
    fVar16 = (float10)FUN_0048f4e0();
    *pfVar14 = (float)(fVar16 * (float10)(fVar1 / fVar2) * (float10)fVar4 + (float10)*pfVar14);
    iVar12 = FUN_0044ff90();
    fVar16 = (float10)FUN_0048f4e0();
    *(float *)(iVar12 + 8) =
         (float)(fVar16 * (float10)(fVar3 / fVar2) * (float10)fVar4 +
                (float10)*(float *)(iVar12 + 8));
  }
  uVar11 = FUN_004500d0();
  fVar16 = (float10)FUN_00430ff0(uVar11);
  fVar4 = *(float *)(param_1 + 0x3c);
  iVar12 = FUN_0044ff90();
  *(float *)(iVar12 + 4) = (float)(fVar16 + (float10)fVar4 + (float10)10.0);
  iVar12 = FUN_0044fb50();
  if ((iVar12 != 1) || (iVar12 = FUN_0044fbc0(), iVar12 != 3)) {
    if (*(char *)(param_1 + 0x2c) == '\x01') {
      iVar12 = FUN_0044ff90();
      if (_DAT_004f1eb4 < *(float *)(iVar12 + 4) - (float)*(int *)(param_1 + 0x28)) {
        uVar11 = FUN_004500d0();
        uVar11 = FUN_004500d0(uVar11);
        FUN_00481ec0(uVar11);
        FUN_00456440(1);
        return;
      }
    }
    else {
      FUN_0044ff90();
      uVar11 = __ftol();
      *(undefined4 *)(param_1 + 0x28) = uVar11;
      *(undefined1 *)(param_1 + 0x2c) = 1;
    }
  }
  return;
}

