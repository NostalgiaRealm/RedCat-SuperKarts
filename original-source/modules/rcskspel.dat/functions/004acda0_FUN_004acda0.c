/*
 * FUN_004acda0 at 004acda0
 * undefined FUN_004acda0(void)
 * Address ranges: 004acda0-004acf35
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004acda0(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  float fVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (DAT_006a62ec == 0) {
    FUN_004afee0(s__s__d____viewport_array_not_init_004fdf08,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x5f);
  }
  if (((int)(param_4 + param_2) < 0) || (DAT_004fe930 < (int)(param_4 + param_2))) {
    FUN_004afee0(s__s__d____error_illegal_x_size_of_004fdfec,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,99,param_2,param_4,DAT_004fe930);
  }
  if (((int)(param_3 + param_5) < 0) || (DAT_004fe934 < (int)(param_3 + param_5))) {
    FUN_004afee0(s__s__d____error_illegal_y_size_of_004fdfac,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x67,param_2,param_5,DAT_004fe934);
  }
  piVar2 = DAT_006a62e8;
  if (DAT_006a62e8[3] == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x6a,DAT_006a62e8 + 5,DAT_006a62e8[1],
                 (int)DAT_006a62e8 + 0x2d);
  }
  if ((param_1 < 0) || (piVar2[1] <= param_1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x6a,piVar2 + 5,param_1,piVar2[1]);
  }
  if (*(char *)(piVar2[4] + param_1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x6a,piVar2 + 5,param_1);
  }
  iVar4 = *(int *)(*piVar2 + param_1 * 4);
  *(int *)(iVar4 + 8) = param_3;
  *(int *)(iVar4 + 4) = param_2;
  iVar6 = (param_4 ^ (int)param_4 >> 0x1f) - ((int)param_4 >> 0x1f);
  *(undefined4 *)(iVar4 + 0x14) = 0xbf800000;
  *(int *)(iVar4 + 0xc) = iVar6;
  uVar3 = (param_5 ^ (int)param_5 >> 0x1f) - ((int)param_5 >> 0x1f);
  *(uint *)(iVar4 + 0x10) = uVar3;
  *(undefined4 *)(iVar4 + 0x1c) = 0x40000000;
  fVar1 = (float)uVar3 / (float)iVar6;
  *(undefined4 *)(iVar4 + 0x34) = 1;
  *(float *)(iVar4 + 0x3c) = fVar1;
  *(float *)(iVar4 + 0x18) = fVar1;
  *(float *)(iVar4 + 0x20) = fVar1 + fVar1;
  if (*(int *)(iVar4 + 0x30) == 1) {
    iVar4 = (**(code **)(**(int **)(iVar4 + 0x2c) + 0x44))(*(int **)(iVar4 + 0x2c),iVar4);
    if (iVar4 != 0) {
      uVar5 = FUN_004aaa00(iVar4);
      FUN_004afee0(s__s__d___D3DError_Creating_viewpo_004fdf80,s___viewport_inl_004fd9ec,0xd,uVar5);
    }
  }
  return;
}

