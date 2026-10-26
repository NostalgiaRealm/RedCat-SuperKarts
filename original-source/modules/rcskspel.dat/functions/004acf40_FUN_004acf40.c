/*
 * FUN_004acf40 at 004acf40
 * undefined FUN_004acf40(void)
 * Address ranges: 004acf40-004ad070
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_004acf40(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  puVar1 = param_1 + 0xb;
  iVar2 = (**(code **)(*DAT_006a62dc + 0x18))(DAT_006a62dc,puVar1,0);
  if (iVar2 != 0) {
    uVar3 = FUN_004aaa00(iVar2);
    FUN_004afee0(s__s__d____D3DError_Creating_viewp_004fe054,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0x97,uVar3);
  }
  param_1[0xf] = (float)DAT_004fe934 / (float)DAT_004fe930;
  puVar4 = param_1;
  for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *param_1 = 0x2c;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = DAT_004fe930;
  iVar2 = DAT_004fe934;
  param_1[8] = (float)param_1[0xf] + (float)param_1[0xf];
  param_1[4] = iVar2;
  param_1[5] = 0xbf800000;
  param_1[6] = param_1[0xf];
  param_1[7] = 0x40000000;
  param_1[9] = 0;
  param_1[10] = 0x3f800000;
  iVar2 = (**(code **)(*DAT_006a621c + 0x18))(DAT_006a621c,*puVar1);
  if (iVar2 != 0) {
    uVar3 = FUN_004aaa00(iVar2);
    FUN_004afee0(s__s__d___D3DError_Creating_viewpo_004fdf80,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0xaf,uVar3);
  }
  iVar2 = (**(code **)(*(int *)*puVar1 + 0x44))((int *)*puVar1,param_1);
  if (iVar2 != 0) {
    uVar3 = FUN_004aaa00(iVar2);
    FUN_004afee0(s__s__d____error_setting_viewport___004fe02c,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0xb3,uVar3);
  }
  iVar2 = (**(code **)(*DAT_006a621c + 0x34))(DAT_006a621c,*puVar1);
  if (iVar2 != 0) {
    uVar3 = FUN_004aaa00(iVar2);
    FUN_004afee0(s__s__d___D3DError_Setting_viewpor_004fdf54,
                 s_D__work_libs_DX3D_Viewport_cpp_004fdf34,0xb7,uVar3);
  }
  param_1[0xc] = 1;
  return param_1;
}

