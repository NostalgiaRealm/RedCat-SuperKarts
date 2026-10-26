/*
 * FUN_004a3a70 at 004a3a70
 * undefined FUN_004a3a70(void)
 * Address ranges: 004a3a70-004a3bc0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004a3a70(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004a36c0();
  if (DAT_006a5e8c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xc0,&DAT_006a5e94,DAT_006a5e84,&DAT_006a5ead);
  }
  if ((iVar1 < 0) || (DAT_006a5e84 <= iVar1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xc0,&DAT_006a5e94,iVar1,DAT_006a5e84);
  }
  if (*(char *)(DAT_006a5e90 + iVar1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xc0,&DAT_006a5e94,iVar1);
  }
  FUN_004a41c0(param_1,0);
  if (DAT_006a5e8c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xc1,&DAT_006a5e94,DAT_006a5e84,&DAT_006a5ead);
  }
  if ((iVar1 < 0) || (DAT_006a5e84 <= iVar1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xc1,&DAT_006a5e94,iVar1,DAT_006a5e84);
  }
  if (*(char *)(DAT_006a5e90 + iVar1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0xc1,&DAT_006a5e94,iVar1);
    *(undefined4 *)(iVar1 * 0x48 + 0x44 + DAT_006a5e80) = 1;
    return iVar1;
  }
  *(undefined4 *)(iVar1 * 0x48 + 0x44 + DAT_006a5e80) = 1;
  return iVar1;
}

