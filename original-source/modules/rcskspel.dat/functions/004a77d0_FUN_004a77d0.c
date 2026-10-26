/*
 * FUN_004a77d0 at 004a77d0
 * undefined FUN_004a77d0(void)
 * Address ranges: 004a77d0-004a7a3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004a77d0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = FUN_004a75e0();
  if (DAT_006a5eec == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x4a,&DAT_006a5ef4,DAT_006a5ee4,&DAT_006a5f0d);
  }
  if ((param_1 < 0) || (DAT_006a5ee4 <= param_1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x4a,&DAT_006a5ef4,param_1,DAT_006a5ee4);
  }
  if (*(char *)(DAT_006a5ef0 + param_1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x4a,&DAT_006a5ef4,param_1);
  }
  uVar1 = *(undefined4 *)(DAT_006a5ee0 + param_1 * 0xbc);
  if (DAT_006a5eec == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x4a,&DAT_006a5ef4,DAT_006a5ee4,&DAT_006a5f0d);
  }
  if ((iVar2 < 0) || (DAT_006a5ee4 <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x4a,&DAT_006a5ef4,iVar2,DAT_006a5ee4);
  }
  if (*(char *)(DAT_006a5ef0 + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x4a,&DAT_006a5ef4,iVar2);
  }
  if (*(int *)(iVar2 * 0xbc + 4 + DAT_006a5ee0) == 0) {
    *(undefined4 *)(iVar2 * 0xbc + DAT_006a5ee0) = uVar1;
  }
  else {
    FUN_004afee0(s__s__d____illegal_change_of_mesh_t_004fd140,s___mesh_inl_004fd168,0x11);
  }
  if (DAT_006a5eec == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x4b,&DAT_006a5ef4,DAT_006a5ee4,&DAT_006a5f0d);
  }
  if ((iVar2 < 0) || (DAT_006a5ee4 <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x4b,&DAT_006a5ef4,iVar2,DAT_006a5ee4);
  }
  if (*(char *)(DAT_006a5ef0 + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x4b,&DAT_006a5ef4,iVar2);
  }
  FUN_004a8560(param_1);
  if (DAT_006a5eec == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x4c,&DAT_006a5ef4,DAT_006a5ee4,&DAT_006a5f0d);
  }
  if ((iVar2 < 0) || (DAT_006a5ee4 <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x4c,&DAT_006a5ef4,iVar2,DAT_006a5ee4);
  }
  if (*(char *)(DAT_006a5ef0 + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x4c,&DAT_006a5ef4,iVar2);
  }
  FUN_004ad120(s_copy_mesh_004fd174);
  return iVar2;
}

