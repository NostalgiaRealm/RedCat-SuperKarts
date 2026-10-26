/*
 * FUN_004a7e10 at 004a7e10
 * undefined FUN_004a7e10(void)
 * Address ranges: 004a7e10-004a81f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a7e10(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_006a5e8c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0xcf,&DAT_006a5e94,DAT_006a5e84,&DAT_006a5ead);
  }
  if ((param_2 < 0) || (DAT_006a5e84 <= param_2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0xcf,&DAT_006a5e94,param_2,DAT_006a5e84);
  }
  if (*(char *)(DAT_006a5e90 + param_2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0xcf,&DAT_006a5e94,param_2);
  }
  iVar2 = DAT_004fd9fc;
  if (*(int *)(DAT_006a5e80 + 0x44 + param_2 * 0x48) == 0) {
    if (DAT_006a629c == 0) {
      FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_Mesh_cpp_004fd124
                   ,0xd0,&DAT_006a62a4,DAT_006a6294,&DAT_006a62bd);
    }
    if ((iVar2 < 0) || (DAT_006a6294 <= iVar2)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_Mesh_cpp_004fd124
                   ,0xd0,&DAT_006a62a4,iVar2,DAT_006a6294);
    }
    if (*(char *)(DAT_006a62a0 + iVar2) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_Mesh_cpp_004fd124
                   ,0xd0,&DAT_006a62a4,iVar2);
    }
    iVar2 = *(int *)(DAT_006a6290 + iVar2 * 4);
    *(int *)(iVar2 + 0x60) = param_2;
    puVar1 = (undefined4 *)FUN_004a4bb0(param_2,s___material_inl_004fc8e0,0xc0);
    *(undefined4 *)(iVar2 + 0x48) = *puVar1;
    *(undefined4 *)(iVar2 + 0x58) = 1;
    if (*(int *)(iVar2 + 0x5c) == 1) {
      FUN_00423930();
    }
    FUN_004a9680(s___d3dev_inl_004fc8a0,0x11a);
    if (DAT_006a6254 != param_2) {
      DAT_006a6254 = param_2;
      iVar2 = *DAT_006a621c;
      puVar1 = (undefined4 *)FUN_004a4bb0(param_2,s___d3dev_inl_004fc8a0,0x121);
      iVar2 = (**(code **)(iVar2 + 0x5c))(DAT_006a621c,1,*puVar1);
      if (iVar2 != 0) {
        uVar3 = FUN_004aaa00(iVar2);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,s___d3dev_inl_004fc8a0,0x122,uVar3)
        ;
      }
    }
  }
  else {
    if (DAT_006a5eec == 0) {
      FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_Mesh_cpp_004fd124
                   ,0xd3,&DAT_006a5ef4,DAT_006a5ee4,&DAT_006a5f0d);
    }
    if ((param_1 < 0) || (DAT_006a5ee4 <= param_1)) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_Mesh_cpp_004fd124
                   ,0xd3,&DAT_006a5ef4,param_1,DAT_006a5ee4);
    }
    if (*(char *)(DAT_006a5ef0 + param_1) == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_Mesh_cpp_004fd124
                   ,0xd3,&DAT_006a5ef4,param_1);
    }
    if (*(int *)(param_1 * 0xbc + 0xb8 + DAT_006a5ee0) != param_2) {
      if (DAT_006a5eec == 0) {
        FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                     s_D__work_libs_DX3D_Mesh_cpp_004fd124,0xd4,&DAT_006a5ef4,DAT_006a5ee4,
                     &DAT_006a5f0d);
      }
      if ((param_1 < 0) || (DAT_006a5ee4 <= param_1)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                     s_D__work_libs_DX3D_Mesh_cpp_004fd124,0xd4,&DAT_006a5ef4,param_1,DAT_006a5ee4);
      }
      if (*(char *)(DAT_006a5ef0 + param_1) == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                     s_D__work_libs_DX3D_Mesh_cpp_004fd124,0xd4,&DAT_006a5ef4,param_1);
      }
      FUN_004a9010(param_2);
      iVar2 = FUN_004a12f0(param_1,s_D__work_libs_DX3D_Mesh_cpp_004fd124,0xd5);
      *(int *)(iVar2 + 0xb8) = param_2;
    }
  }
  if (DAT_006a5f28 == 0) {
    FUN_004a12f0(param_1,s_D__work_libs_DX3D_Mesh_cpp_004fd124,0xdd);
    FUN_004a96b0();
  }
  else {
    FUN_004a12f0(param_1,s_D__work_libs_DX3D_Mesh_cpp_004fd124,0xdb);
    FUN_004a9900();
  }
  if (DAT_006a5f2c != 0) {
    iVar2 = FUN_004a4bb0(param_2,s_D__work_libs_DX3D_Mesh_cpp_004fd124,0xe1);
    if (*(int *)(iVar2 + 0x44) != 0) {
      FUN_004a12f0(param_1,s_D__work_libs_DX3D_Mesh_cpp_004fd124,0xe2);
      FUN_004a9330(param_2);
      iVar2 = FUN_004a12f0(param_1,s_D__work_libs_DX3D_Mesh_cpp_004fd124,0xe3);
      *(undefined4 *)(iVar2 + 0xb8) = 0xffffffff;
    }
  }
  return;
}

