/*
 * FUN_004a3760 at 004a3760
 * undefined FUN_004a3760(void)
 * Address ranges: 004a3760-004a3a6f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004a3760(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004a36c0();
  if (DAT_006a5e8c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb1,&DAT_006a5e94,DAT_006a5e84,&DAT_006a5ead);
  }
  if ((iVar1 < 0) || (DAT_006a5e84 <= iVar1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb1,&DAT_006a5e94,iVar1,DAT_006a5e84);
  }
  if (*(char *)(DAT_006a5e90 + iVar1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb1,&DAT_006a5e94,iVar1);
  }
  iVar2 = iVar1 * 0x48;
  FUN_004a3d90(param_1,4);
  if (DAT_006a5e8c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb2,&DAT_006a5e94,DAT_006a5e84,&DAT_006a5ead);
  }
  if ((iVar1 < 0) || (DAT_006a5e84 <= iVar1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb2,&DAT_006a5e94,iVar1,DAT_006a5e84);
  }
  if (*(char *)(DAT_006a5e90 + iVar1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb2,&DAT_006a5e94,iVar1);
  }
  *(undefined4 *)(DAT_006a5e80 + 0x34 + iVar2) = 0;
  if (DAT_006a5e8c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb3,&DAT_006a5e94,DAT_006a5e84,&DAT_006a5ead);
  }
  if ((iVar1 < 0) || (DAT_006a5e84 <= iVar1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb3,&DAT_006a5e94,iVar1,DAT_006a5e84);
  }
  if (*(char *)(DAT_006a5e90 + iVar1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb3,&DAT_006a5e94,iVar1);
  }
  *(undefined4 *)(DAT_006a5e80 + 0x38 + iVar2) = 0;
  if (DAT_006a5e8c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb4,&DAT_006a5e94,DAT_006a5e84,&DAT_006a5ead);
  }
  if ((iVar1 < 0) || (DAT_006a5e84 <= iVar1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb4,&DAT_006a5e94,iVar1,DAT_006a5e84);
  }
  if (*(char *)(DAT_006a5e90 + iVar1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb4,&DAT_006a5e94,iVar1);
  }
  *(undefined4 *)(DAT_006a5e80 + 0x3c + iVar2) = 0x3f800000;
  if (DAT_006a5e8c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb5,&DAT_006a5e94,DAT_006a5e84,&DAT_006a5ead);
  }
  if ((iVar1 < 0) || (DAT_006a5e84 <= iVar1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb5,&DAT_006a5e94,iVar1,DAT_006a5e84);
  }
  if (*(char *)(DAT_006a5e90 + iVar1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xb5,&DAT_006a5e94,iVar1);
  }
  *(undefined4 *)(DAT_006a5e80 + 0x40 + iVar2) = 0x3f800000;
  iVar2 = FUN_004a4bb0(iVar1,s_D__work_libs_DX3D_text_cpp_004fca28,0xb6);
  *(undefined4 *)(iVar2 + 0x44) = 0;
  return iVar1;
}

