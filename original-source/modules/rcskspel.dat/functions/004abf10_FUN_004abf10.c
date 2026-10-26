/*
 * FUN_004abf10 at 004abf10
 * undefined FUN_004abf10(void)
 * Address ranges: 004abf10-004ac00e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_004abf10(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = param_1 + 0x15;
  param_1[0x19] = 4;
  param_1[0x17] = 1;
  *puVar1 = 0;
  param_1[0x18] = 0xffffffff;
  param_1[0x16] = 0;
  puVar4 = param_1;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *param_1 = 0x50;
  param_1[1] = 0x3f800000;
  param_1[2] = 0x3f800000;
  param_1[3] = 0x3f800000;
  param_1[5] = 0x3f800000;
  param_1[6] = 0x3f800000;
  param_1[7] = 0x3f800000;
  param_1[0x13] = 0x10;
  iVar3 = (**(code **)(*DAT_006a62dc + 0x14))(DAT_006a62dc,puVar1,0);
  if (iVar3 != 0) {
    uVar2 = FUN_004aaa00(iVar3);
    FUN_004afee0(s__s__d____error_creating_material_004fdacc,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x9a,uVar2);
  }
  iVar3 = (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,param_1);
  if (iVar3 != 0) {
    uVar2 = FUN_004aaa00(iVar3);
    FUN_004afee0(s__s__d____error_setting_material___004fdaa4,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0x9d,uVar2);
  }
  iVar3 = (**(code **)(*(int *)*puVar1 + 0x14))((int *)*puVar1,DAT_006a621c,param_1 + 0x14);
  if (iVar3 != 0) {
    uVar2 = FUN_004aaa00(iVar3);
    FUN_004afee0(s__s__d____error_getting_material_h_004fda78,
                 s_D__work_libs_DX3D_Material_cpp_004fda58,0xa0,uVar2);
  }
  param_1[0x16] = 0;
  (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,param_1);
  return param_1;
}

