/*
 * FUN_004a9330 at 004a9330
 * undefined FUN_004a9330(void)
 * Address ranges: 004a9330-004a967d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a9330(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int local_4;
  
  if (*param_1 == 2) {
    iVar4 = 0;
    local_4 = 0;
    if (0 < param_1[0x21]) {
      do {
        if (DAT_006a5e8c == 0) {
          FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x27f,&DAT_006a5e94,DAT_006a5e84,
                       &DAT_006a5ead);
        }
        if ((param_2 < 0) || (DAT_006a5e84 <= param_2)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x27f,&DAT_006a5e94,param_2,
                       DAT_006a5e84);
        }
        if (*(char *)(DAT_006a5e90 + param_2) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x27f,&DAT_006a5e94,param_2);
        }
        pfVar3 = (float *)(iVar4 + 0x18 + param_1[0x20]);
        *pfVar3 = *pfVar3 - *(float *)(DAT_006a5e80 + 0x34 + param_2 * 0x48);
        if (DAT_006a5e8c == 0) {
          FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x280,&DAT_006a5e94,DAT_006a5e84,
                       &DAT_006a5ead);
        }
        if ((param_2 < 0) || (DAT_006a5e84 <= param_2)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x280,&DAT_006a5e94,param_2,
                       DAT_006a5e84);
        }
        if (*(char *)(DAT_006a5e90 + param_2) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x280,&DAT_006a5e94,param_2);
        }
        pfVar3 = (float *)(iVar4 + 0x1c + param_1[0x20]);
        *pfVar3 = *pfVar3 - *(float *)(DAT_006a5e80 + 0x38 + param_2 * 0x48);
        *(float *)(iVar4 + 0x18 + param_1[0x20]) =
             ABS(*(float *)(iVar4 + 0x18 + param_1[0x20])) / _DAT_006a5ed0;
        iVar1 = iVar4 + 0x1c;
        iVar2 = iVar4 + 0x1c;
        iVar4 = iVar4 + 0x20;
        *(float *)(iVar2 + param_1[0x20]) = ABS(*(float *)(iVar1 + param_1[0x20])) / _DAT_006a5ed4;
        local_4 = local_4 + 1;
      } while (local_4 < param_1[0x21]);
      return;
    }
  }
  else {
    iVar4 = 0;
    local_4 = 0;
    if (0 < param_1[0x1f]) {
      do {
        if (DAT_006a5e8c == 0) {
          FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x286,&DAT_006a5e94,DAT_006a5e84,
                       &DAT_006a5ead);
        }
        if ((param_2 < 0) || (DAT_006a5e84 <= param_2)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x286,&DAT_006a5e94,param_2,
                       DAT_006a5e84);
        }
        if (*(char *)(DAT_006a5e90 + param_2) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x286,&DAT_006a5e94,param_2);
        }
        pfVar3 = (float *)(iVar4 + 0x18 + param_1[0x1e]);
        *pfVar3 = *pfVar3 - *(float *)(DAT_006a5e80 + 0x34 + param_2 * 0x48);
        if (DAT_006a5e8c == 0) {
          FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x287,&DAT_006a5e94,DAT_006a5e84,
                       &DAT_006a5ead);
        }
        if ((param_2 < 0) || (DAT_006a5e84 <= param_2)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x287,&DAT_006a5e94,param_2,
                       DAT_006a5e84);
        }
        if (*(char *)(DAT_006a5e90 + param_2) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x287,&DAT_006a5e94,param_2);
        }
        pfVar3 = (float *)(iVar4 + 0x1c + param_1[0x1e]);
        *pfVar3 = *pfVar3 - *(float *)(DAT_006a5e80 + 0x38 + param_2 * 0x48);
        *(float *)(iVar4 + 0x18 + param_1[0x1e]) =
             ABS(*(float *)(iVar4 + 0x18 + param_1[0x1e])) / _DAT_006a5ed0;
        iVar1 = iVar4 + 0x1c;
        iVar2 = iVar4 + 0x1c;
        iVar4 = iVar4 + 0x20;
        *(float *)(iVar2 + param_1[0x1e]) = ABS(*(float *)(iVar1 + param_1[0x1e])) / _DAT_006a5ed4;
        local_4 = local_4 + 1;
      } while (local_4 < param_1[0x1f]);
    }
  }
  return;
}

