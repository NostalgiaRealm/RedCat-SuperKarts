/*
 * FUN_00426e50 at 00426e50
 * undefined FUN_00426e50(void)
 * Address ranges: 00426e50-004270bf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426e50(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 auStack_40 [16];
  
  iVar2 = DAT_0050dfa8;
  if (DAT_0053ba2c != 0) {
    iVar4 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
    *(int *)(iVar4 + 0x60) = DAT_0050dfa8;
    uVar3 = *(undefined4 *)(DAT_006a5e80 + iVar2 * 0x48);
    *(undefined4 *)(iVar4 + 0x58) = 1;
    *(undefined4 *)(iVar4 + 0x48) = uVar3;
    if (*(int *)(iVar4 + 0x5c) == 1) {
      FUN_00423930();
    }
    if (DAT_006a6254 != DAT_0050dfa8) {
      DAT_006a6254 = DAT_0050dfa8;
      iVar2 = (**(code **)(*DAT_006a621c + 0x5c))
                        (DAT_006a621c,1,*(undefined4 *)(DAT_006a5e80 + DAT_0050dfa8 * 0x48));
      if (iVar2 != 0) {
        uVar3 = FUN_004aaa00(iVar2);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x122,uVar3);
      }
    }
    if (DAT_0053b9b0 == 0) {
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,1);
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x13,6);
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x14,5);
    }
    FUN_00426db0();
    puVar6 = &DAT_006a5c90;
    puVar7 = auStack_40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    puVar6 = auStack_40;
    puVar7 = &DAT_006a61dc;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    iVar2 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,1,&DAT_006a61dc);
    if (iVar2 != 0) {
      uVar3 = FUN_004aaa00(iVar2);
      FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x14,uVar3);
    }
    iVar2 = 0;
    do {
      iVar4 = FUN_00426540(iVar2);
      if (*(int *)(&DAT_0050f8b4 + iVar4 * 0x1910) != 0) {
        iVar4 = FUN_00426540(iVar2);
        piVar1 = DAT_006a621c;
        if (2 < *(int *)(&DAT_0050dfb0 + iVar4 * 0x1910)) {
          iVar4 = *DAT_006a621c;
          iVar5 = FUN_00426540(iVar2,1);
          iVar5 = FUN_00426540(iVar2,*(undefined4 *)(&DAT_0050dfb0 + iVar5 * 0x1910));
          iVar4 = (**(code **)(iVar4 + 0x74))(piVar1,5,2,&DAT_0050dfb4 + iVar5 * 0x1910);
          if (iVar4 != 0) {
            FUN_004afee0(s__s___d__DramPrimitive_error_004e7764,
                         s_D__work_rcsk_Code_game_gfx_skid__004e7740,0x2aa);
          }
          piVar1 = DAT_006a621c;
          iVar4 = *DAT_006a621c;
          iVar5 = FUN_00426540(iVar2,1);
          iVar5 = FUN_00426540(iVar2,*(undefined4 *)(&DAT_0050dfb0 + iVar5 * 0x1910));
          iVar4 = (**(code **)(iVar4 + 0x74))(piVar1,5,2,&DAT_0050ec34 + iVar5 * 0x1910);
          if (iVar4 != 0) {
            FUN_004afee0(s__s___d__DramPrimitive_error_004e77a8,
                         s_D__work_rcsk_Code_game_gfx_skid__004e7784,0x2b0);
          }
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x14);
    if (DAT_0053b9b0 == 0) {
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,0);
    }
  }
  return;
}

