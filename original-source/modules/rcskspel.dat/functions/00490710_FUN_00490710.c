/*
 * FUN_00490710 at 00490710
 * undefined FUN_00490710(void)
 * Address ranges: 00490710-00490cd0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00490710(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  float afStack_40 [6];
  undefined4 uStack_28;
  undefined4 uStack_24;
  float afStack_20 [6];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (param_3 != -1) {
    if ((*(int *)(param_1 + 0xcc) != -1) && (*(int *)(param_1 + 200) != -1)) {
      FUN_004afce0(s_Checking_object_type____004fa8b8);
      iVar1 = *(int *)(DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9);
      if (iVar1 == 1) {
        FUN_004afce0(s_Standard__004fa8a4);
        iVar5 = *(int *)(DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9 + 0x99);
      }
      else {
        iVar5 = param_3;
        if (iVar1 == 2) {
          FUN_004afce0(s_Anim__004fa8b0);
          iVar1 = *(int *)(param_1 + 0xc);
          iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_006a5c38 + iVar1 + 4 + iVar1 * 0xa8) * 9 +
                                             4 + DAT_006a5f78) +
                                   *(int *)(DAT_006a5c38 + iVar1 + iVar1 * 0xa8 + 8) * 4) * 0x10 +
                          DAT_006a5f30);
        }
      }
      FUN_004afce0(s_Hmmm_004fa89c);
      if (*(int *)(param_1 + 200) != iVar5) {
        FUN_004afee0(s__s__d___Mesh_used_by_object_has_c_004fa870,
                     s_D__work_rcsk_Code_Engine_Prog_ob_004fa444,0x29a);
      }
      FUN_004afce0(s_Hmmm_1_004fa868);
      iVar1 = *(int *)(DAT_006847d0 + *(int *)(param_1 + 200) * 4);
      if ((((param_3 < 0) || (*(int *)(iVar1 + 4) <= param_3)) || (param_2 < 0)) || (7 < param_2)) {
        FUN_004afee0(s__s__d___Invalid_parameter__m_lev_004fa7f4,
                     s_D__work_rcsk_Code_Engine_Prog_ob_004fa83c,0x3a,*(undefined4 *)(iVar1 + 4),
                     param_3,param_2);
      }
      iVar1 = *(int *)(*(int *)(iVar1 + 8) + param_3 * 4) + param_2 * 0xc;
      FUN_004afce0(s_Hmmm_2_004fa7ec);
      FUN_004afce0(s_Euh__hallo__004fa7dc);
      FUN_004afce0(s_l_changes_>get_change_count_______004fa7b4,*(undefined4 *)(iVar1 + 4));
      iVar5 = 0;
      param_3 = 0;
      FUN_004afce0(s_Euh__hallo__004fa7dc);
      if (0 < *(int *)(iVar1 + 4)) {
        param_2 = 0;
        do {
          FUN_004afce0(s_Hmmm__d_A_004fa7a8,param_3);
          piVar3 = (int *)(param_2 + *(int *)(iVar1 + 8));
          if (*(int *)(DAT_006a5ee0 + 0x7c + *(int *)(param_1 + 200) * 0xbc) != 0) {
            FUN_004afce0(s_Hmmm__d_B_004fa79c,param_3);
            iVar4 = *piVar3;
            iVar5 = DAT_006a5ee0 + *(int *)(param_1 + 200) * 0xbc;
            if (*(int *)(DAT_006a5ee0 + *(int *)(param_1 + 200) * 0xbc) != 1) {
              FUN_004afee0(s__s__d____mesh_is_not_of_requeste_004fa744,
                           s_______Libs_Win3DLib_Include_mesh_004fa774,0x4b);
            }
            if (*(int *)(iVar5 + 4) != 1) {
              FUN_004afee0(s__s__d____vertices_were_not__yet__004fa714,
                           s_______Libs_Win3DLib_Include_mesh_004fa774,0x4e);
            }
            if ((iVar4 < 0) || (*(int *)(iVar5 + 0x7c) <= iVar4)) {
              FUN_004afee0(s__s__d____index__d_is_out_of_VERT_004fa6e0,
                           s_______Libs_Win3DLib_Include_mesh_004fa774,0x51,iVar4,
                           *(undefined4 *)(iVar5 + 0x7c));
            }
            pfVar6 = (float *)(*(int *)(iVar5 + 0x78) + iVar4 * 0x20);
            pfVar7 = afStack_20;
            for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
              *pfVar7 = *pfVar6;
              pfVar6 = pfVar6 + 1;
              pfVar7 = pfVar7 + 1;
            }
            afStack_20[0] = afStack_20[0] + (float)piVar3[1];
            afStack_20[1] = afStack_20[1] + (float)piVar3[2];
            iVar4 = *piVar3;
            afStack_20[2] = afStack_20[2] + (float)piVar3[3];
            iVar5 = DAT_006a5ee0 + *(int *)(param_1 + 0xcc) * 0xbc;
            iVar2 = *(int *)(DAT_006a5ee0 + *(int *)(param_1 + 0xcc) * 0xbc);
            if (iVar2 == 1) {
              if ((iVar4 < 0) || (*(int *)(iVar5 + 0x7c) <= iVar4)) {
                FUN_004afee0(s__s__d____error__d_out_of_mesh_LV_004fa6a0,
                             s_______Libs_Win3DLib_Include_mesh_004fa774,0x6b,iVar4,
                             *(undefined4 *)(iVar5 + 0x84));
              }
              pfVar6 = afStack_20;
              pfVar7 = (float *)(*(int *)(iVar5 + 0x78) + iVar4 * 0x20);
              for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
                *pfVar7 = *pfVar6;
                pfVar6 = pfVar6 + 1;
                pfVar7 = pfVar7 + 1;
              }
            }
            else if (iVar2 == 2) {
              if ((iVar4 < 0) || (*(int *)(iVar5 + 0x84) <= iVar4)) {
                FUN_004afee0(s__s__d____error__d_out_of_mesh_LV_004fa6a0,
                             s_______Libs_Win3DLib_Include_mesh_004fa774,0x5f,iVar4,
                             *(undefined4 *)(iVar5 + 0x84));
              }
              iVar4 = iVar4 * 0x20;
              *(float *)(*(int *)(iVar5 + 0x80) + iVar4) = afStack_20[0];
              *(float *)(*(int *)(iVar5 + 0x80) + 4 + iVar4) = afStack_20[1];
              *(float *)(*(int *)(iVar5 + 0x80) + 8 + iVar4) = afStack_20[2];
              *(undefined4 *)(*(int *)(iVar5 + 0x80) + 0x18 + iVar4) = uStack_8;
              *(undefined4 *)(*(int *)(iVar5 + 0x80) + 0x1c + iVar4) = uStack_4;
              *(undefined4 *)(*(int *)(iVar5 + 0x80) + 0x10 + iVar4) = 0xffffff;
              *(undefined4 *)(*(int *)(iVar5 + 0x80) + 0x14 + iVar4) = 0;
            }
          }
          if (*(int *)(DAT_006a5ee0 + 0x84 + *(int *)(param_1 + 200) * 0xbc) != 0) {
            FUN_004afce0(s_Hmmm__d_C_004fa694,param_3);
            iVar4 = *piVar3;
            iVar5 = DAT_006a5ee0 + *(int *)(param_1 + 200) * 0xbc;
            if (*(int *)(DAT_006a5ee0 + *(int *)(param_1 + 200) * 0xbc) != 2) {
              FUN_004afee0(s__s__d____mesh_is_not_of_requeste_004fa660,
                           s_______Libs_Win3DLib_Include_mesh_004fa774,0xe0);
            }
            if (*(int *)(iVar5 + 4) != 2) {
              FUN_004afee0(s__s__d____vertices_were_not__yet__004fa714,
                           s_______Libs_Win3DLib_Include_mesh_004fa774,0xe3);
            }
            if ((iVar4 < 0) || (*(int *)(iVar5 + 0x84) <= iVar4)) {
              FUN_004afee0(s__s__d____index__d_is_out_of_LVER_004fa628,
                           s_______Libs_Win3DLib_Include_mesh_004fa774,0xe6,iVar4,
                           *(undefined4 *)(iVar5 + 0x7c));
            }
            pfVar6 = (float *)(*(int *)(iVar5 + 0x80) + iVar4 * 0x20);
            pfVar7 = afStack_40;
            for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
              *pfVar7 = *pfVar6;
              pfVar6 = pfVar6 + 1;
              pfVar7 = pfVar7 + 1;
            }
            afStack_40[0] = afStack_40[0] + (float)piVar3[1];
            afStack_40[1] = afStack_40[1] + (float)piVar3[2];
            iVar4 = *piVar3;
            iVar2 = *(int *)(DAT_006a5ee0 + *(int *)(param_1 + 0xcc) * 0xbc);
            afStack_40[2] = afStack_40[2] + (float)piVar3[3];
            iVar5 = DAT_006a5ee0 + *(int *)(param_1 + 0xcc) * 0xbc;
            if (iVar2 == 1) {
              if ((iVar4 < 0) || (*(int *)(iVar5 + 0x7c) <= iVar4)) {
                FUN_004afee0(s__s__d____error__d_out_of_mesh_LV_004fa6a0,
                             s_______Libs_Win3DLib_Include_mesh_004fa774,0x82,iVar4,
                             *(undefined4 *)(iVar5 + 0x84));
              }
              iVar4 = iVar4 * 0x20;
              *(float *)(*(int *)(iVar5 + 0x78) + iVar4) = afStack_40[0];
              *(float *)(*(int *)(iVar5 + 0x78) + 4 + iVar4) = afStack_40[1];
              *(float *)(*(int *)(iVar5 + 0x78) + 8 + iVar4) = afStack_40[2];
              *(float *)(*(int *)(iVar5 + 0x78) + 0xc + iVar4) = afStack_40[0];
              *(float *)(*(int *)(iVar5 + 0x78) + 0x10 + iVar4) = afStack_40[1];
              *(float *)(*(int *)(iVar5 + 0x78) + 0x14 + iVar4) = afStack_40[2];
              *(undefined4 *)(*(int *)(iVar5 + 0x78) + 0x18 + iVar4) = uStack_28;
              *(undefined4 *)(*(int *)(iVar5 + 0x78) + 0x1c + iVar4) = uStack_24;
            }
            else if (iVar2 == 2) {
              if ((iVar4 < 0) || (*(int *)(iVar5 + 0x84) <= iVar4)) {
                FUN_004afee0(s__s__d____error__d_out_of_mesh_LV_004fa6a0,
                             s_______Libs_Win3DLib_Include_mesh_004fa774,0x7c,iVar4,
                             *(undefined4 *)(iVar5 + 0x84));
              }
              pfVar6 = afStack_40;
              pfVar7 = (float *)(*(int *)(iVar5 + 0x80) + iVar4 * 0x20);
              for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
                *pfVar7 = *pfVar6;
                pfVar6 = pfVar6 + 1;
                pfVar7 = pfVar7 + 1;
              }
            }
          }
          iVar5 = param_3 + 1;
          param_2 = param_2 + 0x10;
          FUN_004afce0(s_Euh__hallo__004fa7dc);
          param_3 = iVar5;
        } while (iVar5 < *(int *)(iVar1 + 4));
      }
      FUN_004afce0(s_Hmmm__d_004fa61c,iVar5);
      return;
    }
    FUN_004afce0(s__s__d___Cannot_apply_damage_to_u_004fa5e4,
                 s_D__work_rcsk_Code_Engine_Prog_ob_004fa444,0x283);
  }
  return;
}

