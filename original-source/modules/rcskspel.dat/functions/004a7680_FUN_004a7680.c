/*
 * FUN_004a7680 at 004a7680
 * undefined FUN_004a7680(void)
 * Address ranges: 004a7680-004a77ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004a7680(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_004a75e0();
  if (DAT_006a5eec == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x40,&DAT_006a5ef4,DAT_006a5ee4,&DAT_006a5f0d);
  }
  if ((iVar1 < 0) || (DAT_006a5ee4 <= iVar1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x40,&DAT_006a5ef4,iVar1,DAT_006a5ee4);
  }
  if (*(char *)(DAT_006a5ef0 + iVar1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x40,&DAT_006a5ef4,iVar1);
  }
  if (*(int *)(iVar1 * 0xbc + 4 + DAT_006a5ee0) == 0) {
    *(undefined4 *)(iVar1 * 0xbc + DAT_006a5ee0) = param_1;
  }
  else {
    FUN_004afee0(s__s__d____illegal_change_of_mesh_t_004fd140,s___mesh_inl_004fd168,0x11);
  }
  if (DAT_006a5eec == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x41,&DAT_006a5ef4,DAT_006a5ee4,&DAT_006a5f0d);
  }
  if ((iVar1 < 0) || (DAT_006a5ee4 <= iVar1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x41,&DAT_006a5ef4,iVar1,DAT_006a5ee4);
  }
  if (*(char *)(DAT_006a5ef0 + iVar1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x41,&DAT_006a5ef4,iVar1);
  }
  FUN_004a9ad0(param_2);
  return iVar1;
}

