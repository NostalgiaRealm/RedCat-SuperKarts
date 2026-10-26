/*
 * FUN_004a7a40 at 004a7a40
 * undefined FUN_004a7a40(void)
 * Address ranges: 004a7a40-004a7e03
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004a7a40(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  char *pcVar9;
  int iStack_28;
  undefined4 auStack_20 [6];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar3 = FUN_004a75e0();
  iVar5 = 0;
  if (DAT_006a5eec == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x7d,&DAT_006a5ef4,DAT_006a5ee4,&DAT_006a5f0d);
  }
  if ((iVar3 < 0) || (DAT_006a5ee4 <= iVar3)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x7d,&DAT_006a5ef4,iVar3,DAT_006a5ee4);
  }
  if (*(char *)(DAT_006a5ef0 + iVar3) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x7d,&DAT_006a5ef4,iVar3);
  }
  iVar6 = iVar3 * 0xbc;
  if (*(int *)(iVar6 + 4 + DAT_006a5ee0) == 0) {
    *(undefined4 *)(iVar6 + DAT_006a5ee0) = 2;
  }
  else {
    FUN_004afee0(s__s__d____illegal_change_of_mesh_t_004fd140,s___mesh_inl_004fd168,0x11);
  }
  if (DAT_006a5eec == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x7e,&DAT_006a5ef4,DAT_006a5ee4,&DAT_006a5f0d);
  }
  if ((iVar3 < 0) || (DAT_006a5ee4 <= iVar3)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x7e,&DAT_006a5ef4,iVar3,DAT_006a5ee4);
  }
  if (*(char *)(DAT_006a5ef0 + iVar3) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x7e,&DAT_006a5ef4,iVar3);
  }
  FUN_004a8310(param_2,param_4);
  iStack_28 = 0;
  if (0 < param_2) {
    do {
      if (DAT_006a5eec == 0) {
        FUN_004afee0(s__s__d____T_ARRAY__get_data__s__d_004fc788,
                     s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x82,&DAT_006a5ef4,DAT_006a5ee4,
                     &DAT_006a5f0d);
      }
      if ((iVar3 < 0) || (DAT_006a5ee4 <= iVar3)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,
                     s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x82,&DAT_006a5ef4,iVar3,DAT_006a5ee4);
      }
      if (*(char *)(DAT_006a5ef0 + iVar3) == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,
                     s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x82,&DAT_006a5ef4,iVar3);
      }
      puVar7 = (undefined4 *)(param_1 + iVar5);
      puVar8 = auStack_20;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      piVar1 = (int *)(iVar6 + DAT_006a5ee0);
      FUN_004aa390(s___mesh_inl_004fd168,0x76);
      if (*piVar1 == 1) {
        if ((iVar5 < 0) || (piVar1[0x1f] <= iStack_28)) {
          FUN_004afee0(s__s__d____error__d_out_of_mesh_LV_004fa6a0,s___mesh_inl_004fd168,0x82,
                       iStack_28,piVar1[0x21]);
        }
        *(undefined4 *)(piVar1[0x1e] + iVar5) = auStack_20[0];
        *(undefined4 *)(piVar1[0x1e] + 4 + iVar5) = auStack_20[1];
        *(undefined4 *)(piVar1[0x1e] + 8 + iVar5) = auStack_20[2];
        *(undefined4 *)(piVar1[0x1e] + 0xc + iVar5) = auStack_20[0];
        *(undefined4 *)(piVar1[0x1e] + 0x10 + iVar5) = auStack_20[1];
        *(undefined4 *)(piVar1[0x1e] + 0x14 + iVar5) = auStack_20[2];
        *(undefined4 *)(piVar1[0x1e] + 0x18 + iVar5) = uStack_8;
        *(undefined4 *)(piVar1[0x1e] + 0x1c + iVar5) = uStack_4;
      }
      else if (*piVar1 == 2) {
        if ((iVar5 < 0) || (piVar1[0x21] <= iStack_28)) {
          FUN_004afee0(s__s__d____error__d_out_of_mesh_LV_004fa6a0,s___mesh_inl_004fd168,0x7c,
                       iStack_28,piVar1[0x21]);
        }
        puVar7 = auStack_20;
        puVar8 = (undefined4 *)(piVar1[0x20] + iVar5);
        for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      iStack_28 = iStack_28 + 1;
      iVar5 = iVar5 + 0x20;
    } while (iStack_28 < param_2);
  }
  iVar5 = 0;
  if (0 < param_4) {
    do {
      uVar2 = *(undefined2 *)(param_3 + iVar5 * 2);
      iVar6 = FUN_004a12f0(iVar3,s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x85);
      FUN_004aa390(s___mesh_inl_004fd168,0x3c);
      if ((iVar5 < 0) || (*(int *)(iVar6 + 0x9c) <= iVar5)) {
        FUN_004afee0(s__s__d____getting_index____d___is_004fd18c,s___mesh_inl_004fd168,0x40,iVar5,
                     *(undefined4 *)(iVar6 + 0x7c));
      }
      iVar5 = iVar5 + 1;
      *(undefined2 *)(*(int *)(iVar6 + 0x98) + -2 + iVar5 * 2) = uVar2;
    } while (iVar5 < param_4);
  }
  FUN_004a12f0(iVar3,s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x87);
  FUN_004aa040();
  pcVar9 = s_static_mesh_004fd180;
  FUN_004a12f0(iVar3,s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x88);
  FUN_004ad120(pcVar9);
  return iVar3;
}

