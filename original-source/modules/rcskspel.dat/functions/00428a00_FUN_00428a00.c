/*
 * FUN_00428a00 at 00428a00
 * undefined FUN_00428a00(void)
 * Address ranges: 00428a00-00428c80
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00428a00(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float10 fVar8;
  
  if (DAT_0053ba24 != 0) {
    fVar8 = (float10)FUN_0048f4e0();
    iVar2 = DAT_0053a228;
    if ((float10)1.0 / fVar8 < (float10)10.0) {
      FUN_004289d0();
      return;
    }
    iVar4 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
    *(int *)(iVar4 + 0x60) = DAT_0053a228;
    uVar3 = *(undefined4 *)(DAT_006a5e80 + iVar2 * 0x48);
    *(undefined4 *)(iVar4 + 0x58) = 1;
    *(undefined4 *)(iVar4 + 0x48) = uVar3;
    if (*(int *)(iVar4 + 0x5c) == 1) {
      *(undefined4 *)(iVar4 + 0x58) = 0;
      (**(code **)(**(int **)(iVar4 + 0x54) + 0xc))(*(int **)(iVar4 + 0x54),iVar4);
    }
    if (DAT_006a6254 != DAT_0053a228) {
      DAT_006a6254 = DAT_0053a228;
      iVar2 = (**(code **)(*DAT_006a621c + 0x5c))
                        (DAT_006a621c,1,*(undefined4 *)(DAT_006a5e80 + DAT_0053a228 * 0x48));
      if (iVar2 != 0) {
        uVar3 = FUN_004aaa00(iVar2);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x122,uVar3);
      }
    }
    if (DAT_0053b9f0 != 0) {
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,1);
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x13,5);
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x14,2);
    }
    iVar2 = 0;
    do {
      iVar4 = FUN_00427ed0(iVar2);
      if (*(int *)(&DAT_00535148 + iVar4 * 300) != 0) {
        FUN_004282e0(iVar2);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x46);
    FUN_004bf5b9(&DAT_00535020,0x46,300,&LAB_00428920);
    iVar2 = 0;
    do {
      iVar4 = FUN_00427ed0(iVar2);
      if (*(int *)(&DAT_00535148 + iVar4 * 300) != 0) {
        iVar4 = FUN_00427ed0(iVar2);
        puVar6 = (undefined4 *)(&DAT_00535020 + iVar4 * 300);
        puVar7 = &DAT_006a61dc;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        iVar4 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,1,&DAT_006a61dc);
        if (iVar4 != 0) {
          uVar3 = FUN_004aaa00(iVar4);
          FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                       s____Libs_win3dlib_Include_d3dev_i_004e3040,0x14,uVar3);
        }
        piVar1 = DAT_006a621c;
        iVar4 = *DAT_006a621c;
        iVar5 = FUN_00427ed0(iVar2,6,1);
        iVar4 = (**(code **)(iVar4 + 0x74))(piVar1,6,2,&DAT_00535060 + iVar5 * 300);
        if (iVar4 != 0) {
          FUN_004afee0(s__s___d__DramPrimitive_error_004e7b4c,
                       s_D__work_rcsk_Code_game_gfx_wolk__004e7b28,0x2a2);
        }
        iVar4 = FUN_00427ed0(iVar2);
        *(int *)(&DAT_0053513c + iVar4 * 300) = *(int *)(&DAT_0053513c + iVar4 * 300) + 1;
        iVar5 = FUN_00427ed0(iVar2);
        if (*(int *)(&DAT_00535138 + iVar5 * 300) <= *(int *)(&DAT_0053513c + iVar4 * 300)) {
          iVar4 = FUN_00427ed0(iVar2);
          *(undefined4 *)(&DAT_00535148 + iVar4 * 300) = 0;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x46);
    if (DAT_0053b9f0 != 0) {
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,0);
    }
  }
  return;
}

