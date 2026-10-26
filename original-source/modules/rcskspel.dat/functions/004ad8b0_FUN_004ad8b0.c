/*
 * FUN_004ad8b0 at 004ad8b0
 * undefined FUN_004ad8b0(void)
 * Address ranges: 004ad8b0-004ae485
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004ad8b0(undefined4 *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  
  if (param_2[3] == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,s___array_hpp_004fc894,0xb9,param_2 + 5
                 ,param_2[1],(int)param_2 + 0x2d);
  }
  iVar3 = param_2[2];
  iVar12 = param_2[1];
  if (iVar3 < iVar12) {
    iVar4 = param_2[4];
    iVar8 = iVar3;
    do {
      if (*(char *)(iVar4 + iVar8) == '\0') goto LAB_004ad93f;
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar12);
  }
  iVar8 = 0;
  if (0 < iVar3) {
    iVar4 = param_2[4];
    do {
      if (*(char *)(iVar4 + iVar8) == '\0') goto LAB_004ad93f;
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar3);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,s___array_hpp_004fc894,0xce,param_2 + 5,
               iVar12,(int)param_2 + 0x2d);
  return 0;
LAB_004ad93f:
  *(undefined1 *)(iVar4 + iVar8) = 1;
  param_2[2] = iVar8;
  if (iVar8 == -1) {
    return 0;
  }
  iVar3 = *(int *)((int)param_2 + 0x5a);
  if (iVar3 != 0) {
    if (param_2[3] == 0) {
      FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                   param_2 + 5,param_2[1],(int)param_2 + 0x2d);
    }
    if ((iVar8 < 0) || (param_2[1] <= iVar8)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                   param_2 + 5,iVar8,param_2[1]);
    }
    if (*(char *)(param_2[4] + iVar8) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                   param_2 + 5,iVar8);
    }
    *(int *)(iVar8 * 0xb0 + 0xa8 + *param_2) = iVar3;
    iVar3 = *(int *)((int)param_2 + 0x5a);
    if (param_2[3] == 0) {
      FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                   param_2 + 5,param_2[1],(int)param_2 + 0x2d);
    }
    if ((iVar3 < 0) || (param_2[1] <= iVar3)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                   param_2 + 5,iVar3,param_2[1]);
    }
    if (*(char *)(param_2[4] + iVar3) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                   param_2 + 5,iVar3);
    }
    *(int *)(iVar3 * 0xb0 + 0xa4 + *param_2) = iVar8;
  }
  if (param_2[3] == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                 param_2 + 5,param_2[1],(int)param_2 + 0x2d);
  }
  if ((iVar8 < 0) || (param_2[1] <= iVar8)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                 param_2 + 5,iVar8,param_2[1]);
  }
  if (*(char *)(param_2[4] + iVar8) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                 param_2 + 5,iVar8);
  }
  iVar12 = iVar8 * 0xb0;
  puVar9 = param_1;
  puVar13 = (undefined4 *)(iVar12 + *param_2);
  for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar13 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar13 = puVar13 + 1;
  }
  if ((param_1[0x13] & 0x20) == 0) {
    if ((param_1[0x13] & 8) == 0) {
      if (param_1[0x15] != 0x10) {
        FUN_004afce0(s_THIS_IS_NOT_A_16_bit_RGB_PIXELFO_004fe358,param_1[0x15]);
      }
      iVar3 = 0;
      for (uVar1 = param_1[0x16]; (uVar1 & 1) == 0; uVar1 = uVar1 >> 1) {
        iVar3 = iVar3 + 1;
      }
      iVar4 = 0;
      for (; (uVar1 & 1) != 0; uVar1 = uVar1 >> 1) {
        iVar4 = iVar4 + 1;
      }
      iVar5 = 0;
      for (uVar1 = param_1[0x17]; (uVar1 & 1) == 0; uVar1 = uVar1 >> 1) {
        iVar5 = iVar5 + 1;
      }
      iVar6 = 0;
      for (; (uVar1 & 1) != 0; uVar1 = uVar1 >> 1) {
        iVar6 = iVar6 + 1;
      }
      iVar7 = 0;
      for (uVar1 = param_1[0x18]; (uVar1 & 1) == 0; uVar1 = uVar1 >> 1) {
        iVar7 = iVar7 + 1;
      }
      iVar10 = 0;
      for (; (uVar1 & 1) != 0; uVar1 = uVar1 >> 1) {
        iVar10 = iVar10 + 1;
      }
      if (param_2[3] == 0) {
        FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                     param_2 + 5,param_2[1],(int)param_2 + 0x2d);
      }
      if ((iVar8 < 0) || (param_2[1] <= iVar8)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                     param_2 + 5,iVar8,param_2[1]);
      }
      if (*(char *)(param_2[4] + iVar8) == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                     param_2 + 5,iVar8);
      }
      *(int *)(iVar12 + 0x84 + *param_2) = iVar3;
      if (param_2[3] == 0) {
        FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                     param_2 + 5,param_2[1],(int)param_2 + 0x2d);
      }
      if ((iVar8 < 0) || (param_2[1] <= iVar8)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                     param_2 + 5,iVar8,param_2[1]);
      }
      if (*(char *)(param_2[4] + iVar8) == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                     param_2 + 5,iVar8);
      }
      *(int *)(iVar12 + 0x88 + *param_2) = iVar5;
      if (param_2[3] == 0) {
        FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                     param_2 + 5,param_2[1],(int)param_2 + 0x2d);
      }
      if ((iVar8 < 0) || (param_2[1] <= iVar8)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                     param_2 + 5,iVar8,param_2[1]);
      }
      if (*(char *)(param_2[4] + iVar8) == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                     param_2 + 5,iVar8);
      }
      *(int *)(iVar12 + 0x8c + *param_2) = iVar7;
      if (param_2[3] == 0) {
        FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                     param_2 + 5,param_2[1],(int)param_2 + 0x2d);
      }
      if ((iVar8 < 0) || (param_2[1] <= iVar8)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                     param_2 + 5,iVar8,param_2[1]);
      }
      if (*(char *)(param_2[4] + iVar8) == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                     param_2 + 5,iVar8);
      }
      *(int *)(iVar12 + 0x94 + *param_2) = iVar4;
      if (param_2[3] == 0) {
        FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                     param_2 + 5,param_2[1],(int)param_2 + 0x2d);
      }
      if ((iVar8 < 0) || (param_2[1] <= iVar8)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                     param_2 + 5,iVar8,param_2[1]);
      }
      if (*(char *)(param_2[4] + iVar8) == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                     param_2 + 5,iVar8);
      }
      *(int *)(iVar12 + 0x98 + *param_2) = iVar6;
      if (param_2[3] == 0) {
        FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                     param_2 + 5,param_2[1],(int)param_2 + 0x2d);
      }
      if ((iVar8 < 0) || (param_2[1] <= iVar8)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                     param_2 + 5,iVar8,param_2[1]);
      }
      if (*(char *)(param_2[4] + iVar8) == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                     param_2 + 5,iVar8);
      }
      *(int *)(iVar12 + 0x9c + *param_2) = iVar10;
      if (param_2[3] == 0) {
        FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                     param_2 + 5,param_2[1],(int)param_2 + 0x2d);
      }
      if ((iVar8 < 0) || (param_2[1] <= iVar8)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                     param_2 + 5,iVar8,param_2[1]);
      }
      if (*(char *)(param_2[4] + iVar8) == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                     param_2 + 5,iVar8);
      }
      *(int *)(iVar12 + 0x74 + *param_2) = 8 - iVar4;
      iVar12 = FUN_004ae680(iVar8);
      *(int *)(iVar12 + 0x78) = 8 - iVar6;
      iVar12 = FUN_004ae680(iVar8);
      *(int *)(iVar12 + 0x7c) = 8 - iVar10;
      if ((*(byte *)(param_1 + 0x13) & 1) != 0) {
        iVar12 = 0;
        for (uVar1 = param_1[0x19]; (uVar1 & 1) == 0; uVar1 = uVar1 >> 1) {
          iVar12 = iVar12 + 1;
        }
        iVar11 = 0;
        for (; (uVar1 & 1) != 0; uVar1 = uVar1 >> 1) {
          iVar11 = iVar11 + 1;
        }
        iVar2 = FUN_004ae680(iVar8);
        *(int *)(iVar2 + 0x90) = iVar12;
        iVar2 = FUN_004ae680(iVar8);
        *(int *)(iVar2 + 0xa0) = iVar11;
        iVar2 = FUN_004ae680(iVar8);
        *(int *)(iVar2 + 0x80) = 8 - iVar11;
        FUN_004afce0(s_TXFORMAT___ALPHA_texture_format___004fe2f4,iVar8,iVar4,iVar6,iVar10,iVar11,
                     iVar3,iVar5,iVar7,iVar12,DAT_006ab7ec,DAT_006ab7f0,DAT_006ab7f4,DAT_006ab81c,
                     DAT_006ab820,DAT_006ab824);
        iVar2 = FUN_004ae680(iVar8);
        *(undefined4 *)(iVar2 + 0x6c) = 4;
        iVar2 = FUN_004ae680(iVar8);
        *(undefined4 *)(iVar2 + 0x70) = 0x10;
        if ((*(int *)((int)param_2 + 0x4e) != -1) &&
           (iVar2 = FUN_004ae720(*(int *)((int)param_2 + 0x4e)), iVar11 <= *(int *)(iVar2 + 0xa0)))
        {
          return 1;
        }
        *(int *)((int)param_2 + 0x4e) = iVar8;
        FUN_004afce0(s_TXFORMAT___Selected_ALPHA_textur_004fe288,iVar8,iVar4,iVar6,iVar10,iVar11,
                     iVar3,iVar5,iVar7,iVar12,DAT_006ab7ec,DAT_006ab7f0,DAT_006ab7f4,DAT_006ab81c,
                     DAT_006ab820,DAT_006ab824);
        return 1;
      }
      FUN_004afce0(s_TXFORMAT___texture_format__d__rg_004fe230,iVar8,iVar4,iVar6,iVar10,iVar3,iVar5,
                   iVar7,DAT_006ab7ec,DAT_006ab7f0,DAT_006ab7f4,DAT_006ab81c,DAT_006ab820,
                   DAT_006ab824);
      iVar12 = FUN_004ae680(iVar8);
      *(undefined4 *)(iVar12 + 0x6c) = 3;
      iVar12 = FUN_004ae680(iVar8);
      *(undefined4 *)(iVar12 + 0x70) = 0x10;
      iVar12 = *(int *)((int)param_2 + 0x52);
      iVar4 = iVar10 + iVar6 + iVar4;
      iVar6 = DAT_006ab7ec + DAT_006ab7f0 + DAT_006ab7f4;
      if (iVar12 == -1) {
        if (iVar6 < iVar4) goto LAB_004ae46a;
      }
      else {
        iVar10 = FUN_004ae720(iVar12);
        iVar11 = FUN_004ae720(iVar12);
        iVar10 = *(int *)(iVar10 + 0x9c);
        iVar11 = *(int *)(iVar11 + 0x94);
        iVar12 = FUN_004ae720(iVar12);
        if ((((iVar6 < iVar4) || (DAT_006ab81c != iVar3)) || (DAT_006ab820 != iVar5)) ||
           ((DAT_006ab824 != iVar7 ||
            (iVar6 - (iVar10 + iVar11 + *(int *)(iVar12 + 0x98)) < iVar6 - iVar4))))
        goto LAB_004ae46a;
      }
      FUN_004afce0(s_TXFORMAT___using_this_texture_fo_004fe200);
      *(int *)((int)param_2 + 0x52) = iVar8;
    }
    else {
      FUN_004afce0(s_TXFORMAT___texture_format__d__4b_004fe38c,iVar8);
      if (param_2[3] == 0) {
        FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                     param_2 + 5,param_2[1],(int)param_2 + 0x2d);
      }
      if ((iVar8 < 0) || (param_2[1] <= iVar8)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                     param_2 + 5,iVar8,param_2[1]);
      }
      if (*(char *)(param_2[4] + iVar8) == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                     param_2 + 5,iVar8);
      }
      *(undefined4 *)(iVar12 + 0x6c + *param_2) = 1;
      if (param_2[3] == 0) {
        FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                     param_2 + 5,param_2[1],(int)param_2 + 0x2d);
      }
      if ((iVar8 < 0) || (param_2[1] <= iVar8)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                     param_2 + 5,iVar8,param_2[1]);
      }
      if (*(char *)(param_2[4] + iVar8) == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                     param_2 + 5,iVar8);
      }
      *(undefined4 *)(iVar12 + 0x70 + *param_2) = 4;
      *(int *)((int)param_2 + 0x46) = iVar8;
    }
  }
  else {
    FUN_004afce0(s_TXFORMAT___texture_format__d__8b_004fe3bc,iVar8);
    if (param_2[3] == 0) {
      FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                   param_2 + 5,param_2[1],(int)param_2 + 0x2d);
    }
    if ((iVar8 < 0) || (param_2[1] <= iVar8)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                   param_2 + 5,iVar8,param_2[1]);
    }
    if (*(char *)(param_2[4] + iVar8) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                   param_2 + 5,iVar8);
    }
    *(undefined4 *)(iVar12 + 0x6c + *param_2) = 2;
    if (param_2[3] == 0) {
      FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1c4,
                   param_2 + 5,param_2[1],(int)param_2 + 0x2d);
    }
    if ((iVar8 < 0) || (param_2[1] <= iVar8)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1c8,
                   param_2 + 5,iVar8,param_2[1]);
    }
    if (*(char *)(param_2[4] + iVar8) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1cc,
                   param_2 + 5,iVar8);
    }
    *(undefined4 *)(iVar12 + 0x70 + *param_2) = 8;
    *(int *)((int)param_2 + 0x4a) = iVar8;
  }
LAB_004ae46a:
  if (*(int *)((int)param_2 + 0x5e) == 0) {
    *(int *)((int)param_2 + 0x5e) = iVar8;
  }
  *(int *)((int)param_2 + 0x5a) = iVar8;
  return 1;
}

