/*
 * FUN_004235c0 at 004235c0
 * undefined FUN_004235c0(void)
 * Address ranges: 004235c0-004238e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004235c0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_40 [16];
  
  iVar2 = DAT_00509158;
  if ((DAT_0053ba28 != 0) && (DAT_0050bc28 != 0)) {
    iVar1 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
    *(int *)(iVar1 + 0x60) = DAT_00509158;
    uVar3 = *(undefined4 *)(DAT_006a5e80 + iVar2 * 0x48);
    *(undefined4 *)(iVar1 + 0x58) = 1;
    *(undefined4 *)(iVar1 + 0x48) = uVar3;
    if (*(int *)(iVar1 + 0x5c) == 1) {
      FUN_00423930();
    }
    if (DAT_006a6254 != DAT_00509158) {
      DAT_006a6254 = DAT_00509158;
      iVar2 = (**(code **)(*DAT_006a621c + 0x5c))
                        (DAT_006a621c,1,*(undefined4 *)(DAT_006a5e80 + DAT_00509158 * 0x48));
      if (iVar2 != 0) {
        uVar3 = FUN_004aaa00(iVar2);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x122,uVar3);
      }
    }
    if (DAT_0053b9b0 == 0) {
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,1);
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x13,5);
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x14,6);
    }
    if (((DAT_0053ba20 == 2) && (DAT_0053b9f0 != 0)) && (DAT_006a6274 != 0)) {
      DAT_006a6274 = 0;
      iVar2 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x11,1);
      if (iVar2 != 0) {
        uVar3 = FUN_004aaa00(iVar2);
        FUN_004afee0(s__s__d_____FILTERING__error_setti_004e5f24,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x162,uVar3);
      }
      iVar2 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x12,1);
      if (iVar2 != 0) {
        uVar3 = FUN_004aaa00(iVar2);
        FUN_004afee0(s__s__d_____FILTERING__error_setti_004e5f24,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x165,uVar3);
      }
    }
    if (DAT_006a625c != 0) {
      DAT_006a625c = 0;
      iVar2 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,7,0);
      if (iVar2 != 0) {
        uVar3 = FUN_004aaa00(iVar2);
        FUN_004afee0(s__s__d_____ZBUFFER__error_setting_004e434c,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x150,uVar3);
      }
    }
    FUN_004233c0();
    puVar4 = &DAT_00509160;
    puVar5 = auStack_40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = auStack_40;
    puVar5 = &DAT_006a61dc;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    iVar2 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,1,&DAT_006a61dc);
    if (iVar2 != 0) {
      uVar3 = FUN_004aaa00(iVar2);
      FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x14,uVar3);
    }
    puVar4 = &DAT_005091a0;
    do {
      iVar2 = (**(code **)(*DAT_006a621c + 0x74))(DAT_006a621c,5,2,puVar4,0x22,1);
      if (iVar2 != 0) {
        FUN_004afee0(s__s___d__DramPrimitive_error_004e5fc4,
                     s_D__work_rcsk_Code_game_gfx_flag__004e5fa0,0x168);
      }
      puVar4 = puVar4 + 0x110;
    } while ((int)puVar4 < 0x50bc20);
    if (DAT_0053b9b0 == 0) {
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,0);
    }
    if (((DAT_0053ba20 == 2) && (DAT_0053b9f0 != 0)) && (DAT_006a6274 != 2)) {
      DAT_006a6274 = 2;
      iVar2 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x11,2);
      if (iVar2 != 0) {
        uVar3 = FUN_004aaa00(iVar2);
        FUN_004afee0(s__s__d_____FILTERING__error_setti_004e5f24,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x169,uVar3);
      }
      iVar2 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x12,2);
      if (iVar2 != 0) {
        uVar3 = FUN_004aaa00(iVar2);
        FUN_004afee0(s__s__d_____FILTERING__error_setti_004e5f24,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x16c,uVar3);
      }
    }
    if (DAT_006a625c != 1) {
      DAT_006a625c = 1;
      iVar2 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,7,1);
      if (iVar2 != 0) {
        uVar3 = FUN_004aaa00(iVar2);
        FUN_004afee0(s__s__d_____ZBUFFER__error_setting_004e434c,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x150,uVar3);
      }
    }
  }
  return;
}

