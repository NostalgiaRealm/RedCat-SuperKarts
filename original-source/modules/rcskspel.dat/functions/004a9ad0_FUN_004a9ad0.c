/*
 * FUN_004a9ad0 at 004a9ad0
 * undefined FUN_004a9ad0(void)
 * Address ranges: 004a9ad0-004aa03d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_004a9ad0(int *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iStack_cc;
  int iStack_c4;
  int iStack_c0;
  int local_bc;
  undefined2 uStack_b8;
  undefined2 uStack_b6;
  undefined2 uStack_b4;
  undefined4 auStack_ac [4];
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 auStack_8c [4];
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 auStack_58 [9];
  undefined4 auStack_34 [13];
  
  FUN_004ad120(param_2);
  FUN_004afce0(s______LOADING_MESH______004fd3e8);
  FUN_004afce0(s_mesh_____s__004fd3d4,param_2);
  iVar1 = FUN_004b96d0(param_2);
  iVar6 = 0;
  if (iVar1 == 0) {
    FUN_004afee0(s__s__d____Unable_to_load_object__c_004fd3a0,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x318,param_2);
  }
  FUN_004bf930(&local_bc,1,4,iVar1);
  if (local_bc < 0) {
    FUN_004bf930(&iStack_c4,1,4,iVar1);
  }
  else {
    iStack_c4 = local_bc;
    local_bc = 0;
  }
  FUN_004bf930(&iStack_c0,1,4,iVar1);
  FUN_004a8310(iStack_c4,iStack_c0 * 3);
  FUN_004afce0(s_vertices____d_004fd390,iStack_c4);
  FUN_004afce0(s_triangles____d_004fd380,iStack_c0);
  FUN_004afce0(s_load_vertex_data___004fd36c);
  iStack_cc = 0;
  if (0 < iStack_c4) {
    do {
      if (local_bc == -1) {
        FUN_004bf930(auStack_34,1,0x31,iVar1);
        iVar9 = param_1[1];
        puVar7 = auStack_34;
        puVar8 = auStack_8c;
        for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
        if (iVar9 == 0) {
          FUN_004afee0(s__s__d____mesh_has_not_been_initi_004fd30c,s___mesh_inl_004fd168,0xb8);
        }
        if (*param_1 == 1) {
          if ((iVar6 < 0) || (param_1[0x1f] <= iStack_cc)) {
            FUN_004afee0(s__s__d____error__d_out_of_mesh_LV_004fa6a0,s___mesh_inl_004fd168,0xcd,
                         iStack_cc,param_1[0x21]);
          }
          *(undefined4 *)(iVar6 + param_1[0x1e]) = auStack_8c[0];
          *(undefined4 *)(iVar6 + 4 + param_1[0x1e]) = auStack_8c[1];
          *(undefined4 *)(iVar6 + 8 + param_1[0x1e]) = auStack_8c[2];
          *(undefined4 *)(iVar6 + 0xc + param_1[0x1e]) = auStack_8c[3];
          *(undefined4 *)(iVar6 + 0x10 + param_1[0x1e]) = uStack_7c;
          *(undefined4 *)(iVar6 + 0x14 + param_1[0x1e]) = uStack_78;
          *(undefined4 *)(iVar6 + 0x18 + param_1[0x1e]) = uStack_74;
          *(undefined4 *)(iVar6 + 0x1c + param_1[0x1e]) = uStack_70;
        }
        else if (*param_1 == 2) {
          if ((iVar6 < 0) || (param_1[0x21] <= iStack_cc)) {
            FUN_004afee0(s__s__d____error__d_out_of_mesh_LV_004fa6a0,s___mesh_inl_004fd168,0xbe,
                         iStack_cc,param_1[0x21]);
          }
          *(undefined4 *)(param_1[0x20] + iVar6) = auStack_8c[0];
          *(undefined4 *)(param_1[0x20] + 4 + iVar6) = auStack_8c[1];
          *(undefined4 *)(param_1[0x20] + 8 + iVar6) = auStack_8c[2];
          *(undefined4 *)(param_1[0x20] + 0x18 + iVar6) = uStack_74;
          *(undefined4 *)(param_1[0x20] + 0x1c + iVar6) = uStack_70;
          iVar9 = __ftol();
          uVar2 = __ftol();
          uVar3 = __ftol();
          uVar4 = __ftol();
          *(uint *)(param_1[0x20] + 0x10 + iVar6) = ((iVar9 << 8 | uVar2) << 8 | uVar3) << 8 | uVar4
          ;
          *(undefined4 *)(param_1[0x20] + 0x14 + iVar6) = 0;
        }
      }
      else if (local_bc == 0) {
        FUN_004bf930(auStack_58,1,0x21,iVar1);
        iVar9 = param_1[1];
        puVar7 = auStack_58;
        puVar8 = auStack_ac;
        for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        if (iVar9 == 0) {
          FUN_004afee0(s__s__d____mesh_has_not_been_initi_004fd30c,s___mesh_inl_004fd168,0x94);
        }
        if (*param_1 == 1) {
          if ((iVar6 < 0) || (param_1[0x1f] <= iStack_cc)) {
            FUN_004afee0(s__s__d____error__d_out_of_mesh_LV_004fa6a0,s___mesh_inl_004fd168,0xa6,
                         iStack_cc,param_1[0x21]);
          }
          *(undefined4 *)(iVar6 + param_1[0x1e]) = auStack_ac[0];
          *(undefined4 *)(iVar6 + 4 + param_1[0x1e]) = auStack_ac[1];
          *(undefined4 *)(iVar6 + 8 + param_1[0x1e]) = auStack_ac[2];
          *(undefined4 *)(iVar6 + 0xc + param_1[0x1e]) = auStack_ac[3];
          *(undefined4 *)(iVar6 + 0x10 + param_1[0x1e]) = uStack_9c;
          *(undefined4 *)(iVar6 + 0x14 + param_1[0x1e]) = uStack_98;
          *(undefined4 *)(iVar6 + 0x18 + param_1[0x1e]) = uStack_94;
          *(undefined4 *)(iVar6 + 0x1c + param_1[0x1e]) = uStack_90;
        }
        else if (*param_1 == 2) {
          if ((iVar6 < 0) || (param_1[0x21] <= iStack_cc)) {
            FUN_004afee0(s__s__d____error__d_out_of_mesh_LV_004fa6a0,s___mesh_inl_004fd168,0x9a,
                         iStack_cc,param_1[0x21]);
          }
          *(undefined4 *)(param_1[0x20] + iVar6) = auStack_ac[0];
          *(undefined4 *)(param_1[0x20] + 4 + iVar6) = auStack_ac[1];
          *(undefined4 *)(param_1[0x20] + 8 + iVar6) = auStack_ac[2];
          *(undefined4 *)(param_1[0x20] + 0x18 + iVar6) = uStack_94;
          *(undefined4 *)(param_1[0x20] + 0x1c + iVar6) = uStack_90;
          *(undefined4 *)(param_1[0x20] + 0x10 + iVar6) = 0xffffff;
          *(undefined4 *)(param_1[0x20] + 0x14 + iVar6) = 0;
        }
      }
      else {
        FUN_004afee0(s__s__d____unsupported_version_num_004fd338,
                     s_D__work_libs_DX3D_Mesh_cpp_004fd124,0x342,local_bc,param_2);
      }
      if ((*(byte *)(iVar1 + 0xc) & 0x20) != 0) {
        FUN_004afee0(s__s__d____error_reading_<_s>_004fd2ec,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                     0x347,param_2);
      }
      iStack_cc = iStack_cc + 1;
      iVar6 = iVar6 + 0x20;
    } while (iStack_cc < iStack_c4);
  }
  FUN_004afce0(&DAT_004fd2e8);
  FUN_004afce0(s_loading_triangle_data___004fd2cc);
  iVar6 = 0;
  if (0 < iStack_c0) {
    iVar9 = 0;
    do {
      FUN_004bf930(&uStack_b8,1,9,iVar1);
      *(undefined2 *)(iVar9 + param_1[0x26]) = uStack_b8;
      *(undefined2 *)(iVar9 + 2 + param_1[0x26]) = uStack_b6;
      *(undefined2 *)(iVar9 + 4 + param_1[0x26]) = uStack_b4;
      if ((*(byte *)(iVar1 + 0xc) & 0x20) != 0) {
        FUN_004afee0(s__s__d____error_reading_<_s>_004fd2ec,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                     0x356,param_2);
      }
      iVar6 = iVar6 + 1;
      iVar9 = iVar9 + 6;
    } while (iVar6 < iStack_c0);
  }
  FUN_004afce0(&DAT_004fd2e8);
  FUN_004aa040();
  FUN_004b9840(iVar1);
  return 0;
}

