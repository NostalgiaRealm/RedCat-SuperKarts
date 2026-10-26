/*
 * FUN_004a46e0 at 004a46e0
 * undefined FUN_004a46e0(void)
 * Address ranges: 004a46e0-004a4a2f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a46e0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if ((param_1 < 0) || (DAT_006a5e84 < param_1)) {
    FUN_004afee0(s__s__d____Illegal_texturenumber___004fcd0c,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0x25c,param_1);
  }
  iVar2 = FUN_004ae830();
  if (iVar2 != 0) {
    if (DAT_006a5e8c == 0) {
      FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_text_cpp_004fca28
                   ,0x262,&DAT_006a5e94,DAT_006a5e84,&DAT_006a5ead);
    }
    if ((param_1 < 0) || (DAT_006a5e84 <= param_1)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_text_cpp_004fca28
                   ,0x262,&DAT_006a5e94,param_1,DAT_006a5e84);
    }
    if (DAT_006a5e90[param_1] == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_text_cpp_004fca28
                   ,0x262,&DAT_006a5e94,param_1);
    }
    iVar2 = param_1 * 0x48;
    if (*(int *)(iVar2 + 0x44 + DAT_006a5e80) == 1) {
      if (DAT_006a5e8c == 0) {
        FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x263,&DAT_006a5e94,DAT_006a5e84,
                     &DAT_006a5ead);
      }
      if (DAT_006a5e84 < 1) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x263,&DAT_006a5e94,0,DAT_006a5e84);
      }
      if (*DAT_006a5e90 == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x263,&DAT_006a5e94,0);
      }
      if (DAT_006a5e8c == 0) {
        FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x263,&DAT_006a5e94,DAT_006a5e84,
                     &DAT_006a5ead);
      }
      if (DAT_006a5e84 < 1) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x263,&DAT_006a5e94,0,DAT_006a5e84);
      }
      if (*DAT_006a5e90 == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x263,&DAT_006a5e94,0);
      }
      iVar2 = (**(code **)(**(int **)(DAT_006a5e80 + 0x10) + 0x14))
                        (*(int **)(DAT_006a5e80 + 0x10),*(undefined4 *)(DAT_006a5e80 + 0xc));
      if (iVar2 == 0) {
        return;
      }
      uVar3 = FUN_004aaa00(iVar2);
      uVar4 = 0x264;
    }
    else {
      if (DAT_006a5e8c == 0) {
        FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x267,&DAT_006a5e94,DAT_006a5e84,
                     &DAT_006a5ead);
      }
      if ((param_1 < 0) || (DAT_006a5e84 <= param_1)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x267,&DAT_006a5e94,param_1,DAT_006a5e84)
        ;
      }
      if (DAT_006a5e90[param_1] == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x267,&DAT_006a5e94,param_1);
      }
      if (DAT_006a5e8c == 0) {
        FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x267,&DAT_006a5e94,DAT_006a5e84,
                     &DAT_006a5ead);
      }
      if ((param_1 < 0) || (DAT_006a5e84 <= param_1)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x267,&DAT_006a5e94,param_1,DAT_006a5e84)
        ;
      }
      if (DAT_006a5e90[param_1] == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x267,&DAT_006a5e94,param_1);
      }
      piVar1 = *(int **)(iVar2 + 0x10 + DAT_006a5e80);
      iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,*(undefined4 *)(iVar2 + 0xc + DAT_006a5e80));
      if (iVar2 == 0) {
        return;
      }
      uVar3 = FUN_004aaa00(iVar2);
      uVar4 = 0x268;
    }
    FUN_004afee0(s__s__d____D3DError_get_texturehan_004fcad0,s_D__work_libs_DX3D_text_cpp_004fca28,
                 uVar4,uVar3);
  }
  return;
}

