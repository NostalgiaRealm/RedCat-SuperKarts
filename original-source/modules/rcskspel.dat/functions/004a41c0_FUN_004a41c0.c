/*
 * FUN_004a41c0 at 004a41c0
 * undefined FUN_004a41c0(void)
 * Address ranges: 004a41c0-004a467e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004a41c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  char **ppcVar5;
  char *apcStack_74 [8];
  int *piStack_54;
  int *piStack_50;
  char *pcStack_4c;
  char *pcStack_48;
  undefined4 *puStack_44;
  undefined *puStack_40;
  undefined *puStack_3c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puStack_3c = (undefined *)param_2;
  puStack_40 = (undefined *)0x4a41d6;
  FUN_004ad120();
  *(undefined4 *)(param_1 + 0x2c) = param_3;
  puStack_3c = (undefined *)0x4a41e2;
  puVar1 = (undefined4 *)FUN_004ae4a0();
  ppcVar5 = apcStack_74 + 7;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppcVar5 = (char *)*puVar1;
    puVar1 = puVar1 + 1;
    ppcVar5 = ppcVar5 + 1;
  }
  apcStack_74[6] = (char *)0x4a41f5;
  FUN_004b5c20();
  apcStack_74[6] = (char *)0x4a41fa;
  apcStack_74[6] = (char *)FUN_004ae4a0();
  apcStack_74[4] = (char *)&local_24;
  apcStack_74[5] = (char *)0x1800;
  apcStack_74[3] = (char *)&local_28;
  apcStack_74[2] = (char *)param_2;
  apcStack_74[1] = (char *)0x4a4210;
  uVar2 = FUN_004a3c50();
  *(undefined4 *)(param_1 + 4) = uVar2;
  apcStack_74[1] = (char *)0x4a4218;
  puVar1 = (undefined4 *)FUN_004ae4a0();
  ppcVar5 = apcStack_74 + 7;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppcVar5 = (char *)*puVar1;
    puVar1 = puVar1 + 1;
    ppcVar5 = ppcVar5 + 1;
  }
  apcStack_74[6] = (char *)0x4a422b;
  FUN_004b5c20();
  *(undefined4 *)(param_1 + 0x24) = local_28;
  *(undefined4 *)(param_1 + 0x28) = local_24;
  *(float *)(param_1 + 0x34) = DAT_006a5ec8;
  *(float *)(param_1 + 0x3c) = _DAT_006a5ed0 + DAT_006a5ec8;
  *(float *)(param_1 + 0x38) = DAT_006a5ecc;
  *(float *)(param_1 + 0x40) = _DAT_006a5ed4 + DAT_006a5ecc;
  if (DAT_006a5e8c == 0) {
    puStack_3c = &DAT_006a5ead;
    puStack_40 = DAT_006a5e84;
    puStack_44 = (undefined4 *)&DAT_006a5e94;
    pcStack_48 = (char *)0x1f0;
    pcStack_4c = s_D__work_libs_DX3D_text_cpp_004fca28;
    piStack_50 = (int *)s__s__d____T_ARRAY__get_data__s__d_004fc788;
    piStack_54 = (int *)0x4a429a;
    FUN_004afee0();
  }
  if ((int)DAT_006a5e84 < 1) {
    puStack_3c = DAT_006a5e84;
    puStack_40 = (undefined *)0x0;
    puStack_44 = (undefined4 *)&DAT_006a5e94;
    pcStack_48 = (char *)0x1f0;
    pcStack_4c = s_D__work_libs_DX3D_text_cpp_004fca28;
    piStack_50 = (int *)s__s__d____out_of_boundaries__s__d_004fc818;
    piStack_54 = (int *)0x4a42c2;
    FUN_004afee0();
  }
  if (*DAT_006a5e90 == '\0') {
    puStack_3c = (undefined *)0x0;
    puStack_40 = &DAT_006a5e94;
    puStack_44 = (undefined4 *)0x1f0;
    pcStack_48 = s_D__work_libs_DX3D_text_cpp_004fca28;
    pcStack_4c = s__s__d____array_element_not_regis_004fc7e8;
    piStack_50 = (int *)0x4a42ef;
    FUN_004afee0();
  }
  puVar4 = DAT_006a5e84;
  puStack_3c = (undefined *)0x4a4308;
  uStack_20 = __ftol();
  puStack_3c = puVar4;
  if (DAT_006a5e8c == 0) {
    puStack_3c = &DAT_006a5ead;
    puStack_44 = (undefined4 *)&DAT_006a5e94;
    pcStack_48 = (char *)0x1f1;
    pcStack_4c = s_D__work_libs_DX3D_text_cpp_004fca28;
    piStack_50 = (int *)s__s__d____T_ARRAY__get_data__s__d_004fc788;
    piStack_54 = (int *)0x4a4334;
    puStack_40 = puVar4;
    FUN_004afee0();
    puStack_3c = DAT_006a5e84;
  }
  if ((int)puStack_3c < 1) {
    puStack_40 = (undefined *)0x0;
    puStack_44 = (undefined4 *)&DAT_006a5e94;
    pcStack_48 = (char *)0x1f1;
    pcStack_4c = s_D__work_libs_DX3D_text_cpp_004fca28;
    piStack_50 = (int *)s__s__d____out_of_boundaries__s__d_004fc818;
    piStack_54 = (int *)0x4a435c;
    FUN_004afee0();
    puStack_3c = DAT_006a5e84;
  }
  puVar4 = puStack_3c;
  if (*DAT_006a5e90 == '\0') {
    puStack_3c = (undefined *)0x0;
    puStack_40 = &DAT_006a5e94;
    puStack_44 = (undefined4 *)0x1f1;
    pcStack_48 = s_D__work_libs_DX3D_text_cpp_004fca28;
    pcStack_4c = s__s__d____array_element_not_regis_004fc7e8;
    piStack_50 = (int *)0x4a4389;
    FUN_004afee0();
    puVar4 = DAT_006a5e84;
  }
  puStack_3c = (undefined *)0x4a43a3;
  uStack_18 = __ftol();
  puStack_3c = puVar4;
  if (DAT_006a5e8c == 0) {
    puStack_3c = &DAT_006a5ead;
    puStack_44 = (undefined4 *)&DAT_006a5e94;
    pcStack_48 = (char *)0x1f2;
    pcStack_4c = s_D__work_libs_DX3D_text_cpp_004fca28;
    piStack_50 = (int *)s__s__d____T_ARRAY__get_data__s__d_004fc788;
    piStack_54 = (int *)0x4a43cf;
    puStack_40 = puVar4;
    FUN_004afee0();
    puStack_3c = DAT_006a5e84;
  }
  if ((int)puStack_3c < 1) {
    puStack_40 = (undefined *)0x0;
    puStack_44 = (undefined4 *)&DAT_006a5e94;
    pcStack_48 = (char *)0x1f2;
    pcStack_4c = s_D__work_libs_DX3D_text_cpp_004fca28;
    piStack_50 = (int *)s__s__d____out_of_boundaries__s__d_004fc818;
    piStack_54 = (int *)0x4a43f7;
    FUN_004afee0();
    puStack_3c = DAT_006a5e84;
  }
  puVar4 = puStack_3c;
  if (*DAT_006a5e90 == '\0') {
    puStack_3c = (undefined *)0x0;
    puStack_40 = &DAT_006a5e94;
    puStack_44 = (undefined4 *)0x1f2;
    pcStack_48 = s_D__work_libs_DX3D_text_cpp_004fca28;
    pcStack_4c = s__s__d____array_element_not_regis_004fc7e8;
    piStack_50 = (int *)0x4a4423;
    FUN_004afee0();
    puVar4 = DAT_006a5e84;
  }
  puStack_3c = (undefined *)0x4a443d;
  uStack_1c = __ftol();
  puStack_3c = puVar4;
  if (DAT_006a5e8c == 0) {
    puStack_3c = &DAT_006a5ead;
    puStack_44 = (undefined4 *)&DAT_006a5e94;
    pcStack_48 = (char *)0x1f3;
    pcStack_4c = s_D__work_libs_DX3D_text_cpp_004fca28;
    piStack_50 = (int *)s__s__d____T_ARRAY__get_data__s__d_004fc788;
    piStack_54 = (int *)0x4a4469;
    puStack_40 = puVar4;
    FUN_004afee0();
    puStack_3c = DAT_006a5e84;
  }
  if ((int)puStack_3c < 1) {
    puStack_40 = (undefined *)0x0;
    puStack_44 = (undefined4 *)&DAT_006a5e94;
    pcStack_48 = (char *)0x1f3;
    pcStack_4c = s_D__work_libs_DX3D_text_cpp_004fca28;
    piStack_50 = (int *)s__s__d____out_of_boundaries__s__d_004fc818;
    piStack_54 = (int *)0x4a4491;
    FUN_004afee0();
  }
  if (*DAT_006a5e90 == '\0') {
    puStack_3c = (undefined *)0x0;
    puStack_40 = &DAT_006a5e94;
    puStack_44 = (undefined4 *)0x1f3;
    pcStack_48 = s_D__work_libs_DX3D_text_cpp_004fca28;
    pcStack_4c = s__s__d____array_element_not_regis_004fc7e8;
    piStack_50 = (int *)0x4a44b8;
    FUN_004afee0();
  }
  puStack_3c = (undefined *)0x4a44cb;
  puStack_3c = (undefined *)__ftol();
  puStack_40 = (undefined *)uStack_18;
  puStack_44 = (undefined4 *)uStack_1c;
  pcStack_48 = (char *)uStack_20;
  pcStack_4c = s_dest__d__d___d__d_004fccf8;
  piStack_50 = (int *)0x4a44e9;
  uStack_14 = puStack_3c;
  FUN_004afce0();
  piStack_50 = *(int **)(param_1 + 0x28);
  piStack_54 = *(int **)(param_1 + 0x24);
  apcStack_74[7] = (char *)0x0;
  apcStack_74[6] = (char *)0x0;
  apcStack_74[5] = s_src__d__d___d__d_004fcce4;
  uStack_10 = 0;
  uStack_c = 0;
  apcStack_74[4] = (char *)0x4a450d;
  uStack_8 = piStack_54;
  uStack_4 = piStack_50;
  FUN_004afce0();
  if (DAT_006a5e8c == 0) {
    puStack_3c = &DAT_006a5ead;
    puStack_40 = DAT_006a5e84;
    puStack_44 = (undefined4 *)&DAT_006a5e94;
    pcStack_48 = (char *)0x200;
    pcStack_4c = s_D__work_libs_DX3D_text_cpp_004fca28;
    piStack_50 = (int *)s__s__d____T_ARRAY__get_data__s__d_004fc788;
    piStack_54 = (int *)0x4a453e;
    FUN_004afee0();
  }
  if ((int)DAT_006a5e84 < 1) {
    puStack_3c = DAT_006a5e84;
    puStack_40 = (undefined *)0x0;
    puStack_44 = (undefined4 *)&DAT_006a5e94;
    pcStack_48 = (char *)0x200;
    pcStack_4c = s_D__work_libs_DX3D_text_cpp_004fca28;
    piStack_50 = (int *)s__s__d____out_of_boundaries__s__d_004fc818;
    piStack_54 = (int *)0x4a4565;
    FUN_004afee0();
  }
  if (*DAT_006a5e90 == '\0') {
    puStack_3c = (undefined *)0x0;
    puStack_40 = &DAT_006a5e94;
    puStack_44 = (undefined4 *)0x200;
    pcStack_48 = s_D__work_libs_DX3D_text_cpp_004fca28;
    pcStack_4c = s__s__d____array_element_not_regis_004fc7e8;
    piStack_50 = (int *)0x4a458c;
    FUN_004afee0();
  }
  puStack_3c = (undefined *)0x0;
  puStack_44 = &uStack_10;
  puStack_40 = (undefined *)0x1000000;
  piStack_50 = *(int **)(DAT_006a5e80 + 4);
  pcStack_48 = *(char **)(param_1 + 4);
  pcStack_4c = (char *)&uStack_20;
  piStack_54 = (int *)0x4a45b1;
  piStack_54 = (int *)(**(code **)(*piStack_50 + 0x14))();
  if (piStack_54 != (int *)0x0) {
    apcStack_74[7] = "Ph\x01\x02";
    apcStack_74[7] = (char *)FUN_004b0190();
    apcStack_74[6] = (char *)0x201;
    apcStack_74[5] = s_D__work_libs_DX3D_text_cpp_004fca28;
    apcStack_74[4] = s__s__d____blt_surf_2_surf_blittin_004fcc74;
    apcStack_74[3] = (char *)0x4a45d0;
    FUN_004afee0();
  }
  piStack_54 = *(int **)(param_1 + 4);
  apcStack_74[7] = (char *)0x4a45dc;
  (**(code **)(*piStack_54 + 8))();
  *(undefined4 *)(param_1 + 4) = 0;
  DAT_006a5ec8 = _DAT_006a5ed0 + DAT_006a5ec8;
  if (1.0 <= DAT_006a5ec8) {
    DAT_006a5ecc = _DAT_006a5ed4 + DAT_006a5ecc;
    if (1.0 <= DAT_006a5ecc) {
      apcStack_74[7] = (char *)uStack_18;
      apcStack_74[6] = (char *)0x20c;
      apcStack_74[5] = s_D__work_libs_DX3D_text_cpp_004fca28;
      apcStack_74[4] = s__s__d____out_of_main_texture_spa_004fcca4;
      apcStack_74[3] = (char *)0x4a4636;
      FUN_004afee0();
    }
    DAT_006a5ec8 = 0.0;
  }
  puVar1 = &DAT_006ab7c8;
  ppcVar5 = apcStack_74;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppcVar5 = (char *)*puVar1;
    puVar1 = puVar1 + 1;
    ppcVar5 = ppcVar5 + 1;
  }
  FUN_004b5c20();
  apcStack_74[7] = (char *)0x4a4666;
  iVar3 = FUN_004ae830();
  if (iVar3 != 0) {
    apcStack_74[7] = (char *)0x0;
    apcStack_74[6] = (char *)0x4a4670;
    FUN_004a46e0();
  }
  return 0;
}

