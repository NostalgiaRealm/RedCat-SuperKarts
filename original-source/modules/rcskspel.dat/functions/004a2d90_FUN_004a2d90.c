/*
 * FUN_004a2d90 at 004a2d90
 * undefined FUN_004a2d90(void)
 * Address ranges: 004a2d90-004a2ff9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a2d90(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = DAT_006a5ed8;
  DAT_006a5ed8 = 1;
  iVar2 = FUN_004a33b0(param_1);
  if (iVar2 != 0) {
    FUN_004afee0(s__s__d____main_accummulator_textu_004fca6c,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0x58);
  }
  iVar2 = DAT_004fd9fc;
  if (DAT_006a629c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0x5b,&DAT_006a62a4,DAT_006a6294,&DAT_006a62bd);
  }
  if ((iVar2 < 0) || (DAT_006a6294 <= iVar2)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0x5b,&DAT_006a62a4,iVar2,DAT_006a6294);
  }
  if (*(char *)(DAT_006a62a0 + iVar2) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_text_cpp_004fca28,
                 0x5b,&DAT_006a62a4,iVar2);
  }
  iVar2 = *(int *)(DAT_006a6290 + iVar2 * 4);
  *(undefined4 *)(iVar2 + 0x60) = 0;
  if (DAT_006a5e8c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s___material_inl_004fc8e0,0xc0,
                 &DAT_006a5e94,DAT_006a5e84,&DAT_006a5ead);
  }
  if (DAT_006a5e84 < 1) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___material_inl_004fc8e0,0xc0,
                 &DAT_006a5e94,0,DAT_006a5e84);
  }
  if (*DAT_006a5e90 == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___material_inl_004fc8e0,0xc0,
                 &DAT_006a5e94,0);
  }
  *(undefined4 *)(iVar2 + 0x48) = *DAT_006a5e80;
  *(undefined4 *)(iVar2 + 0x58) = 1;
  if (*(int *)(iVar2 + 0x5c) == 1) {
    *(undefined4 *)(iVar2 + 0x58) = 0;
    (**(code **)(**(int **)(iVar2 + 0x54) + 0xc))(*(int **)(iVar2 + 0x54),iVar2);
  }
  if (DAT_006a6234 != 1) {
    FUN_004afee0(s__s__d____device_was_not_initiali_004fc8ac,s___d3dev_h_004fc8d4,0xb8);
  }
  if (DAT_006a6254 != 0) {
    DAT_006a6254 = 0;
    if (DAT_006a5e8c == 0) {
      FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s___d3dev_inl_004fc8a0,0x121,
                   &DAT_006a5e94,DAT_006a5e84,&DAT_006a5ead);
    }
    if (DAT_006a5e84 < 1) {
      FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___d3dev_inl_004fc8a0,0x121,
                   &DAT_006a5e94,0,DAT_006a5e84);
    }
    if (*DAT_006a5e90 == '\0') {
      FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___d3dev_inl_004fc8a0,0x121,
                   &DAT_006a5e94,0);
    }
    iVar2 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,1,*DAT_006a5e80);
    if (iVar2 != 0) {
      uVar3 = FUN_004aaa00(iVar2);
      FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,s___d3dev_inl_004fc8a0,0x122,uVar3);
    }
  }
  DAT_006a5ed8 = uVar1;
  return;
}

