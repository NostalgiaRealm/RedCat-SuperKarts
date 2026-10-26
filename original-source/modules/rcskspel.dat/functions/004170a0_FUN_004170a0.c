/*
 * FUN_004170a0 at 004170a0
 * undefined FUN_004170a0(void)
 * Address ranges: 004170a0-004175bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004170a0(int param_1)

{
  int iVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  undefined4 *puVar9;
  float10 fVar10;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  undefined1 auStack_80 [4];
  float fStack_7c;
  float fStack_78;
  int iStack_74;
  float afStack_70 [6];
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  float fStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  float fStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  float fStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  float fStack_8;
  undefined1 auStack_4 [4];
  
  param_1 = param_1 * 0xd0;
  iVar6 = FUN_00490ce0();
  iVar6 = DAT_006a5ee0 + iVar6 * 0xbc;
  uStack_34 = *(undefined4 *)(iVar6 + 0x10);
  uStack_30 = *(undefined4 *)(iVar6 + 0x14);
  fStack_2c = *(float *)(iVar6 + 0x60) + 13.0;
  uStack_28 = *(undefined4 *)(iVar6 + 0x58);
  uStack_24 = *(undefined4 *)(iVar6 + 0x14);
  fStack_20 = *(float *)(iVar6 + 0x60) + 13.0;
  uStack_1c = *(undefined4 *)(iVar6 + 0x10);
  uStack_18 = *(undefined4 *)(iVar6 + 0x14);
  fStack_14 = *(float *)(iVar6 + 0x18) - 13.0;
  uStack_10 = *(undefined4 *)(iVar6 + 0x58);
  uStack_c = *(undefined4 *)(iVar6 + 0x14);
  fStack_8 = *(float *)(iVar6 + 0x18) - 13.0;
  iVar6 = 0;
  iStack_74 = *(int *)(DAT_0067ee20 + 0xc + param_1) * 0xa9;
  do {
    pfVar8 = (float *)((int)afStack_70 + iVar6);
    pfVar7 = (float *)FUN_004a25f0(auStack_80,(int)&uStack_34 + iVar6,
                                   iStack_74 + 0x10 + DAT_006a5c38);
    *pfVar8 = *pfVar7;
    fVar2 = pfVar7[2];
    *(float *)((int)afStack_70 + iVar6 + 4) = pfVar7[1];
    *(float *)((int)afStack_70 + iVar6 + 8) = fVar2;
    iVar3 = *(int *)(DAT_0067ee20 + 0xc + param_1);
    uVar4 = *(undefined4 *)(DAT_0067ee20 + 0x1c + param_1);
    iVar1 = DAT_006a5c38 + iVar3 + 0x50 + iVar3 * 0xa8;
    *pfVar8 = *(float *)(DAT_006a5c38 + iVar3 + 0x50 + iVar3 * 0xa8) + *pfVar8;
    *(float *)((int)afStack_70 + iVar6 + 4) =
         *(float *)(iVar1 + 4) + *(float *)((int)afStack_70 + iVar6 + 4);
    *(float *)((int)afStack_70 + iVar6 + 8) =
         *(float *)(iVar1 + 8) + *(float *)((int)afStack_70 + iVar6 + 8);
    FUN_004977d0(uVar4,*pfVar8,*(undefined4 *)((int)afStack_70 + iVar6 + 4),
                 *(undefined4 *)((int)afStack_70 + iVar6 + 8));
    FUN_00495fe0(*pfVar8,*(undefined4 *)((int)afStack_70 + iVar6 + 4),
                 *(undefined4 *)((int)afStack_70 + iVar6 + 8),auStack_4,&uStack_3c,&uStack_40);
    fVar10 = (float10)FUN_00496290(*pfVar8,*(undefined4 *)((int)afStack_70 + iVar6 + 4),
                                   *(undefined4 *)((int)afStack_70 + iVar6 + 8),uStack_3c,uStack_40)
    ;
    *(float *)((int)afStack_70 + iVar6 + 4) = (float)fVar10;
    iVar6 = iVar6 + 0xc;
  } while (iVar6 < 0x30);
  *(float *)(DAT_006a5c38 + *(int *)(DAT_0067ee20 + 0xc + param_1) * 0xa9 + 0x54) =
       fStack_48 + fStack_54 + afStack_70[4] + afStack_70[1];
  iVar6 = *(int *)(DAT_0067ee20 + 0xc + param_1);
  *(float *)(DAT_006a5c38 + iVar6 + 0x54 + iVar6 * 0xa8) =
       *(float *)(DAT_006a5c38 + iVar6 + 0x54 + iVar6 * 0xa8) * 0.25;
  fStack_a4 = (afStack_70[3] - fStack_4c) + (afStack_70[0] - fStack_58);
  fStack_a0 = (afStack_70[4] - fStack_48) + (afStack_70[1] - fStack_54);
  fStack_9c = (afStack_70[5] - fStack_44) + (afStack_70[2] - fStack_50);
  fStack_7c = fStack_48 - fStack_54;
  fStack_78 = fStack_44 - fStack_50;
  fStack_b0 = (fStack_4c - fStack_58) + (afStack_70[3] - afStack_70[0]);
  fStack_ac = fStack_7c + (afStack_70[4] - afStack_70[1]);
  fStack_a8 = fStack_78 + (afStack_70[5] - afStack_70[2]);
  fStack_98 = fStack_a0 * fStack_a8 - fStack_9c * fStack_ac;
  fStack_94 = fStack_9c * fStack_b0 - fStack_a4 * fStack_a8;
  fStack_90 = fStack_a4 * fStack_ac - fStack_a0 * fStack_b0;
  fStack_8c = fStack_98;
  fStack_88 = fStack_94;
  fStack_84 = fStack_90;
  fVar10 = (float10)FUN_00405f40(&fStack_a4);
  fStack_38 = (float)SQRT(fVar10);
  pfVar8 = (float *)FUN_004175f0(auStack_80,&fStack_a4,fStack_38);
  fStack_a4 = *pfVar8;
  fStack_a0 = pfVar8[1];
  fStack_9c = pfVar8[2];
  fVar10 = (float10)FUN_00405f40(&fStack_8c);
  fVar10 = SQRT(fVar10);
  pfVar8 = (float *)FUN_00405f20((float)((float10)fStack_8c / fVar10),
                                 (float)((float10)fStack_88 / fVar10),
                                 (float)((float10)fStack_84 / fVar10));
  fStack_8c = *pfVar8;
  fStack_88 = pfVar8[1];
  fStack_84 = pfVar8[2];
  fVar10 = (float10)FUN_00405f40(&fStack_b0);
  fVar10 = SQRT(fVar10);
  puVar9 = (undefined4 *)
           FUN_00405f20((float)((float10)fStack_b0 / fVar10),(float)((float10)fStack_ac / fVar10),
                        (float)((float10)fStack_a8 / fVar10));
  uVar4 = puVar9[1];
  uVar5 = puVar9[2];
  *(undefined4 *)(iStack_74 + 0x10 + DAT_006a5c38) = *puVar9;
  *(undefined4 *)(iStack_74 + 0x14 + DAT_006a5c38) = uVar4;
  *(undefined4 *)(iStack_74 + 0x18 + DAT_006a5c38) = uVar5;
  *(float *)(iStack_74 + 0x20 + DAT_006a5c38) = fStack_8c;
  *(float *)(iStack_74 + 0x24 + DAT_006a5c38) = fStack_88;
  *(float *)(iStack_74 + 0x28 + DAT_006a5c38) = fStack_84;
  *(float *)(iStack_74 + 0x30 + DAT_006a5c38) = fStack_a4;
  *(float *)(iStack_74 + 0x34 + DAT_006a5c38) = fStack_a0;
  *(float *)(iStack_74 + 0x38 + DAT_006a5c38) = fStack_9c;
  return 0;
}

