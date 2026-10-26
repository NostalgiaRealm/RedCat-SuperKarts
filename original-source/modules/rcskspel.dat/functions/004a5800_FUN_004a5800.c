/*
 * FUN_004a5800 at 004a5800
 * undefined FUN_004a5800(void)
 * Address ranges: 004a5800-004a5bff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004a5800(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  FUN_004afce0(s_adding_frame__anim__d__mesh__s__t_004fcf88,param_2,param_3,param_4);
  FUN_004a6f20();
  iVar1 = FUN_004a65d0(param_3);
  iVar2 = FUN_004a6990(param_4);
  iVar5 = DAT_006a5f38;
  if (DAT_006a5f3c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,s___array_hpp_004fc894,0xb9,
                 &DAT_006a5f44,DAT_006a5f34,&DAT_006a5f5d);
    iVar5 = DAT_006a5f38;
  }
  for (; iVar5 < DAT_006a5f34; iVar5 = iVar5 + 1) {
    if (*(char *)(DAT_006a5f40 + iVar5) == '\0') goto LAB_004a5bf1;
  }
  iVar5 = 0;
  if (0 < DAT_006a5f38) {
    do {
      if (*(char *)(DAT_006a5f40 + iVar5) == '\0') goto LAB_004a5bf1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_006a5f38);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,s___array_hpp_004fc894,0xce,&DAT_006a5f44
               ,DAT_006a5f34,&DAT_006a5f5d);
  iVar5 = -1;
LAB_004a58d2:
  FUN_004afce0(s___framelist__frame__d_004fcf6c,iVar5);
  if (*(int *)(param_1 + 0x24) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 param_1 + 0x2c,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x45);
  }
  if ((iVar1 < 0) || (*(int *)(param_1 + 0x1c) <= iVar1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 param_1 + 0x2c,iVar1,*(undefined4 *)(param_1 + 0x1c));
  }
  if (*(char *)(*(int *)(param_1 + 0x28) + iVar1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 param_1 + 0x2c,iVar1);
  }
  if (DAT_006a5f3c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 &DAT_006a5f44,DAT_006a5f34,&DAT_006a5f5d);
  }
  if ((iVar5 < 0) || (DAT_006a5f34 <= iVar5)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 &DAT_006a5f44,iVar5,DAT_006a5f34);
  }
  if (*(char *)(DAT_006a5f40 + iVar5) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 &DAT_006a5f44,iVar5);
  }
  *(undefined4 *)(iVar5 * 0x10 + DAT_006a5f30) =
       *(undefined4 *)(iVar1 * 0x15 + 0xd + *(int *)(param_1 + 0x18));
  if (*(int *)(param_1 + 0x6a) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 param_1 + 0x72,*(undefined4 *)(param_1 + 0x62),param_1 + 0x8b);
  }
  if ((iVar2 < 0) || (*(int *)(param_1 + 0x62) <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 param_1 + 0x72,iVar2,*(undefined4 *)(param_1 + 0x62));
  }
  if (*(char *)(*(int *)(param_1 + 0x6e) + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 param_1 + 0x72,iVar2);
  }
  if (DAT_006a5f3c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 &DAT_006a5f44,DAT_006a5f34,&DAT_006a5f5d);
  }
  if ((iVar5 < 0) || (DAT_006a5f34 <= iVar5)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 &DAT_006a5f44,iVar5,DAT_006a5f34);
  }
  if (*(char *)(DAT_006a5f40 + iVar5) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 &DAT_006a5f44,iVar5);
  }
  *(undefined4 *)(iVar5 * 0x10 + 4 + DAT_006a5f30) =
       *(undefined4 *)(iVar2 * 0x15 + 0xd + *(int *)(param_1 + 0x5e));
  iVar3 = FUN_004a6f50(iVar5);
  *(int *)(iVar3 + 8) = iVar1;
  iVar1 = FUN_004a6f50(iVar5);
  *(int *)(iVar1 + 0xc) = iVar2;
  puVar4 = (undefined4 *)FUN_004a6f50(iVar5);
  FUN_004afce0(s___framelist__mesh__d_004fcf4c,*puVar4);
  iVar1 = FUN_004a6f50(iVar5);
  FUN_004afce0(s___framelist__texture__d_004fcf2c,*(undefined4 *)(iVar1 + 4));
  iVar1 = FUN_004a6f50(iVar5);
  FUN_004afce0(s___framelist__ld_mesh__d_004fcf0c,*(undefined4 *)(iVar1 + 8));
  iVar1 = FUN_004a6f50(iVar5);
  FUN_004afce0(s___framelist__ld_texture__d_004fceec,*(undefined4 *)(iVar1 + 0xc));
  iVar1 = FUN_004a6db0(param_2);
  FUN_004afce0(s___indexlist__index__d_004fced0,iVar1);
  iVar2 = FUN_004a6fe0(param_2);
  *(int *)(*(int *)(iVar2 + 4) + iVar1 * 4) = iVar5;
  iVar1 = FUN_004a6fe0(param_2);
  *(undefined1 *)(iVar1 + 8) = 1;
  return iVar5;
LAB_004a5bf1:
  *(undefined1 *)(DAT_006a5f40 + iVar5) = 1;
  DAT_006a5f38 = iVar5;
  goto LAB_004a58d2;
}

