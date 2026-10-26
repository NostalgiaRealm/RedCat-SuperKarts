/*
 * FUN_00499630 at 00499630
 * undefined FUN_00499630(void)
 * Address ranges: 00499630-004997e8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00499630(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar10 = param_1 * 0xd0;
  iVar6 = FUN_00490ce0();
  if (*(int *)(iVar10 + 0x44 + DAT_0067ee20) != 0) {
    if (199 < DAT_006847c8) {
      FUN_004afee0(s__s__d____Max_nb_of_bboxs_reached_004fb7c0,
                   s_D__work_rcsk_Code_Engine_Prog_Bb_004fb7e4,0x37);
    }
    iVar4 = DAT_006a5ee0;
    iVar5 = DAT_006847c8;
    iVar6 = iVar6 * 0xbc;
    iVar7 = DAT_006847c8 * 0x4c;
    puVar1 = (undefined4 *)(iVar6 + 0x10 + DAT_006a5ee0);
    *(undefined4 *)(&DAT_00680c68 + iVar7) = *puVar1;
    *(undefined4 *)(&DAT_00680c6c + iVar7) = puVar1[1];
    *(undefined4 *)(&DAT_00680c70 + iVar7) = puVar1[2];
    puVar1 = (undefined4 *)(iVar6 + 0x1c + iVar4);
    *(undefined4 *)(&DAT_00680c74 + iVar7) = *puVar1;
    *(undefined4 *)(&DAT_00680c78 + iVar7) = puVar1[1];
    *(undefined4 *)(&DAT_00680c7c + iVar7) = puVar1[2];
    puVar1 = (undefined4 *)(iVar6 + 0x4c + iVar4);
    puVar2 = (undefined4 *)(iVar6 + 0x40 + iVar4);
    *(undefined4 *)(&DAT_00680c80 + iVar7) = *puVar1;
    *(undefined4 *)(&DAT_00680c84 + iVar7) = puVar1[1];
    iVar4 = DAT_0067ee20;
    *(undefined4 *)(&DAT_00680c88 + iVar7) = puVar1[2];
    *(undefined4 *)(&DAT_00680c8c + iVar7) = *puVar2;
    *(undefined4 *)(&DAT_00680c90 + iVar7) = puVar2[1];
    iVar9 = DAT_006a5c38;
    *(undefined4 *)(&DAT_00680c94 + iVar7) = puVar2[2];
    iVar11 = *(int *)(iVar10 + 0xc + iVar4) * 0xa9 + iVar9;
    *(undefined4 *)(&DAT_00680c98 + iVar7) = *(undefined4 *)(iVar11 + 0x50);
    *(undefined4 *)(&DAT_00680c9c + iVar7) = *(undefined4 *)(iVar11 + 0x54);
    *(undefined4 *)(&DAT_00680ca0 + iVar7) = *(undefined4 *)(iVar11 + 0x58);
    iVar10 = *(int *)(iVar10 + 0xc + iVar4);
    iVar9 = iVar9 + iVar10;
    pfVar3 = (float *)(iVar9 + 0x78 + iVar10 * 0xa8);
    if (*(float *)(iVar9 + 0x78 + iVar10 * 0xa8) <= 0.0) {
      FUN_004c062b((double)*pfVar3);
    }
    else {
      FUN_004c06fa((double)*pfVar3);
    }
    uVar8 = __ftol();
    iVar10 = DAT_006a5ee0;
    (&DAT_00680cac)[iVar5 * 0x13] = uVar8;
    DAT_006847c8 = DAT_006847c8 + 1;
    *(float *)(&DAT_00680ca4 + iVar5 * 0x4c) = *(float *)(iVar6 + 0x74 + iVar10) + 4.0;
    (&DAT_00680ca8)[iVar5 * 0x13] = param_1;
    *(undefined4 *)(&DAT_00680cb0 + iVar5 * 0x4c) = 1;
  }
  return;
}

