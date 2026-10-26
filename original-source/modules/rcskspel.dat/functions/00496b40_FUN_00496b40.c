/*
 * FUN_00496b40 at 00496b40
 * undefined FUN_00496b40(void)
 * Address ranges: 00496b40-0049706d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00496b40(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  uint uStack_24;
  int iStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (((*(int *)(param_1 + 0x4a) == -1) || (*(int *)(param_1 + 0x4e) == -1)) ||
     (*(int *)(param_1 + 0x52) == -1)) {
    FUN_004afee0(s__s__d____Textures_not_set__Canno_004fb204,
                 s_D__work_rcsk_Code_Engine_Prog_Rd_004fb234,0x140);
  }
  iVar3 = FUN_004b96d0(param_2);
  iVar4 = FUN_004b96d0(param_3);
  if (iVar3 == 0) {
    FUN_004afee0(s__s__d____File_open_failed_for_fi_004face0,
                 s_D__work_rcsk_Code_Engine_Prog_Rd_004fb234,0x14a,param_2);
  }
  if (iVar4 == 0) {
    FUN_004afee0(s__s__d_____s___s_____File_open_fa_004fb1d0,
                 s_D__work_rcsk_Code_Engine_Prog_Rd_004fb234,0x14f,param_3);
  }
  FUN_004bf930(&DAT_00680b74,4,1,iVar4);
  if (DAT_00680b74 < 0) {
    FUN_004bf930(&iStack_20,4,1,iVar4);
  }
  else {
    iStack_20 = DAT_00680b74;
  }
  FUN_004bf930(&uStack_1c,4,1,iVar4);
  FUN_004bf930(&uStack_24,4,1,iVar3);
  if (uStack_1c != uStack_24) {
    FUN_004afee0(s__s__d____Data_chunk_count_does_n_004fb17c,
                 s_D__work_rcsk_Code_Engine_Prog_Rd_004fb234,0x162,uStack_1c,uStack_24);
  }
  FUN_004afce0(s_m_chunks_alloc__d_004fb168,uStack_24);
  uVar2 = uStack_24;
  piVar1 = (int *)(param_1 + 4);
  iVar12 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00405f70();
  }
  if ((int)uVar2 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0x107,param_1 + 0x31,param_1 + 0x18,
                 uVar2);
  }
  pvVar5 = operator_new(uVar2 * 4);
  *piVar1 = (int)pvVar5;
  *(uint *)(param_1 + 8) = uVar2;
  *(undefined4 *)(param_1 + 0xc) = 0;
  pvVar5 = operator_new(uVar2);
  *(void **)(param_1 + 0x14) = pvVar5;
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,param_1 + 0x31,param_1 + 0x18,
               *(undefined4 *)(param_1 + 8));
  iVar6 = 0;
  *(undefined4 *)(param_1 + 0x10) = 1;
  if (0 < (int)uVar2) {
    do {
      iVar6 = iVar6 + 1;
      *(undefined1 *)(*(int *)(param_1 + 0x14) + -1 + iVar6) = 0;
    } while (iVar6 < (int)uVar2);
  }
  FUN_004964e0(uStack_24 << 4,uStack_24 * 0x18,uStack_24 * 0xc,uStack_24 * 0xc);
  FUN_00494760(uStack_24);
  if ((int)uStack_24 < 1) {
LAB_00496dc7:
    FUN_00424ec0();
    iVar12 = 0;
    if (uStack_24 != 1 && -1 < (int)(uStack_24 - 1)) {
      do {
        iVar6 = *piVar1;
        if (iVar12 == 0) {
          iVar10 = *(int *)(iVar6 + -4 + uStack_24 * 4);
        }
        else {
          iVar10 = *(int *)(iVar6 + -4 + iVar12 * 4);
        }
        puVar11 = (undefined4 *)(DAT_00680b28 + 0x24 + iVar10 * 0x984);
        uStack_18 = *puVar11;
        uStack_14 = puVar11[1];
        uStack_10 = puVar11[2];
        iVar10 = *(int *)(iVar6 + 4 + iVar12 * 4);
        iVar6 = DAT_00680b28 + 0x24 + iVar10 * 0x984;
        uStack_c = *(undefined4 *)(DAT_00680b28 + 0x24 + iVar10 * 0x984);
        uStack_8 = *(undefined4 *)(iVar6 + 4);
        uStack_4 = *(undefined4 *)(iVar6 + 8);
        FUN_00495cb0(&uStack_18,&uStack_c);
        FUN_00494b90();
        iVar12 = iVar12 + 1;
      } while (iVar12 < (int)(uStack_24 - 1));
    }
    iVar6 = DAT_00680b28 + iVar12 * 0x984;
    uStack_18 = *(undefined4 *)(iVar6 + -0x960);
    uStack_14 = *(undefined4 *)(iVar6 + -0x95c);
    uStack_10 = *(undefined4 *)(iVar6 + -0x958);
    puVar11 = (undefined4 *)(DAT_00680b28 + 0x24 + *(int *)*piVar1 * 0x984);
    uStack_c = *puVar11;
    uStack_8 = puVar11[1];
    uStack_4 = puVar11[2];
    FUN_00495cb0(&uStack_18,&uStack_c);
    FUN_00494b90();
    puVar11 = (undefined4 *)(DAT_00680b28 + 0x5c + *(int *)(*piVar1 + -4 + iVar12 * 4) * 0x984);
    puVar13 = (undefined4 *)(DAT_00680b28 + 0x5c + *(int *)(*piVar1 + iVar12 * 4) * 0x984);
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar13 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar13 = puVar13 + 1;
    }
    *(undefined4 *)(DAT_00680b28 + 0xdc + *(int *)(*piVar1 + iVar12 * 4) * 0x984) =
         *(undefined4 *)(DAT_00680b28 + 0xdc + *(int *)(*piVar1 + -4 + iVar12 * 4) * 0x984);
    puVar11 = (undefined4 *)(DAT_00680b28 + 0x30 + *(int *)(*piVar1 + -4 + iVar12 * 4) * 0x984);
    puVar13 = (undefined4 *)(DAT_00680b28 + 0x30 + *(int *)(*piVar1 + iVar12 * 4) * 0x984);
    *puVar13 = *puVar11;
    puVar13[1] = puVar11[1];
    puVar13[2] = puVar11[2];
    puVar11 = (undefined4 *)(DAT_00680b28 + 0x3c + *(int *)(*piVar1 + -4 + iVar12 * 4) * 0x984);
    puVar13 = (undefined4 *)(DAT_00680b28 + 0x3c + *(int *)(*piVar1 + iVar12 * 4) * 0x984);
    *puVar13 = *puVar11;
    puVar13[1] = puVar11[1];
    puVar13[2] = puVar11[2];
    puVar11 = (undefined4 *)(DAT_00680b28 + 0x48 + *(int *)(*piVar1 + -4 + iVar12 * 4) * 0x984);
    puVar13 = (undefined4 *)(DAT_00680b28 + 0x48 + *(int *)(*piVar1 + iVar12 * 4) * 0x984);
    *puVar13 = *puVar11;
    puVar13[1] = puVar11[1];
    puVar13[2] = puVar11[2];
    FUN_00424ec0();
    FUN_004b9840(iVar3);
    FUN_004b9840(iVar4);
    return;
  }
LAB_00496d24:
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0xb9,param_1 + 0x18,
                 *(undefined4 *)(param_1 + 8),param_1 + 0x31);
  }
  iVar6 = *(int *)(param_1 + 0xc);
  iVar10 = *(int *)(param_1 + 8);
  if (iVar6 < iVar10) {
    iVar9 = *(int *)(param_1 + 0x14);
    iVar7 = iVar6;
    do {
      if (*(char *)(iVar9 + iVar7) == '\0') goto LAB_00496dea;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar6) {
    iVar9 = *(int *)(param_1 + 0x14);
    do {
      if (*(char *)(iVar9 + iVar7) == '\0') goto LAB_00496dea;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar6);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,
               s_______Libs_Win3DLib_Include_arra_004fa4c0,0xce,param_1 + 0x18,iVar10,param_1 + 0x31
              );
  goto LAB_00496da0;
LAB_00496dea:
  *(undefined1 *)(iVar9 + iVar7) = 1;
  *(int *)(param_1 + 0xc) = iVar7;
LAB_00496da0:
  iVar6 = *piVar1;
  uVar8 = FUN_004948c0(iVar3,iVar4);
  *(undefined4 *)(iVar6 + iVar12 * 4) = uVar8;
  iVar12 = iVar12 + 1;
  if ((int)uStack_24 <= iVar12) goto LAB_00496dc7;
  goto LAB_00496d24;
}

