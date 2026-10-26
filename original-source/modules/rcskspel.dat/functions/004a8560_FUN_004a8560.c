/*
 * FUN_004a8560 at 004a8560
 * undefined FUN_004a8560(void)
 * Address ranges: 004a8560-004a89e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a8560(char *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar5;
  int iVar6;
  undefined1 *puVar7;
  char **ppcVar8;
  char *apcStack_78 [4];
  char *pcStack_68;
  char *pcStack_64;
  char *pcStack_60;
  char *pcStack_5c;
  undefined1 *local_48;
  undefined1 auStack_40 [32];
  undefined1 auStack_20 [32];
  
  local_48 = (undefined1 *)0x0;
  pcStack_5c = (char *)0x4a857a;
  FUN_004a8350();
  if (DAT_006a5eec == 0) {
    pcStack_5c = &DAT_006a5f0d;
    pcStack_60 = (char *)DAT_006a5ee4;
    pcStack_64 = &DAT_006a5ef4;
    pcStack_68 = (char *)0x196;
    apcStack_78[3] = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
    apcStack_78[2] = s__s__d____T_ARRAY__get_data__s__d_004fc788;
    apcStack_78[1] = (char *)0x4a85a7;
    FUN_004afee0();
  }
  if (((int)param_1 < 0) || (DAT_006a5ee4 <= (int)param_1)) {
    pcStack_5c = (char *)DAT_006a5ee4;
    pcStack_60 = param_1;
    pcStack_64 = &DAT_006a5ef4;
    pcStack_68 = (char *)0x196;
    apcStack_78[3] = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
    apcStack_78[2] = s__s__d____out_of_boundaries__s__d_004fc818;
    apcStack_78[1] = (char *)0x4a85d6;
    FUN_004afee0();
  }
  if (param_1[DAT_006a5ef0] == '\0') {
    pcStack_5c = param_1;
    pcStack_60 = &DAT_006a5ef4;
    pcStack_64 = (char *)0x196;
    pcStack_68 = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
    apcStack_78[3] = s__s__d____array_element_not_regis_004fc7e8;
    apcStack_78[2] = (char *)0x4a8604;
    FUN_004afee0();
  }
  iVar6 = (int)param_1 * 0xbc;
  iVar1 = *(int *)(iVar6 + 0x9c + DAT_006a5ee0);
  if (DAT_006a5eec == 0) {
    pcStack_5c = &DAT_006a5f0d;
    pcStack_64 = &DAT_006a5ef4;
    pcStack_68 = (char *)0x198;
    apcStack_78[3] = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
    apcStack_78[2] = s__s__d____T_ARRAY__get_data__s__d_004fc788;
    apcStack_78[1] = (char *)0x4a8651;
    pcStack_60 = (char *)DAT_006a5ee4;
    FUN_004afee0();
  }
  if (((int)param_1 < 0) || (DAT_006a5ee4 <= (int)param_1)) {
    pcStack_60 = param_1;
    pcStack_64 = &DAT_006a5ef4;
    pcStack_68 = (char *)0x198;
    apcStack_78[3] = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
    apcStack_78[2] = s__s__d____out_of_boundaries__s__d_004fc818;
    apcStack_78[1] = (char *)0x4a867c;
    pcStack_5c = (char *)DAT_006a5ee4;
    FUN_004afee0();
  }
  if (param_1[DAT_006a5ef0] == '\0') {
    pcStack_5c = param_1;
    pcStack_60 = &DAT_006a5ef4;
    pcStack_64 = (char *)0x198;
    pcStack_68 = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
    apcStack_78[3] = s__s__d____array_element_not_regis_004fc7e8;
    apcStack_78[2] = (char *)0x4a86aa;
    FUN_004afee0();
  }
  pcStack_60 = (char *)DAT_006a5ee4;
  if (*(int *)(iVar6 + DAT_006a5ee0) == 1) {
    if (DAT_006a5eec == 0) {
      pcStack_5c = &DAT_006a5f0d;
      pcStack_64 = &DAT_006a5ef4;
      pcStack_68 = (char *)0x19a;
      apcStack_78[3] = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
      apcStack_78[2] = s__s__d____T_ARRAY__get_data__s__d_004fc788;
      apcStack_78[1] = (char *)0x4a8848;
      FUN_004afee0();
    }
    if (((int)param_1 < 0) || (DAT_006a5ee4 <= (int)param_1)) {
      pcStack_60 = param_1;
      pcStack_64 = &DAT_006a5ef4;
      pcStack_68 = (char *)0x19a;
      apcStack_78[3] = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
      apcStack_78[2] = s__s__d____out_of_boundaries__s__d_004fc818;
      apcStack_78[1] = (char *)0x4a8873;
      pcStack_5c = (char *)DAT_006a5ee4;
      FUN_004afee0();
    }
    if (param_1[DAT_006a5ef0] == '\0') {
      pcStack_5c = param_1;
      pcStack_60 = &DAT_006a5ef4;
      pcStack_64 = (char *)0x19a;
      pcStack_68 = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
      apcStack_78[3] = s__s__d____array_element_not_regis_004fc7e8;
      apcStack_78[2] = (char *)0x4a889b;
      FUN_004afee0();
    }
    local_48 = *(undefined1 **)(iVar6 + 0x7c + DAT_006a5ee0);
  }
  else if (*(int *)(iVar6 + DAT_006a5ee0) == 2) {
    if (DAT_006a5eec == 0) {
      pcStack_5c = &DAT_006a5f0d;
      pcStack_64 = &DAT_006a5ef4;
      pcStack_68 = (char *)0x19d;
      apcStack_78[3] = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
      apcStack_78[2] = s__s__d____T_ARRAY__get_data__s__d_004fc788;
      apcStack_78[1] = (char *)0x4a87b7;
      FUN_004afee0();
    }
    if (((int)param_1 < 0) || (DAT_006a5ee4 <= (int)param_1)) {
      pcStack_60 = param_1;
      pcStack_64 = &DAT_006a5ef4;
      pcStack_68 = (char *)0x19d;
      apcStack_78[3] = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
      apcStack_78[2] = s__s__d____out_of_boundaries__s__d_004fc818;
      apcStack_78[1] = (char *)0x4a87e2;
      pcStack_5c = (char *)DAT_006a5ee4;
      FUN_004afee0();
    }
    if (param_1[DAT_006a5ef0] == '\0') {
      pcStack_5c = param_1;
      pcStack_60 = &DAT_006a5ef4;
      pcStack_64 = (char *)0x19d;
      pcStack_68 = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
      apcStack_78[3] = s__s__d____array_element_not_regis_004fc7e8;
      apcStack_78[2] = (char *)0x4a880a;
      FUN_004afee0();
    }
    local_48 = *(undefined1 **)(iVar6 + 0x84 + DAT_006a5ee0);
  }
  else {
    if (DAT_006a5eec == 0) {
      pcStack_5c = &DAT_006a5f0d;
      pcStack_64 = &DAT_006a5ef4;
      pcStack_68 = (char *)0x1a0;
      apcStack_78[3] = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
      apcStack_78[2] = s__s__d____T_ARRAY__get_data__s__d_004fc788;
      apcStack_78[1] = (char *)0x4a86f2;
      FUN_004afee0();
    }
    if (((int)param_1 < 0) || (DAT_006a5ee4 <= (int)param_1)) {
      pcStack_60 = param_1;
      pcStack_64 = &DAT_006a5ef4;
      pcStack_68 = (char *)0x1a0;
      apcStack_78[3] = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
      apcStack_78[2] = s__s__d____out_of_boundaries__s__d_004fc818;
      apcStack_78[1] = (char *)0x4a871d;
      pcStack_5c = (char *)DAT_006a5ee4;
      FUN_004afee0();
    }
    if (param_1[DAT_006a5ef0] == '\0') {
      pcStack_5c = param_1;
      pcStack_60 = &DAT_006a5ef4;
      pcStack_64 = (char *)0x1a0;
      pcStack_68 = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
      apcStack_78[3] = s__s__d____array_element_not_regis_004fc7e8;
      apcStack_78[2] = (char *)0x4a8745;
      FUN_004afee0();
    }
    puVar3 = (undefined4 *)(iVar6 + 0xa8 + DAT_006a5ee0);
    if (*(int *)(iVar6 + 0xac + DAT_006a5ee0) == 0) {
      pcStack_5c = (char *)0x24;
      pcStack_60 = s___str_h_004fcac4;
      pcStack_64 = s__s__d____string_is_not_initialis_004fb8fc;
      pcStack_68 = (char *)0x4a8771;
      FUN_004afee0();
    }
    pcStack_60 = (char *)*puVar3;
    pcStack_5c = param_1;
    pcStack_64 = (char *)0x1a0;
    pcStack_68 = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
    apcStack_78[3] = s__s__d____corrupt_mesh_type__duri_004fd230;
    apcStack_78[2] = (char *)0x4a878c;
    FUN_004afee0();
  }
  pcStack_60 = local_48;
  pcStack_64 = (char *)0x4a88b9;
  pcStack_5c = (char *)iVar1;
  FUN_004a8310();
  iVar6 = 0;
  if (0 < (int)local_48) {
    do {
      pcStack_5c = (char *)0x1a7;
      pcStack_60 = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
      pcStack_64 = param_1;
      pcStack_68 = (char *)0x4a88dc;
      piVar2 = (int *)FUN_004a12f0();
      pcStack_5c = (char *)iVar6;
      if (*piVar2 == 1) {
        pcStack_60 = auStack_40;
        pcStack_64 = (char *)0x1a8;
        pcStack_68 = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
        apcStack_78[3] = param_1;
        apcStack_78[2] = (char *)0x4a88fe;
        FUN_004a12f0();
        pcStack_64 = (char *)0x4a8905;
        puVar3 = (undefined4 *)FUN_004aa430();
        ppcVar8 = apcStack_78;
        for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
          *ppcVar8 = (char *)*puVar3;
          puVar3 = puVar3 + 1;
          ppcVar8 = ppcVar8 + 1;
        }
        FUN_004aa4b0(iVar6);
      }
      else {
        pcStack_60 = auStack_20;
        pcStack_64 = (char *)0x1aa;
        pcStack_68 = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
        apcStack_78[3] = param_1;
        apcStack_78[2] = (char *)0x4a8939;
        FUN_004a12f0();
        pcStack_64 = (char *)0x4a8940;
        puVar3 = (undefined4 *)FUN_004aa6d0();
        ppcVar8 = apcStack_78;
        for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
          *ppcVar8 = (char *)*puVar3;
          puVar3 = puVar3 + 1;
          ppcVar8 = ppcVar8 + 1;
        }
        FUN_004aa5c0(iVar6);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)local_48);
  }
  puVar7 = (undefined1 *)0x0;
  if (0 < iVar1) {
    do {
      pcStack_5c = (char *)0x1b0;
      pcStack_60 = s_D__work_libs_DX3D_Mesh_cpp_004fd124;
      pcStack_64 = param_1;
      pcStack_68 = (char *)0x4a8984;
      iVar6 = FUN_004a12f0();
      pcStack_5c = (char *)0x2e;
      pcStack_60 = s___mesh_inl_004fd168;
      pcStack_64 = (char *)0x4a8994;
      FUN_004aa390();
      if (((int)puVar7 < 0) || (uVar5 = extraout_var, *(int *)(iVar6 + 0x9c) <= (int)puVar7)) {
        pcStack_5c = *(char **)(iVar6 + 0x7c);
        pcStack_64 = (char *)0x32;
        pcStack_68 = s___mesh_inl_004fd168;
        apcStack_78[3] = s__s__d____getting_index____d___is_004fd18c;
        apcStack_78[2] = (char *)0x4a89b6;
        pcStack_60 = puVar7;
        FUN_004afee0();
        uVar5 = extraout_var_00;
      }
      pcStack_5c = (char *)CONCAT22(uVar5,*(undefined2 *)(*(int *)(iVar6 + 0x98) + (int)puVar7 * 2))
      ;
      pcStack_64 = (char *)0x4a89ce;
      pcStack_60 = puVar7;
      FUN_004aa3c0();
      puVar7 = puVar7 + 1;
    } while ((int)puVar7 < iVar1);
  }
  pcStack_5c = (char *)0x4a89dc;
  FUN_004aa040();
  return;
}

