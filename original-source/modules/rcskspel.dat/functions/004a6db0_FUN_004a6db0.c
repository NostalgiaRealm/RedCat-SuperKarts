/*
 * FUN_004a6db0 at 004a6db0
 * undefined FUN_004a6db0(void)
 * Address ranges: 004a6db0-004a6f1c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004a6db0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (DAT_006a5f84 == 0) {
      FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                   &DAT_006a5f8c,DAT_006a5f7c,&DAT_006a5fa5);
    }
    if ((param_1 < 0) || (DAT_006a5f7c <= param_1)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                   &DAT_006a5f8c,param_1,DAT_006a5f7c);
    }
    if (*(char *)(DAT_006a5f88 + param_1) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                   &DAT_006a5f8c,param_1);
    }
    if (*(int *)(param_1 * 9 + DAT_006a5f78) <= iVar1) {
      FUN_004afee0(s___s__d___no_free_index_in_index_f_004fd094,
                   s_D__work_libs_DX3D_Animsys_cpp_004fce58,0x1e2,param_1,iVar1 + -1);
      return -1;
    }
    if (DAT_006a5f84 == 0) {
      FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                   &DAT_006a5f8c,DAT_006a5f7c,&DAT_006a5fa5);
    }
    if ((param_1 < 0) || (DAT_006a5f7c <= param_1)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                   &DAT_006a5f8c,param_1,DAT_006a5f7c);
    }
    if (*(char *)(DAT_006a5f88 + param_1) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                   &DAT_006a5f8c,param_1);
    }
    if (*(int *)(*(int *)(param_1 * 9 + 4 + DAT_006a5f78) + iVar1 * 4) == -1) break;
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

