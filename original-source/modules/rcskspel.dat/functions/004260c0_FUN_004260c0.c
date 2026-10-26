/*
 * FUN_004260c0 at 004260c0
 * undefined FUN_004260c0(void)
 * Address ranges: 004260c0-004264b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004260c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  float10 fVar16;
  
  iVar12 = param_1 * 0xd0;
  iVar1 = *(int *)(DAT_0067ee20 + iVar12 + 0xc);
  iVar9 = *(int *)(DAT_0067ee20 + iVar12 + 0x28) * 0xa9;
  iVar11 = *(int *)(*(int *)(*(int *)(*(int *)(iVar9 + 4 + DAT_006a5c38) * 9 + 4 + DAT_006a5f78) +
                            *(int *)(iVar9 + 8 + DAT_006a5c38) * 4) * 0x10 + DAT_006a5f30);
  iVar10 = FUN_00490ce0();
  iVar13 = iVar11 * 0xbc;
  if (*(int *)(iVar13 + 0x84 + DAT_006a5ee0) != 4) {
    FUN_004afee0(s__s__d____Object___d__has_a_shado_004e75fc,
                 s_D__work_rcsk_Code_game_gfx_shdw__004e75d8,0x7c,param_1,iVar11);
  }
  iVar11 = DAT_006a5ee0 + iVar10 * 0xbc;
  uVar2 = *(undefined4 *)(iVar11 + 0x54);
  uVar3 = *(undefined4 *)(iVar11 + 0x40);
  uVar4 = *(undefined4 *)(iVar11 + 0x48);
  uVar5 = *(undefined4 *)(iVar11 + 0x10);
  uVar6 = *(undefined4 *)(iVar11 + 0x18);
  uVar7 = *(undefined4 *)(iVar11 + 0x1c);
  uVar8 = *(undefined4 *)(iVar11 + 0x24);
  **(undefined4 **)(iVar13 + 0x80 + DAT_006a5ee0) = *(undefined4 *)(iVar11 + 0x4c);
  *(undefined4 *)(*(int *)(iVar13 + 0x80 + DAT_006a5ee0) + 8) = uVar2;
  *(undefined4 *)(*(int *)(iVar13 + 0x80 + DAT_006a5ee0) + 0x20) = uVar3;
  *(undefined4 *)(*(int *)(iVar13 + 0x80 + DAT_006a5ee0) + 0x28) = uVar4;
  *(undefined4 *)(*(int *)(iVar13 + 0x80 + DAT_006a5ee0) + 0x40) = uVar5;
  *(undefined4 *)(*(int *)(iVar13 + 0x80 + DAT_006a5ee0) + 0x48) = uVar6;
  *(undefined4 *)(*(int *)(iVar13 + 0x80 + DAT_006a5ee0) + 0x60) = uVar7;
  *(undefined4 *)(*(int *)(iVar13 + 0x80 + DAT_006a5ee0) + 0x68) = uVar8;
  iVar11 = *(int *)(DAT_0067ee20 + 0xc + iVar12) * 0xa9 + DAT_006a5c38;
  puVar14 = (undefined4 *)(iVar9 + 0x50 + DAT_006a5c38);
  *puVar14 = *(undefined4 *)(iVar11 + 0x50);
  puVar14[1] = *(undefined4 *)(iVar11 + 0x54);
  puVar14[2] = *(undefined4 *)(iVar11 + 0x58);
  iVar10 = *(int *)(DAT_0067ee20 + 0xc + iVar12);
  iVar11 = iVar9 + DAT_006a5c38;
  fVar16 = (float10)FUN_00494b70(*(undefined4 *)(DAT_006a5c38 + iVar10 + iVar10 * 0xa8 + 0x50),
                                 *(undefined4 *)(DAT_006a5c38 + iVar10 + 0x58 + iVar10 * 0xa8));
  *(float *)(iVar11 + 0x54) = (float)fVar16;
  *(float *)(iVar9 + 0x50 + DAT_006a5c38) = *(float *)(iVar9 + 0x50 + DAT_006a5c38) + 2.0;
  *(float *)(iVar9 + 0x58 + DAT_006a5c38) = *(float *)(iVar9 + 0x58 + DAT_006a5c38) + 2.0;
  *(undefined4 *)(iVar9 + 0x74 + DAT_006a5c38) = 0;
  *(undefined4 *)(iVar9 + 0x78 + DAT_006a5c38) =
       *(undefined4 *)(*(int *)(DAT_0067ee20 + 0xc + iVar12) * 0xa9 + DAT_006a5c38 + 0x78);
  *(undefined4 *)(iVar9 + 0x7c + DAT_006a5c38) = 0;
  puVar14 = (undefined4 *)(*(int *)(DAT_0067ee20 + 0xc + iVar12) * 0xa9 + DAT_006a5c38 + 0x10);
  puVar15 = (undefined4 *)(iVar9 + 0x10 + DAT_006a5c38);
  for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar15 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar15 = puVar15 + 1;
  }
  *(float *)(iVar9 + 0x40 + DAT_006a5c38) = *(float *)(iVar9 + 0x40 + DAT_006a5c38) + 2.0;
  iVar10 = *(int *)(DAT_0067ee20 + 0xc + iVar12);
  iVar11 = iVar9 + DAT_006a5c38;
  fVar16 = (float10)FUN_00494b70(*(undefined4 *)(DAT_006a5c38 + iVar10 + iVar10 * 0xa8 + 0x50),
                                 *(undefined4 *)(DAT_006a5c38 + iVar10 + 0x58 + iVar10 * 0xa8));
  *(float *)(iVar11 + 0x44) = (float)fVar16;
  *(float *)(iVar9 + 0x48 + DAT_006a5c38) = *(float *)(iVar9 + 0x48 + DAT_006a5c38) + 2.0;
  iVar1 = iVar1 * 0xa9;
  if (*(float *)(iVar1 + 0x54 + DAT_006a5c38) < *(float *)(iVar9 + 0x54 + DAT_006a5c38)) {
    *(undefined4 *)(iVar9 + 0x54 + DAT_006a5c38) = *(undefined4 *)(iVar1 + 0x54 + DAT_006a5c38);
    *(undefined4 *)(iVar9 + 0x44 + DAT_006a5c38) = *(undefined4 *)(iVar1 + 0x54 + DAT_006a5c38);
  }
  *(undefined4 *)(iVar9 + 0xa5 + DAT_006a5c38) = 1;
  if (DAT_0053ba60 != 0) {
    (**(code **)(*DAT_006a621c + 0x5c))
              (DAT_006a621c,0x13,
               *(undefined4 *)(&DAT_004fa400 + *(int *)(iVar9 + 0xa5 + DAT_006a5c38) * 8));
    (**(code **)(*DAT_006a621c + 0x5c))
              (DAT_006a621c,0x14,
               *(undefined4 *)(&DAT_004fa404 + *(int *)(iVar9 + 0xa5 + DAT_006a5c38) * 8));
  }
  FUN_004a0d80();
  return;
}

