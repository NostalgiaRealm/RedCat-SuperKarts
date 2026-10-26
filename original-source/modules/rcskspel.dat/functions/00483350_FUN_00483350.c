/*
 * FUN_00483350 at 00483350
 * undefined FUN_00483350(void)
 * Address ranges: 00483350-00483644
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00483350(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 **ppuVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  char *pcStack_130;
  int *piStack_12c;
  undefined4 uStack_128;
  undefined4 *puStack_124;
  int *piStack_120;
  undefined4 uStack_11c;
  undefined4 *puStack_118;
  undefined4 auStack_100 [10];
  undefined4 auStack_d8 [6];
  undefined4 auStack_c0 [13];
  undefined4 auStack_8c [19];
  undefined4 auStack_40 [16];
  
  if (*(char *)(param_1 + 0xa8) == '\0') {
    puVar6 = &DAT_006a61dc;
    puVar9 = auStack_40;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
    puStack_118 = &DAT_006a61dc;
    puVar6 = &DAT_006a619c;
    puVar9 = auStack_c0;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
    uStack_11c = 1;
    puVar6 = &DAT_006a5c90;
    puVar9 = auStack_100;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar6 = auStack_100;
    puVar9 = &DAT_006a61dc;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
    piStack_120 = DAT_006a621c;
    puStack_124 = (undefined4 *)0x4833bf;
    puStack_124 = (undefined4 *)(**(code **)(*DAT_006a621c + 0x68))();
    iVar4 = 0;
    if (puStack_124 != (undefined4 *)0x0) {
      uStack_128 = 0x4833cb;
      uStack_128 = FUN_004aaa00();
      piStack_12c = (int *)0x14;
      pcStack_130 = s____Libs_win3dlib_Include_d3dev_i_004e3040;
      FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c);
    }
    puStack_124 = &DAT_006a619c;
    puVar6 = &DAT_006a5c90;
    puVar9 = auStack_8c;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
    uStack_128 = 2;
    puVar6 = auStack_8c;
    puVar9 = &DAT_006a619c;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
    piStack_12c = DAT_006a621c;
    pcStack_130 = (char *)0x483418;
    pcStack_130 = (char *)(**(code **)(*DAT_006a621c + 0x68))();
    if (pcStack_130 != (char *)0x0) {
      uVar3 = FUN_004aaa00();
      FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x36,uVar3);
    }
    cVar1 = *(char *)(param_1 + 0x90);
    puVar6 = auStack_d8;
    ppuVar7 = &puStack_118;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *ppuVar7 = (undefined4 *)*puVar6;
      puVar6 = puVar6 + 1;
      ppuVar7 = ppuVar7 + 1;
    }
    if (cVar1 != '\0') {
      puVar6 = &DAT_006a5c90;
      ppuVar7 = &puStack_118;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *ppuVar7 = (undefined4 *)*puVar6;
        puVar6 = puVar6 + 1;
        ppuVar7 = ppuVar7 + 1;
      }
    }
    pcStack_130 = *(char **)(param_1 + 0xe0);
    (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x13);
    (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x14,*(undefined4 *)(param_1 + 0xe4));
    iVar5 = *(int *)(param_1 + 0xdc);
    iVar8 = 0;
    iVar10 = 0;
    if (0 < *(int *)(param_1 + 0xa0)) {
      do {
        iVar2 = *(int *)(param_1 + 0x9c);
        if (*(char *)(iVar2 + 8 + iVar4) != '\0') {
          (**(code **)(*(int *)(iVar2 + iVar4) + 4))
                    (iVar5,&pcStack_130,
                     CONCAT31((int3)((uint)iVar2 >> 8),*(char *)(param_1 + 0x90) == '\0'));
          iVar5 = iVar5 + 0xc0;
          iVar10 = iVar10 + 6;
        }
        iVar8 = iVar8 + 1;
        iVar4 = iVar4 + 0x5c;
      } while (iVar8 < *(int *)(param_1 + 0xa0));
    }
    iVar4 = *(int *)(param_1 + 0x94);
    iVar5 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
    *(int *)(iVar5 + 0x60) = iVar4;
    uVar3 = *(undefined4 *)(DAT_006a5e80 + iVar4 * 0x48);
    *(undefined4 *)(iVar5 + 0x58) = 1;
    *(undefined4 *)(iVar5 + 0x48) = uVar3;
    if (*(int *)(iVar5 + 0x5c) == 1) {
      *(undefined4 *)(iVar5 + 0x58) = 0;
      (**(code **)(**(int **)(iVar5 + 0x54) + 0xc))(*(int **)(iVar5 + 0x54),iVar5);
    }
    iVar4 = *(int *)(param_1 + 0x94);
    if (DAT_006a6254 != iVar4) {
      DAT_006a6254 = iVar4;
      iVar4 = (**(code **)(*DAT_006a621c + 0x5c))
                        (DAT_006a621c,1,*(undefined4 *)(DAT_006a5e80 + iVar4 * 0x48));
      if (iVar4 != 0) {
        uVar3 = FUN_004aaa00(iVar4);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x122,uVar3);
      }
    }
    iVar4 = (**(code **)(*DAT_006a621c + 0x74))
                      (DAT_006a621c,4,2,*(undefined4 *)(param_1 + 0xdc),iVar10,8);
    if (iVar4 != 0) {
      FUN_004afee0(s__s___d___>_DrawPrimitive_error____004f9a84,
                   s_D__work_rcsk_Code_game_Par_Main__004f9a60,0x2a0);
    }
    puVar6 = auStack_8c;
    puVar9 = &DAT_006a61dc;
    for (iVar4 = 0x10; puVar6 = puVar6 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar6;
      puVar9 = puVar9 + 1;
    }
    iVar4 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,1,&DAT_006a61dc);
    if (iVar4 != 0) {
      uVar3 = FUN_004aaa00(iVar4);
      FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x14,uVar3);
    }
    puVar6 = (undefined4 *)&stack0xfffffeec;
    puVar9 = &DAT_006a619c;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
    iVar4 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,2,&DAT_006a619c);
    if (iVar4 != 0) {
      uVar3 = FUN_004aaa00(iVar4);
      FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x36,uVar3);
    }
  }
  return;
}

