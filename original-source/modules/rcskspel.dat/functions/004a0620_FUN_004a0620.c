/*
 * FUN_004a0620 at 004a0620
 * undefined FUN_004a0620(void)
 * Address ranges: 004a0620-004a089e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004a0620(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x11e,&DAT_006a5c4c,DAT_006a5c3c,
                 &DAT_006a5c65);
  }
  if ((param_1 < 0) || (DAT_006a5c3c <= param_1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x11e,&DAT_006a5c4c,param_1,DAT_006a5c3c)
    ;
  }
  if (*(char *)(DAT_006a5c48 + param_1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x11e,&DAT_006a5c4c,param_1);
  }
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x11e,&DAT_006a5c4c,DAT_006a5c3c,
                 &DAT_006a5c65);
  }
  if ((param_1 < 0) || (DAT_006a5c3c <= param_1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x11e,&DAT_006a5c4c,param_1,DAT_006a5c3c)
    ;
  }
  if (*(char *)(DAT_006a5c48 + param_1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x11e,&DAT_006a5c4c,param_1);
  }
  iVar2 = param_1 * 0xa9;
  iVar1 = iVar2 + DAT_006a5c38;
  *(float *)(iVar1 + 0x50) =
       *(float *)(iVar2 + 0x5c + DAT_006a5c38) + *(float *)(iVar2 + 0x50 + DAT_006a5c38);
  *(float *)(iVar1 + 0x54) = *(float *)(iVar1 + 0x60) + *(float *)(iVar1 + 0x54);
  *(float *)(iVar1 + 0x58) = *(float *)(iVar1 + 100) + *(float *)(iVar1 + 0x58);
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x11f,&DAT_006a5c4c,DAT_006a5c3c,
                 &DAT_006a5c65);
  }
  if ((param_1 < 0) || (DAT_006a5c3c <= param_1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x11f,&DAT_006a5c4c,param_1,DAT_006a5c3c)
    ;
  }
  if (*(char *)(DAT_006a5c48 + param_1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x11f,&DAT_006a5c4c,param_1);
  }
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x11f,&DAT_006a5c4c,DAT_006a5c3c,
                 &DAT_006a5c65);
  }
  if ((param_1 < 0) || (DAT_006a5c3c <= param_1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x11f,&DAT_006a5c4c,param_1,DAT_006a5c3c)
    ;
  }
  if (*(char *)(DAT_006a5c48 + param_1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x11f,&DAT_006a5c4c,param_1);
  }
  iVar2 = DAT_006a5c38 + iVar2;
  *(float *)(iVar2 + 0x74) = *(float *)(iVar2 + 0x68) + *(float *)(iVar2 + 0x74);
  *(float *)(iVar2 + 0x78) = *(float *)(iVar2 + 0x6c) + *(float *)(iVar2 + 0x78);
  *(float *)(iVar2 + 0x7c) = *(float *)(iVar2 + 0x70) + *(float *)(iVar2 + 0x7c);
  return 0;
}

