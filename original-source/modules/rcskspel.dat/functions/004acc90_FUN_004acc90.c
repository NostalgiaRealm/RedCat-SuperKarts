/*
 * FUN_004acc90 at 004acc90
 * undefined FUN_004acc90(void)
 * Address ranges: 004acc90-004acd63
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004acc90(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_006a62ec == 0) {
    FUN_004afee0(s__s__d____viewport_array_not_init_004fdf08,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x49);
  }
  piVar1 = DAT_006a62e8;
  DAT_006a62f0 = param_1;
  if (DAT_006a62e8[3] == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x4d,DAT_006a62e8 + 5,DAT_006a62e8[1],
                 (int)DAT_006a62e8 + 0x2d);
  }
  if ((param_1 < 0) || (piVar1[1] <= param_1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x4d,piVar1 + 5,param_1,piVar1[1]);
  }
  if (*(char *)(piVar1[4] + param_1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x4d,piVar1 + 5,param_1);
  }
  iVar2 = (**(code **)(*DAT_006a621c + 0x34))
                    (DAT_006a621c,*(undefined4 *)(*(int *)(*piVar1 + param_1 * 4) + 0x2c));
  if (iVar2 != 0) {
    uVar3 = FUN_004aaa00(iVar2);
    FUN_004afee0(s__s__d___D3DError_Setting_viewpor_004fdf54,s___viewport_inl_004fd9ec,0x46,uVar3);
  }
  return;
}

