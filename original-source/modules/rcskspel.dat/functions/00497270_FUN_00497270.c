/*
 * FUN_00497270 at 00497270
 * undefined FUN_00497270(void)
 * Address ranges: 00497270-004977cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00497270(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 local_40 [16];
  
  iVar6 = param_2 * 0x984;
  iVar8 = param_3 * 0x984;
  iVar5 = *(int *)(iVar8 + 4 + DAT_00680b28) - *(int *)(iVar6 + DAT_00680b28);
  *(int *)(param_1 + 0xa2) = *(int *)(param_1 + 0xa2) + iVar5;
  *(int *)(param_1 + 0x9e) = *(int *)(param_1 + 0x9e) + iVar5 / 3;
  if (0 < iVar5) {
    puVar7 = &DAT_006a5c90;
    puVar9 = local_40;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar7 = local_40;
    puVar9 = &DAT_006a61dc;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    iVar4 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,1,&DAT_006a61dc);
    if (iVar4 != 0) {
      uVar2 = FUN_004aaa00(iVar4);
      FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                   s_______Libs_Win3DLib_Include_d3de_004fb2c0,0x14,uVar2);
    }
    if (*(int *)(param_1 + 0x9a) != 0) {
      iVar4 = *(int *)(param_1 + 0x4a);
      iVar3 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
      *(int *)(iVar3 + 0x60) = iVar4;
      *(undefined4 *)(iVar3 + 0x48) = *(undefined4 *)(DAT_006a5e80 + iVar4 * 0x48);
      *(undefined4 *)(iVar3 + 0x58) = 1;
      if (*(int *)(iVar3 + 0x5c) == 1) {
        FUN_00423930();
      }
      iVar4 = *(int *)(param_1 + 0x4a);
      if ((DAT_006a6254 != iVar4) &&
         (DAT_006a6254 = iVar4,
         iVar4 = (**(code **)(*DAT_006a621c + 0x5c))
                           (DAT_006a621c,1,*(undefined4 *)(DAT_006a5e80 + iVar4 * 0x48)), iVar4 != 0
         )) {
        uVar2 = FUN_004aaa00(iVar4);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,
                     s_______Libs_Win3DLib_Include_d3de_004fb2c0,0x122,uVar2);
      }
    }
    iVar5 = (**(code **)(*DAT_006a621c + 0x78))
                      (DAT_006a621c,4,2,*(undefined4 *)(param_1 + 0x6a),
                       *(undefined4 *)(param_1 + 0x72),*(int *)(param_1 + 0x6e) + unaff_ESI * 2,
                       iVar5,8);
    if (iVar5 != 0) {
      uVar2 = FUN_004aaa00(iVar5);
      FUN_004afee0(s__s__d____D3DError_DrawPrimitive___004fb298,
                   s_D__work_rcsk_Code_Engine_Prog_Rd_004fb234,0x21c,uVar2);
    }
  }
  iVar5 = *(int *)(iVar6 + 8 + DAT_00680b28);
  iVar4 = *(int *)(iVar8 + 0xc + DAT_00680b28) - iVar5;
  *(int *)(param_1 + 0x9e) = *(int *)(param_1 + 0x9e) + iVar4 / 3;
  *(int *)(param_1 + 0xa2) = *(int *)(param_1 + 0xa2) + iVar4;
  if (0 < iVar4) {
    if (*(int *)(param_1 + 0x9a) != 0) {
      iVar3 = *(int *)(param_1 + 0x4e);
      iVar1 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
      *(int *)(iVar1 + 0x60) = iVar3;
      *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(DAT_006a5e80 + iVar3 * 0x48);
      *(undefined4 *)(iVar1 + 0x58) = 1;
      if (*(int *)(iVar1 + 0x5c) == 1) {
        FUN_00423930();
      }
      iVar3 = *(int *)(param_1 + 0x4e);
      if ((DAT_006a6254 != iVar3) &&
         (DAT_006a6254 = iVar3,
         iVar3 = (**(code **)(*DAT_006a621c + 0x5c))
                           (DAT_006a621c,1,*(undefined4 *)(DAT_006a5e80 + iVar3 * 0x48)), iVar3 != 0
         )) {
        uVar2 = FUN_004aaa00(iVar3);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,
                     s_______Libs_Win3DLib_Include_d3de_004fb2c0,0x122,uVar2);
      }
    }
    iVar5 = (**(code **)(*DAT_006a621c + 0x78))
                      (DAT_006a621c,4,2,*(undefined4 *)(param_1 + 0x7a),
                       *(undefined4 *)(param_1 + 0x82),*(int *)(param_1 + 0x7e) + iVar5 * 2,iVar4,8)
    ;
    if (iVar5 != 0) {
      FUN_004afcc0(0,1);
      FUN_004afce0(s_start__d__end__d_004fb284,param_2,param_3);
      FUN_004afcc0(0,0);
      uVar2 = FUN_004aaa00(iVar5);
      FUN_004afee0(s__s__d____D3DError_DrawPrimitive___004fb298,
                   s_D__work_rcsk_Code_Engine_Prog_Rd_004fb234,0x23c,uVar2);
    }
  }
  iVar5 = *(int *)(iVar6 + 0x10 + DAT_00680b28);
  iVar4 = *(int *)(iVar8 + 0x14 + DAT_00680b28) - iVar5;
  *(int *)(param_1 + 0x9e) = *(int *)(param_1 + 0x9e) + iVar4 / 3;
  *(int *)(param_1 + 0xa2) = *(int *)(param_1 + 0xa2) + iVar4;
  if (0 < iVar4) {
    if (*(int *)(param_1 + 0x9a) != 0) {
      iVar3 = *(int *)(param_1 + 0x52);
      iVar1 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
      *(int *)(iVar1 + 0x60) = iVar3;
      *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(DAT_006a5e80 + iVar3 * 0x48);
      *(undefined4 *)(iVar1 + 0x58) = 1;
      if (*(int *)(iVar1 + 0x5c) == 1) {
        FUN_00423930();
      }
      iVar3 = *(int *)(param_1 + 0x52);
      if ((DAT_006a6254 != iVar3) &&
         (DAT_006a6254 = iVar3,
         iVar3 = (**(code **)(*DAT_006a621c + 0x5c))
                           (DAT_006a621c,1,*(undefined4 *)(DAT_006a5e80 + iVar3 * 0x48)), iVar3 != 0
         )) {
        uVar2 = FUN_004aaa00(iVar3);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,
                     s_______Libs_Win3DLib_Include_d3de_004fb2c0,0x122,uVar2);
      }
    }
    iVar5 = (**(code **)(*DAT_006a621c + 0x78))
                      (DAT_006a621c,4,2,*(undefined4 *)(param_1 + 0x5a),
                       *(undefined4 *)(param_1 + 0x62),*(int *)(param_1 + 0x5e) + iVar5 * 2,iVar4,8)
    ;
    if (iVar5 != 0) {
      uVar2 = FUN_004aaa00(iVar5);
      FUN_004afee0(s__s__d____D3DError_DrawPrimitive___004fb298,
                   s_D__work_rcsk_Code_Engine_Prog_Rd_004fb234,0x25b,uVar2);
    }
  }
  iVar5 = *(int *)(iVar6 + 0x18 + DAT_00680b28);
  iVar6 = *(int *)(iVar8 + 0x1c + DAT_00680b28) - iVar5;
  *(int *)(param_1 + 0xa2) = *(int *)(param_1 + 0xa2) + iVar6;
  *(int *)(param_1 + 0x9e) = *(int *)(param_1 + 0x9e) + iVar6 / 3;
  if (0 < iVar6) {
    if (*(int *)(param_1 + 0x9a) != 0) {
      iVar8 = *(int *)(param_1 + 0x56);
      iVar4 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
      *(int *)(iVar4 + 0x60) = iVar8;
      *(undefined4 *)(iVar4 + 0x48) = *(undefined4 *)(DAT_006a5e80 + iVar8 * 0x48);
      *(undefined4 *)(iVar4 + 0x58) = 1;
      if (*(int *)(iVar4 + 0x5c) == 1) {
        *(undefined4 *)(iVar4 + 0x58) = 0;
        (**(code **)(**(int **)(iVar4 + 0x54) + 0xc))(*(int **)(iVar4 + 0x54),iVar4);
      }
      iVar8 = *(int *)(param_1 + 0x56);
      if ((DAT_006a6254 != iVar8) &&
         (DAT_006a6254 = iVar8,
         iVar8 = (**(code **)(*DAT_006a621c + 0x5c))
                           (DAT_006a621c,1,*(undefined4 *)(DAT_006a5e80 + iVar8 * 0x48)), iVar8 != 0
         )) {
        uVar2 = FUN_004aaa00(iVar8);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,
                     s_______Libs_Win3DLib_Include_d3de_004fb2c0,0x122,uVar2);
      }
    }
    iVar5 = (**(code **)(*DAT_006a621c + 0x78))
                      (DAT_006a621c,4,2,*(undefined4 *)(param_1 + 0x8a),
                       *(undefined4 *)(param_1 + 0x92),*(int *)(param_1 + 0x8e) + iVar5 * 2,iVar6,1)
    ;
    if (iVar5 != 0) {
      uVar2 = FUN_004aaa00(iVar5);
      FUN_004afee0(s__s__d____D3DError_DrawPrimitive___004fb298,
                   s_D__work_rcsk_Code_Engine_Prog_Rd_004fb234,0x27a,uVar2);
    }
  }
  return;
}

