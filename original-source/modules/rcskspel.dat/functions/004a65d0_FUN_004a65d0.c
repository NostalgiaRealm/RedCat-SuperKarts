/*
 * FUN_004a65d0 at 004a65d0
 * undefined FUN_004a65d0(void)
 * Address ranges: 004a65d0-004a6986
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004a65d0(int param_1,char *param_2)

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
  
  FUN_004afce0(s_get_mesh_index___s_004fd064,param_2);
  iVar6 = *(int *)(param_1 + 0x1c);
  iVar10 = 0;
  if (0 < iVar6) {
    iVar9 = 0;
    do {
      if ((iVar9 < 0) || (*(int *)(param_1 + 0x1c) <= iVar10)) {
        FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,s___array_hpp_004fc894,0x43,iVar10,
                     param_1 + 0x2c,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x45);
      }
      if (*(char *)(*(int *)(param_1 + 0x28) + iVar10) != '\0') {
        if (*(int *)(param_1 + 0x24) == 0) {
          FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                       param_1 + 0x2c,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x45);
        }
        if ((iVar9 < 0) || (*(int *)(param_1 + 0x1c) <= iVar10)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                       param_1 + 0x2c,iVar10,*(undefined4 *)(param_1 + 0x1c));
        }
        if (*(char *)(*(int *)(param_1 + 0x28) + iVar10) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                       param_1 + 0x2c,iVar10);
        }
        iVar3 = __strcmpi(param_2,(char *)(*(int *)(param_1 + 0x18) + iVar9));
        if (iVar3 == 0) {
          FUN_004afce0(s___already_used__index__d_004fd048,iVar10);
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
          piVar1 = (int *)(iVar10 * 0x15 + 0x11 + *(int *)(param_1 + 0x18));
          *piVar1 = *piVar1 + 1;
          return iVar10;
        }
      }
      iVar10 = iVar10 + 1;
      iVar9 = iVar9 + 0x15;
    } while (iVar10 < iVar6);
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,s___array_hpp_004fc894,0xb9,
                 param_1 + 0x2c,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x45);
  }
  iVar6 = *(int *)(param_1 + 0x20);
  iVar10 = *(int *)(param_1 + 0x1c);
  if (iVar6 < iVar10) {
    iVar9 = *(int *)(param_1 + 0x28);
    iVar3 = iVar6;
    do {
      if (*(char *)(iVar9 + iVar3) == '\0') goto LAB_004a67e2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar10);
  }
  iVar3 = 0;
  if (0 < iVar6) {
    iVar9 = *(int *)(param_1 + 0x28);
    do {
      if (*(char *)(iVar9 + iVar3) == '\0') goto LAB_004a67e2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar6);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,s___array_hpp_004fc894,0xce,
               param_1 + 0x2c,iVar10,param_1 + 0x45);
  iVar3 = -1;
LAB_004a680e:
  FUN_004afce0(s___not_yet_used__adding_to_list___004fd020,iVar3);
  if (*(int *)(param_1 + 0x24) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 param_1 + 0x2c,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x45);
  }
  if ((iVar3 < 0) || (*(int *)(param_1 + 0x1c) <= iVar3)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 param_1 + 0x2c,iVar3,*(undefined4 *)(param_1 + 0x1c));
  }
  if (*(char *)(*(int *)(param_1 + 0x28) + iVar3) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 param_1 + 0x2c,iVar3);
  }
  iVar6 = *(int *)(param_1 + 0x18);
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
  pcVar11 = (char *)(iVar3 * 0x15 + iVar6);
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
  if (*(int *)(param_1 + 0x24) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 param_1 + 0x2c,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x45);
  }
  if ((iVar3 < 0) || (*(int *)(param_1 + 0x1c) <= iVar3)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 param_1 + 0x2c,iVar3,*(undefined4 *)(param_1 + 0x1c));
  }
  if (*(char *)(*(int *)(param_1 + 0x28) + iVar3) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 param_1 + 0x2c,iVar3);
  }
  iVar6 = *(int *)(param_1 + 0x18);
  uVar5 = FUN_004a7680(2,param_2);
  *(undefined4 *)(iVar6 + iVar3 * 0x15 + 0xd) = uVar5;
  iVar6 = FUN_004a7070(iVar3);
  *(undefined4 *)(iVar6 + 0x11) = 1;
  return iVar3;
LAB_004a67e2:
  *(undefined1 *)(iVar9 + iVar3) = 1;
  *(int *)(param_1 + 0x20) = iVar3;
  goto LAB_004a680e;
}

