/*
 * FUN_0041c0b0 at 0041c0b0
 * undefined FUN_0041c0b0(void)
 * Address ranges: 0041c0b0-0041c4a3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041c0b0(float param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  iVar7 = (int)param_1 * 0xd0;
  iVar3 = FUN_004906b0(0);
  fVar2 = ABS(*(float *)(DAT_006a5ee0 + 0x14 +
                        *(int *)(*(int *)(*(int *)(*(int *)(DAT_006a5c38 + iVar3 * 0xa9 + 4) * 9 + 4
                                                  + DAT_006a5f78) + 4) * 0x10 + DAT_006a5f30) * 0xbc
                        ));
  iVar3 = iVar7 + DAT_0067ee20;
  fVar8 = (float10)FUN_0048f4e0();
  fVar9 = (float10)fVar2;
  fVar1 = (float)(((float10)_DAT_004fc8f4 / (fVar9 + fVar9)) * fVar8 *
                 (float10)*(float *)(iVar3 + 0xa4));
  iVar3 = FUN_004906b0(0);
  *(float *)(DAT_006a5c38 + iVar3 + 0x74 + iVar3 * 0xa8) =
       *(float *)(DAT_006a5c38 + iVar3 + 0x74 + iVar3 * 0xa8) - fVar1;
  iVar3 = FUN_004906b0(1);
  *(float *)(DAT_006a5c38 + iVar3 + 0x74 + iVar3 * 0xa8) =
       *(float *)(DAT_006a5c38 + iVar3 + 0x74 + iVar3 * 0xa8) - fVar1;
  iVar3 = FUN_004906b0(2);
  pfVar5 = (float *)(DAT_006a5c38 + iVar3 * 0xa9 + 0x74);
  *pfVar5 = *pfVar5 - fVar1;
  iVar3 = FUN_004906b0(3);
  *(float *)(DAT_006a5c38 + iVar3 + 0x74 + iVar3 * 0xa8) =
       *(float *)(DAT_006a5c38 + iVar3 + 0x74 + iVar3 * 0xa8) - fVar1;
  iVar3 = FUN_004906b0(0);
  *(float *)(DAT_006a5c38 + iVar3 * 0xa9 + 0x78) =
       _DAT_004fc8f4 * 0.083333336 * -0.01 * _DAT_0053bd70;
  iVar3 = FUN_004906b0(1);
  iVar6 = 0;
  *(float *)(DAT_006a5c38 + iVar3 * 0xa9 + 0x78) =
       _DAT_004fc8f4 * 0.083333336 * -0.01 * _DAT_0053bd70;
  iVar3 = *(int *)(iVar7 + 0xc + DAT_0067ee20);
  do {
    iVar4 = FUN_004906b0(iVar6);
    iVar4 = iVar4 * 0xa9 + DAT_006a5c38;
    local_18 = *(float *)(iVar4 + 0x50);
    local_10 = *(float *)(iVar4 + 0x58);
    local_14 = 0.0;
    pfVar5 = (float *)FUN_004a25f0(local_c,&local_18,DAT_006a5c38 + iVar3 * 0xa9 + 0x10);
    iVar4 = *(int *)(iVar7 + 0xc + DAT_0067ee20);
    local_18 = *pfVar5 + *(float *)(DAT_006a5c38 + iVar4 + 0x50 + iVar4 * 0xa8);
    iVar4 = DAT_006a5c38 + iVar4 + 0x50 + iVar4 * 0xa8;
    local_14 = pfVar5[1] + *(float *)(iVar4 + 4);
    local_10 = pfVar5[2] + *(float *)(iVar4 + 8);
    FUN_004977d0(*(undefined4 *)(iVar7 + 0x1c + DAT_0067ee20),local_18,local_14,local_10);
    FUN_00495fe0(local_18,local_14,local_10,local_1c,&local_20,&local_24);
    fVar8 = (float10)FUN_00496290(local_18,local_14,local_10,local_20,local_24);
    param_1 = (float)(fVar8 - (float10)local_14);
    if (fVar8 - (float10)local_14 <= (float10)0.5) {
      if (param_1 < -1.11) {
        param_1 = -1.11;
      }
    }
    else {
      param_1 = 0.5;
    }
    iVar4 = FUN_004906b0(iVar6);
    *(float *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x54) = param_1 + fVar2;
    FUN_004906b0(iVar6);
    FUN_004a09e0();
    iVar6 = iVar6 + 1;
  } while (iVar6 < 4);
  return;
}

