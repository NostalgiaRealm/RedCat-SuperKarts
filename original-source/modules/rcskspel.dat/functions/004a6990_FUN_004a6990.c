/*
 * FUN_004a6990 at 004a6990
 * undefined FUN_004a6990(void)
 * Address ranges: 004a6990-004a6da1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004a6990(int param_1,char *param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  int iStack_c;
  
  FUN_004afce0(s_get_texture_index___s_004fd07c,param_2);
  iVar6 = *(int *)(param_1 + 0x62);
  iVar10 = 0;
  if (0 < iVar6) {
    iVar9 = 0;
    do {
      if ((iVar9 < 0) || (*(int *)(param_1 + 0x62) <= iVar10)) {
        FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,s___array_hpp_004fc894,0x43,iVar10,
                     param_1 + 0x72,*(undefined4 *)(param_1 + 0x62),param_1 + 0x8b);
      }
      if (*(char *)(*(int *)(param_1 + 0x6e) + iVar10) != '\0') {
        if (*(int *)(param_1 + 0x6a) == 0) {
          FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                       param_1 + 0x72,*(undefined4 *)(param_1 + 0x62),param_1 + 0x8b);
        }
        if ((iVar9 < 0) || (*(int *)(param_1 + 0x62) <= iVar10)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                       param_1 + 0x72,iVar10,*(undefined4 *)(param_1 + 0x62));
        }
        if (*(char *)(*(int *)(param_1 + 0x6e) + iVar10) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                       param_1 + 0x72,iVar10);
        }
        iVar3 = __strcmpi(param_2,(char *)(*(int *)(param_1 + 0x5e) + iVar9));
        if (iVar3 == 0) {
          FUN_004afce0(s___already_used__index__d_004fd048,iVar10);
          if (*(int *)(param_1 + 0x6a) == 0) {
            FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                         param_1 + 0x72,*(undefined4 *)(param_1 + 0x62),param_1 + 0x8b);
          }
          if ((iVar10 < 0) || (*(int *)(param_1 + 0x62) <= iVar10)) {
            FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                         param_1 + 0x72,iVar10,*(undefined4 *)(param_1 + 0x62));
          }
          if (*(char *)(*(int *)(param_1 + 0x6e) + iVar10) == '\0') {
            FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                         param_1 + 0x72,iVar10);
          }
          piVar1 = (int *)(iVar10 * 0x15 + 0x11 + *(int *)(param_1 + 0x5e));
          *piVar1 = *piVar1 + 1;
          return iVar10;
        }
      }
      iVar10 = iVar10 + 1;
      iVar9 = iVar9 + 0x15;
    } while (iVar10 < iVar6);
  }
  if (*(int *)(param_1 + 0x6a) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,s___array_hpp_004fc894,0xb9,
                 param_1 + 0x72,*(undefined4 *)(param_1 + 0x62),param_1 + 0x8b);
  }
  iVar6 = *(int *)(param_1 + 0x66);
  iVar10 = *(int *)(param_1 + 0x62);
  if (iVar6 < iVar10) {
    iStack_c = iVar6;
    do {
      if (*(char *)(*(int *)(param_1 + 0x6e) + iStack_c) == '\0') {
        *(undefined1 *)(*(int *)(param_1 + 0x6e) + iStack_c) = 1;
        *(int *)(param_1 + 0x66) = iStack_c;
        goto LAB_004a6be6;
      }
      iStack_c = iStack_c + 1;
    } while (iStack_c < iVar10);
  }
  iStack_c = 0;
  if (0 < iVar6) {
    do {
      if (*(char *)(*(int *)(param_1 + 0x6e) + iStack_c) == '\0') {
        *(undefined1 *)(*(int *)(param_1 + 0x6e) + iStack_c) = 1;
        *(int *)(param_1 + 0x66) = iStack_c;
        goto LAB_004a6be6;
      }
      iStack_c = iStack_c + 1;
    } while (iStack_c < iVar6);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,s___array_hpp_004fc894,0xce,
               param_1 + 0x72,iVar10,param_1 + 0x8b);
  iStack_c = -1;
LAB_004a6be6:
  FUN_004afce0(s___not_yet_used__adding_to_list___004fd020,iStack_c);
  if (*(int *)(param_1 + 0x6a) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 param_1 + 0x72,*(undefined4 *)(param_1 + 0x62),param_1 + 0x8b);
  }
  if ((iStack_c < 0) || (*(int *)(param_1 + 0x62) <= iStack_c)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 param_1 + 0x72,iStack_c,*(undefined4 *)(param_1 + 0x62));
  }
  if (*(char *)(*(int *)(param_1 + 0x6e) + iStack_c) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 param_1 + 0x72,iStack_c);
  }
  iVar6 = *(int *)(param_1 + 0x5e);
  pcVar4 = (char *)FUN_004bfcb1(param_2);
  uVar7 = 0xffffffff;
  do {
    pcVar11 = pcVar4;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar11 = pcVar4 + 1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar11;
  } while (cVar2 != '\0');
  uVar7 = ~uVar7;
  pcVar4 = pcVar11 + -uVar7;
  pcVar11 = (char *)(iStack_c * 0x15 + iVar6);
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar11 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar11 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar11 = pcVar11 + 1;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar5 = FUN_004a33b0(param_2);
    iVar6 = FUN_004a7070(iStack_c);
    *(undefined4 *)(iVar6 + 0xd) = uVar5;
  }
  else {
    if (*(int *)(param_1 + 0x6a) == 0) {
      FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                   param_1 + 0x72,*(undefined4 *)(param_1 + 0x62),param_1 + 0x8b);
    }
    if ((iStack_c < 0) || (*(int *)(param_1 + 0x62) <= iStack_c)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                   param_1 + 0x72,iStack_c,*(undefined4 *)(param_1 + 0x62));
    }
    if (*(char *)(*(int *)(param_1 + 0x6e) + iStack_c) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                   param_1 + 0x72,iStack_c);
    }
    iVar6 = *(int *)(param_1 + 0x5e);
    uVar5 = FUN_004a3a70(param_2);
    *(undefined4 *)(iVar6 + iStack_c * 0x15 + 0xd) = uVar5;
  }
  iVar6 = FUN_004a7070(iStack_c);
  *(undefined4 *)(iVar6 + 0x11) = 1;
  return iStack_c;
}

