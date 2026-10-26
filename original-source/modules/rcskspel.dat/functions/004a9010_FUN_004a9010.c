/*
 * FUN_004a9010 at 004a9010
 * undefined FUN_004a9010(void)
 * Address ranges: 004a9010-004a932c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a9010(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  int local_4;
  
  if (*param_1 == 2) {
    iVar5 = 0;
    local_4 = 0;
    if (0 < param_1[0x21]) {
      do {
        if (DAT_006a5e8c == 0) {
          FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x270,&DAT_006a5e94,DAT_006a5e84,
                       &DAT_006a5ead);
        }
        if ((param_2 < 0) || (DAT_006a5e84 <= param_2)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x270,&DAT_006a5e94,param_2,
                       DAT_006a5e84);
        }
        if (*(char *)(DAT_006a5e90 + param_2) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x270,&DAT_006a5e94,param_2);
        }
        *(float *)(iVar5 + 0x18 + param_1[0x20]) =
             ABS(*(float *)(iVar5 + 0x18 + param_1[0x20])) * _DAT_006a5ed0 +
             *(float *)(param_2 * 0x48 + 0x34 + DAT_006a5e80);
        if (DAT_006a5e8c == 0) {
          FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x271,&DAT_006a5e94,DAT_006a5e84,
                       &DAT_006a5ead);
        }
        if ((param_2 < 0) || (DAT_006a5e84 <= param_2)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x271,&DAT_006a5e94,param_2,
                       DAT_006a5e84);
        }
        if (*(char *)(DAT_006a5e90 + param_2) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x271,&DAT_006a5e94,param_2);
        }
        iVar1 = iVar5 + 0x1c;
        iVar2 = iVar5 + 0x1c;
        iVar5 = iVar5 + 0x20;
        *(float *)(iVar2 + param_1[0x20]) =
             ABS(*(float *)(iVar1 + param_1[0x20])) * _DAT_006a5ed4 +
             *(float *)(param_2 * 0x48 + 0x38 + DAT_006a5e80);
        local_4 = local_4 + 1;
      } while (local_4 < param_1[0x21]);
      return;
    }
  }
  else {
    iVar5 = 0;
    local_4 = 0;
    if (0 < param_1[0x1f]) {
      do {
        if (DAT_006a5e8c == 0) {
          FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x275,&DAT_006a5e94,DAT_006a5e84,
                       &DAT_006a5ead);
        }
        if ((param_2 < 0) || (DAT_006a5e84 <= param_2)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x275,&DAT_006a5e94,param_2,
                       DAT_006a5e84);
        }
        if (*(char *)(DAT_006a5e90 + param_2) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x275,&DAT_006a5e94,param_2);
        }
        *(float *)(param_1[0x1e] + 0x18 + iVar5) =
             ABS(*(float *)(param_1[0x1e] + 0x18 + iVar5)) * _DAT_006a5ed0 +
             *(float *)(param_2 * 0x48 + 0x34 + DAT_006a5e80);
        if (DAT_006a5e8c == 0) {
          FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x276,&DAT_006a5e94,DAT_006a5e84,
                       &DAT_006a5ead);
        }
        if ((param_2 < 0) || (DAT_006a5e84 <= param_2)) {
          FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x276,&DAT_006a5e94,param_2,
                       DAT_006a5e84);
        }
        if (*(char *)(DAT_006a5e90 + param_2) == '\0') {
          FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                       s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x276,&DAT_006a5e94,param_2);
        }
        pfVar3 = (float *)(param_1[0x1e] + 0x1c + iVar5);
        pfVar4 = (float *)(param_1[0x1e] + 0x1c + iVar5);
        iVar5 = iVar5 + 0x20;
        *pfVar4 = ABS(*pfVar3) * _DAT_006a5ed4 + *(float *)(param_2 * 0x48 + 0x38 + DAT_006a5e80);
        local_4 = local_4 + 1;
      } while (local_4 < param_1[0x1f]);
    }
  }
  return;
}

