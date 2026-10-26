/*
 * FUN_004b64c0 at 004b64c0
 * undefined FUN_004b64c0(void)
 * Address ranges: 004b64c0-004b6ae1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b64c0(int param_1,int param_2,int param_3,int param_4,byte param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_retaddr;
  undefined4 uVar7;
  int *piVar8;
  int iStack_2c;
  int iStack_28;
  undefined4 local_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  local_24 = 0x1008000;
  if ((param_2 < 0) || (DAT_00501110 < param_2)) {
    FUN_004afee0(s__s__d____illegal_array_index__d_00500ea8,
                 s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x2b2,param_2);
  }
  iVar6 = param_2 * 0x20;
  if (*(int *)(iVar6 + 0x1c + DAT_006ab880) == 0) {
    FUN_004afee0(s__s__d____blt_with_unallocated_me_00500e78,
                 s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x2b5,param_2);
  }
  if (*(int *)(iVar6 + 0x18 + DAT_006ab880) == 4) {
    if (param_1 == 0) {
      param_2 = FUN_004b0530(DAT_006a64bc);
      iStack_28 = DAT_006a643c;
    }
    else if (param_1 == 1) {
      param_2 = FUN_004b0530(DAT_006a64c0);
      iStack_28 = DAT_006a64a8;
    }
    else if (param_1 == 2) {
      param_2 = FUN_004b0530(DAT_006a64a0);
      iStack_28 = DAT_006a64b8;
    }
    else {
      FUN_004afee0(s__s__d____unidentified_focus_erro_004ff408,
                   s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x2c8,param_1);
    }
    iVar3 = *(int *)(iVar6 + 0xc + DAT_006ab880);
    iVar4 = *(int *)(iVar6 + 8 + DAT_006ab880);
    iVar5 = param_3;
    if ((param_5 & 2) == 0) {
      param_4 = param_4 - *(int *)(iVar6 + 0x14 + DAT_006ab880);
      iVar5 = param_3 - *(int *)(iVar6 + 0x10 + DAT_006ab880);
    }
    param_3 = *(int *)(iVar6 + DAT_006ab880);
    if ((param_5 & 1) == 0) {
      iVar6 = 0;
LAB_004b6715:
      FUN_004aa0b0(param_2,param_3,iVar5,param_4,iVar4,iVar3,iVar6,iStack_28);
      if (param_1 == 0) {
        FUN_004b08a0(DAT_006a64bc,param_2);
        return;
      }
      if (param_1 != 1) {
        if (param_1 != 2) {
          FUN_004afee0(s__s__d____unidentified_focus_erro_004ff408,
                       s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x349,param_1);
          return;
        }
        FUN_004b08a0(DAT_006a64a0,param_2);
        return;
      }
      FUN_004b08a0(DAT_006a64c0,param_2);
      return;
    }
    iVar6 = 0;
    if (DAT_006ab848 == 0) {
      FUN_004afee0(s__s__d____no_clipping_limit_set_00500d04,
                   s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x2dd);
    }
    if ((((DAT_006ab83c <= iVar4 + iVar5) && (iVar5 <= DAT_006ab838)) &&
        (DAT_006ab840 <= iVar3 + param_4)) && (param_4 <= DAT_006ab834)) {
      if (param_4 < DAT_006ab840) {
        param_3 = param_3 + (DAT_006ab840 - param_4) * iVar4;
        iVar3 = iVar3 + (param_4 - DAT_006ab840);
        param_4 = DAT_006ab840;
        if (iVar3 < 1) {
          return;
        }
      }
      if ((iVar3 + param_4 <= DAT_006ab834) || (iVar3 = DAT_006ab834 - param_4, 0 < iVar3)) {
        if (iVar5 < DAT_006ab83c) {
          iVar6 = DAT_006ab83c - iVar5;
          param_3 = param_3 + iVar6;
          iVar4 = iVar4 - iVar6;
          iVar5 = DAT_006ab83c;
          if (iVar4 < 1) {
            return;
          }
        }
        if (DAT_006ab838 < iVar4 + iVar5) {
          iVar6 = iVar4 - DAT_006ab838;
          iVar4 = DAT_006ab838 - iVar5;
          iVar6 = iVar6 + iVar5;
          if (iVar4 < 1) {
            return;
          }
        }
        goto LAB_004b6715;
      }
    }
  }
  else {
    iStack_28 = 0;
    iStack_2c = 0;
    if ((param_5 & 4) != 0) {
      local_24 = 0x1000000;
    }
    iVar3 = *(int *)(iVar6 + 0xc + DAT_006ab880);
    iVar4 = *(int *)(iVar6 + 8 + DAT_006ab880);
    if ((param_5 & 2) == 0) {
      param_3 = param_3 - *(int *)(iVar6 + 0x10 + DAT_006ab880);
      param_4 = param_4 - *(int *)(iVar6 + 0x14 + DAT_006ab880);
    }
    if (DAT_006ab848 == 0) {
      FUN_004afee0(s__s__d____no_clipping_limit_set_00500d04,
                   s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x362);
    }
    if (((DAT_006ab83c <= param_3 + iVar4) && (param_3 <= DAT_006ab838)) &&
       ((DAT_006ab840 <= iVar3 + param_4 && (param_4 <= DAT_006ab834)))) {
      if (param_4 < DAT_006ab840) {
        iStack_2c = DAT_006ab840 - param_4;
        iVar3 = iVar3 - iStack_2c;
        param_4 = DAT_006ab840;
        if (iVar3 < 1) {
          return;
        }
      }
      if ((iVar3 + param_4 <= DAT_006ab834) || (iVar3 = DAT_006ab834 - param_4, 0 < iVar3)) {
        if (param_3 < DAT_006ab83c) {
          iStack_28 = DAT_006ab83c - param_3;
          iVar4 = iVar4 - iStack_28;
          param_3 = DAT_006ab83c;
          if (iVar4 < 1) {
            return;
          }
        }
        if ((param_3 + iVar4 <= DAT_006ab838) || (iVar4 = DAT_006ab838 - param_3, 0 < iVar4)) {
          iStack_8 = param_3 + iVar4;
          iStack_4 = iVar3 + param_4;
          iStack_20 = iStack_28;
          iStack_18 = iStack_28 + iVar4;
          iStack_1c = iStack_2c;
          iStack_14 = iStack_2c + iVar3;
          piVar8 = *(int **)(iVar6 + 4 + DAT_006ab880);
          iStack_10 = param_3;
          iStack_c = param_4;
          iVar3 = (**(code **)(*piVar8 + 0x60))(piVar8);
          if (iVar3 != 0) {
            FUN_004afce0(s__s__d____had_to_restore__d_00500e58,
                         s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x39d,param_1);
            piVar1 = *(int **)(iVar6 + 4 + DAT_006ab880);
            (**(code **)(*piVar1 + 0x6c))(piVar1);
          }
          if (unaff_retaddr == 0) {
            FUN_004b08e0(DAT_006a64bc);
            uVar7 = 0;
            iVar3 = (**(code **)(*DAT_006a64bc + 0x14))
                              (DAT_006a64bc,&iStack_14,*(undefined4 *)(iVar6 + 4 + DAT_006ab880),
                               &local_24,iStack_28,0);
            if (iVar3 != 0) {
              iVar6 = iVar6 + DAT_006ab880;
              uVar2 = FUN_004b0190(iVar3);
              FUN_004afee0(s__s__d____set_mem_image___d__to_s_00500d28,
                           s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x3a8,iStack_14,param_3,
                           param_4,iVar4,iStack_28,piVar8,uVar7,*(undefined4 *)(iVar6 + 8),
                           *(undefined4 *)(iVar6 + 0xc),uVar2);
            }
          }
          else if (unaff_retaddr == 1) {
            FUN_004b08e0(DAT_006a64c0);
            uVar7 = 0;
            iVar3 = (**(code **)(*DAT_006a64c0 + 0x14))
                              (DAT_006a64c0,&iStack_14,*(undefined4 *)(iVar6 + 4 + DAT_006ab880),
                               &local_24,iStack_28,0);
            if (iVar3 != 0) {
              iVar6 = iVar6 + DAT_006ab880;
              uVar2 = FUN_004b0190(iVar3);
              FUN_004afee0(s__s__d____set_mem_image___d__to_b_00500d88,
                           s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x3b0,iStack_14,param_3,
                           param_4,iVar4,iStack_28,piVar8,uVar7,*(undefined4 *)(iVar6 + 8),
                           *(undefined4 *)(iVar6 + 0xc),uVar2);
              return;
            }
          }
          else if (unaff_retaddr == 2) {
            FUN_004b08e0(DAT_006a64a0);
            uVar7 = 0;
            iVar3 = (**(code **)(*DAT_006a64a0 + 0x14))
                              (DAT_006a64a0,&iStack_14,*(undefined4 *)(iVar6 + 4 + DAT_006ab880),
                               &local_24,iStack_28,0);
            if (iVar3 != 0) {
              iVar6 = iVar6 + DAT_006ab880;
              uVar2 = FUN_004b0190(iVar3);
              FUN_004afee0(s__s__d____set_mem_image___d__to_b_00500df0,
                           s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x3b8,iStack_14,param_3,
                           param_4,iVar4,iStack_28,piVar8,uVar7,*(undefined4 *)(iVar6 + 8),
                           *(undefined4 *)(iVar6 + 0xc),uVar2);
              return;
            }
          }
        }
      }
    }
  }
  return;
}

