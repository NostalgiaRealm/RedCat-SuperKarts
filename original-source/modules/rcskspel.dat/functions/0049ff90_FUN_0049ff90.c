/*
 * FUN_0049ff90 at 0049ff90
 * undefined FUN_0049ff90(void)
 * Address ranges: 0049ff90-004a02a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0049ff90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_0049fbc0();
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x84,&DAT_006a5c4c,DAT_006a5c3c,
                 &DAT_006a5c65);
  }
  if ((iVar2 < 0) || (DAT_006a5c3c <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x84,&DAT_006a5c4c,iVar2,DAT_006a5c3c);
  }
  if (*(char *)(DAT_006a5c48 + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x84,&DAT_006a5c4c,iVar2);
  }
  iVar1 = iVar2 * 0xa9;
  *(undefined4 *)(iVar1 + DAT_006a5c38) = 2;
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x85,&DAT_006a5c4c,DAT_006a5c3c,
                 &DAT_006a5c65);
  }
  if ((iVar2 < 0) || (DAT_006a5c3c <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x85,&DAT_006a5c4c,iVar2,DAT_006a5c3c);
  }
  if (*(char *)(DAT_006a5c48 + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x85,&DAT_006a5c4c,iVar2);
  }
  *(undefined4 *)(iVar1 + 4 + DAT_006a5c38) = param_1;
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x86,&DAT_006a5c4c,DAT_006a5c3c,
                 &DAT_006a5c65);
  }
  if ((iVar2 < 0) || (DAT_006a5c3c <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x86,&DAT_006a5c4c,iVar2,DAT_006a5c3c);
  }
  if (*(char *)(DAT_006a5c48 + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x86,&DAT_006a5c4c,iVar2);
  }
  *(undefined4 *)(iVar1 + 8 + DAT_006a5c38) = param_2;
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x88,&DAT_006a5c4c,DAT_006a5c3c,
                 &DAT_006a5c65);
  }
  if ((iVar2 < 0) || (DAT_006a5c3c <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x88,&DAT_006a5c4c,iVar2,DAT_006a5c3c);
  }
  if (*(char *)(DAT_006a5c48 + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x88,&DAT_006a5c4c,iVar2);
  }
  *(undefined4 *)(iVar1 + 0x9d + DAT_006a5c38) = param_3;
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x89,&DAT_006a5c4c,DAT_006a5c3c,
                 &DAT_006a5c65);
  }
  if ((iVar2 < 0) || (DAT_006a5c3c <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x89,&DAT_006a5c4c,iVar2,DAT_006a5c3c);
  }
  if (*(char *)(DAT_006a5c48 + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x89,&DAT_006a5c4c,iVar2);
    *(undefined4 *)(iVar1 + 0x91 + DAT_006a5c38) = 1;
    return iVar2;
  }
  *(undefined4 *)(iVar1 + 0x91 + DAT_006a5c38) = 1;
  return iVar2;
}

