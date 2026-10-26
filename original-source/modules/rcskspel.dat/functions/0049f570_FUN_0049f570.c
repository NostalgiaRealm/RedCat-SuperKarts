/*
 * FUN_0049f570 at 0049f570
 * undefined FUN_0049f570(void)
 * Address ranges: 0049f570-0049f83e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049f570(int param_1)

{
  int iVar1;
  
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 &DAT_006a5c4c,DAT_006a5c3c,&DAT_006a5c65);
  }
  if ((param_1 < 0) || (DAT_006a5c3c <= param_1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 &DAT_006a5c4c,param_1,DAT_006a5c3c);
  }
  if (*(char *)(DAT_006a5c48 + param_1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 &DAT_006a5c4c,param_1);
  }
  iVar1 = param_1 * 0xa9;
  *(undefined4 *)(iVar1 + 0x91 + DAT_006a5c38) = 0xffffffff;
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 &DAT_006a5c4c,DAT_006a5c3c,&DAT_006a5c65);
  }
  if ((param_1 < 0) || (DAT_006a5c3c <= param_1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 &DAT_006a5c4c,param_1,DAT_006a5c3c);
  }
  if (*(char *)(DAT_006a5c48 + param_1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 &DAT_006a5c4c,param_1);
  }
  *(undefined4 *)(iVar1 + 0xa1 + DAT_006a5c38) = 1;
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x42,&DAT_006a5c4c,DAT_006a5c3c,
                 &DAT_006a5c65);
  }
  if ((param_1 < 0) || (DAT_006a5c3c <= param_1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x42,&DAT_006a5c4c,param_1,DAT_006a5c3c);
  }
  if (*(char *)(DAT_006a5c48 + param_1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x42,&DAT_006a5c4c,param_1);
  }
  *(undefined4 *)(iVar1 + 0x99 + DAT_006a5c38) = 0xffffffff;
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x43,&DAT_006a5c4c,DAT_006a5c3c,
                 &DAT_006a5c65);
  }
  if ((param_1 < 0) || (DAT_006a5c3c <= param_1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x43,&DAT_006a5c4c,param_1,DAT_006a5c3c);
  }
  if (*(char *)(DAT_006a5c48 + param_1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Object3d_cpp_004fc7c8,0x43,&DAT_006a5c4c,param_1);
  }
  *(undefined4 *)(iVar1 + 0x95 + DAT_006a5c38) = 0xffffffff;
  if (DAT_006a5c44 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__free__s__d__of_004fc74c,s___array_hpp_004fc894,0xd7,
                 &DAT_006a5c4c,DAT_006a5c3c,&DAT_006a5c65);
  }
  if ((-1 < param_1) && (param_1 < DAT_006a5c3c)) {
    *(undefined1 *)(DAT_006a5c48 + param_1) = 0;
    return;
  }
  FUN_004afee0(s__s__d____T_ARRAY__free_illegal_i_004fc708,s___array_hpp_004fc894,0xdb,param_1,
               &DAT_006a5c4c,DAT_006a5c3c,&DAT_006a5c65);
  *(undefined1 *)(DAT_006a5c48 + param_1) = 0;
  return;
}

