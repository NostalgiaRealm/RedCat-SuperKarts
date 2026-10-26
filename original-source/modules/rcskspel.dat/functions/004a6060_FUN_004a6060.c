/*
 * FUN_004a6060 at 004a6060
 * undefined FUN_004a6060(void)
 * Address ranges: 004a6060-004a61fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_004a6060(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    iVar2 = 0;
    do {
      if ((iVar2 < 0) || (*(int *)(param_1 + 0x62) <= iVar3)) {
        FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,s___array_hpp_004fc894,0x43,iVar3,
                     param_1 + 0x72,*(undefined4 *)(param_1 + 0x62),param_1 + 0x8b);
      }
      if (*(char *)(*(int *)(param_1 + 0x6e) + iVar3) != '\0') {
        if (*(int *)(param_1 + 0x6a) == 0) {
          FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                       param_1 + 0x72,*(undefined4 *)(param_1 + 0x62),param_1 + 0x8b);
        }
        if ((iVar2 < 0) || (*(int *)(param_1 + 0x62) <= iVar3)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                       param_1 + 0x72,iVar3,*(undefined4 *)(param_1 + 0x62));
        }
        if (*(char *)(*(int *)(param_1 + 0x6e) + iVar3) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                       param_1 + 0x72,iVar3);
        }
        iVar1 = __strcmpi(param_2,(char *)(*(int *)(param_1 + 0x5e) + iVar2));
        if (iVar1 == 0) {
          if (*(int *)(param_1 + 0x6a) == 0) {
            FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                         param_1 + 0x72,*(undefined4 *)(param_1 + 0x62),param_1 + 0x8b);
          }
          if ((iVar3 < 0) || (*(int *)(param_1 + 0x62) <= iVar3)) {
            FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                         param_1 + 0x72,iVar3,*(undefined4 *)(param_1 + 0x62));
          }
          if (*(char *)(*(int *)(param_1 + 0x6e) + iVar3) == '\0') {
            FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                         param_1 + 0x72,iVar3);
          }
          return *(undefined4 *)(iVar3 * 0x15 + 0xd + *(int *)(param_1 + 0x5e));
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x15;
    } while (iVar3 < *(int *)(param_1 + 0xc));
  }
  FUN_004afee0(s_find_texture_index___texture_<_s_004fcfb4,param_2);
  return 0;
}

