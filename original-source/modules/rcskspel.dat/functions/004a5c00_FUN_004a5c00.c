/*
 * FUN_004a5c00 at 004a5c00
 * undefined FUN_004a5c00(void)
 * Address ranges: 004a5c00-004a6058
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004a5c00(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  char *pcVar13;
  
  FUN_004afce0(s_adding_frame__anim__d__mesh__s__t_004fcf88,param_2,param_3,param_4);
  FUN_004a6f20();
  uVar2 = FUN_004a6990(param_4);
  piVar11 = (int *)(param_1 + 0x18);
  if (*(int *)(param_1 + 0x24) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,s___array_hpp_004fc894,0xb9,
                 param_1 + 0x2c,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x45);
  }
  iVar12 = *(int *)(param_1 + 0x20);
  iVar5 = *(int *)(param_1 + 0x1c);
  if (iVar12 < iVar5) {
    iVar7 = *(int *)(param_1 + 0x28);
    iVar10 = iVar12;
    do {
      if (*(char *)(iVar7 + iVar10) == '\0') goto LAB_004a5ef9;
      iVar10 = iVar10 + 1;
    } while (iVar10 < iVar5);
  }
  iVar10 = 0;
  if (0 < iVar12) {
    iVar7 = *(int *)(param_1 + 0x28);
    do {
      if (*(char *)(iVar7 + iVar10) == '\0') goto LAB_004a5ef9;
      iVar10 = iVar10 + 1;
    } while (iVar10 < iVar12);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,s___array_hpp_004fc894,0xce,
               param_1 + 0x2c,iVar5,param_1 + 0x45);
  iVar10 = -1;
LAB_004a5cc2:
  if (*(int *)(param_1 + 0x24) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 param_1 + 0x2c,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x45);
  }
  if ((iVar10 < 0) || (*(int *)(param_1 + 0x1c) <= iVar10)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 param_1 + 0x2c,iVar10,*(undefined4 *)(param_1 + 0x1c));
  }
  if (*(char *)(*(int *)(param_1 + 0x28) + iVar10) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 param_1 + 0x2c,iVar10);
  }
  iVar12 = *piVar11;
  iVar5 = iVar10 * 0x15;
  pcVar3 = (char *)FUN_004bfcb1(param_3);
  uVar8 = 0xffffffff;
  do {
    pcVar13 = pcVar3;
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    pcVar13 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar13;
  } while (cVar1 != '\0');
  uVar8 = ~uVar8;
  pcVar3 = pcVar13 + -uVar8;
  pcVar13 = (char *)(iVar5 + iVar12);
  for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined4 *)pcVar13 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *pcVar13 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar13 = pcVar13 + 1;
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 param_1 + 0x2c,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x45);
  }
  if ((iVar10 < 0) || (*(int *)(param_1 + 0x1c) <= iVar10)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 param_1 + 0x2c,iVar10,*(undefined4 *)(param_1 + 0x1c));
  }
  if (*(char *)(*(int *)(param_1 + 0x28) + iVar10) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 param_1 + 0x2c,iVar10);
  }
  iVar12 = *piVar11;
  uVar4 = FUN_004a7680(2,param_3);
  *(undefined4 *)(iVar12 + iVar5 + 0xd) = uVar4;
  if (*(int *)(param_1 + 0x24) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 param_1 + 0x2c,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x45);
  }
  if ((iVar10 < 0) || (*(int *)(param_1 + 0x1c) <= iVar10)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 param_1 + 0x2c,iVar10,*(undefined4 *)(param_1 + 0x1c));
  }
  if (*(char *)(*(int *)(param_1 + 0x28) + iVar10) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 param_1 + 0x2c,iVar10);
  }
  *(undefined4 *)(*piVar11 + 0x11 + iVar5) = 1;
  iVar12 = DAT_006a5f38;
  if (DAT_006a5f3c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,s___array_hpp_004fc894,0xb9,
                 &DAT_006a5f44,DAT_006a5f34,&DAT_006a5f5d);
    iVar12 = DAT_006a5f38;
  }
  for (; iVar12 < DAT_006a5f34; iVar12 = iVar12 + 1) {
    if (*(char *)(DAT_006a5f40 + iVar12) == '\0') goto LAB_004a5f05;
  }
  iVar12 = 0;
  if (0 < DAT_006a5f38) {
    do {
      if (*(char *)(DAT_006a5f40 + iVar12) == '\0') goto LAB_004a5f05;
      iVar12 = iVar12 + 1;
    } while (iVar12 < DAT_006a5f38);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,s___array_hpp_004fc894,0xce,&DAT_006a5f44
               ,DAT_006a5f34,&DAT_006a5f5d);
  iVar12 = -1;
LAB_004a5f36:
  FUN_004afce0(s___framelist__frame__d_004fcf6c,iVar12);
  iVar5 = FUN_004a7070(iVar10);
  puVar6 = (undefined4 *)FUN_004a6f50(iVar12);
  *puVar6 = *(undefined4 *)(iVar5 + 0xd);
  iVar5 = FUN_004a7070(uVar2);
  iVar7 = FUN_004a6f50(iVar12);
  *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(iVar5 + 0xd);
  iVar5 = FUN_004a6f50(iVar12);
  *(int *)(iVar5 + 8) = iVar10;
  iVar5 = FUN_004a6f50(iVar12);
  *(undefined4 *)(iVar5 + 0xc) = uVar2;
  puVar6 = (undefined4 *)FUN_004a6f50(iVar12);
  FUN_004afce0(s___framelist__mesh__d_004fcf4c,*puVar6);
  iVar5 = FUN_004a6f50(iVar12);
  FUN_004afce0(s___framelist__texture__d_004fcf2c,*(undefined4 *)(iVar5 + 4));
  iVar5 = FUN_004a6f50(iVar12);
  FUN_004afce0(s___framelist__ld_mesh__d_004fcf0c,*(undefined4 *)(iVar5 + 8));
  iVar5 = FUN_004a6f50(iVar12);
  FUN_004afce0(s___framelist__ld_texture__d_004fceec,*(undefined4 *)(iVar5 + 0xc));
  iVar5 = FUN_004a6db0(param_2);
  FUN_004afce0(s___indexlist__index__d_004fced0,iVar5);
  iVar7 = FUN_004a6fe0(param_2);
  *(int *)(*(int *)(iVar7 + 4) + iVar5 * 4) = iVar12;
  iVar5 = FUN_004a6fe0(param_2);
  *(undefined1 *)(iVar5 + 8) = 1;
  return iVar12;
LAB_004a5ef9:
  *(undefined1 *)(iVar7 + iVar10) = 1;
  *(int *)(param_1 + 0x20) = iVar10;
  goto LAB_004a5cc2;
LAB_004a5f05:
  *(undefined1 *)(DAT_006a5f40 + iVar12) = 1;
  DAT_006a5f38 = iVar12;
  goto LAB_004a5f36;
}

