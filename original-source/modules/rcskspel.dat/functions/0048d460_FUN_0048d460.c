/*
 * FUN_0048d460 at 0048d460
 * undefined FUN_0048d460(void)
 * Address ranges: 0048d460-0048d606
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048d460(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int **ppiVar5;
  int iVar6;
  int *apiStack_64 [4];
  undefined4 uStack_54;
  undefined4 uStack_50;
  
  if (((DAT_0053ba78 != 0) && (DAT_0053ba60 != 0)) && (DAT_0053b9b0 == 0)) {
    uStack_50 = 1;
    uStack_54 = 0x1b;
    apiStack_64[3] = DAT_006a621c;
    apiStack_64[2] = (int *)0x48d49e;
    (**(code **)(*DAT_006a621c + 0x5c))();
    apiStack_64[2] = (int *)0x2;
    apiStack_64[1] = (int *)0x13;
    apiStack_64[0] = DAT_006a621c;
    (**(code **)(*DAT_006a621c + 0x5c))();
    (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x14,2);
    puVar4 = &DAT_006a5c90;
    ppiVar5 = apiStack_64;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppiVar5 = (int *)*puVar4;
      puVar4 = puVar4 + 1;
      ppiVar5 = ppiVar5 + 1;
    }
    ppiVar5 = apiStack_64;
    puVar4 = &DAT_006a61dc;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *ppiVar5;
      ppiVar5 = ppiVar5 + 1;
      puVar4 = puVar4 + 1;
    }
    iVar3 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,1,&DAT_006a61dc);
    if (iVar3 != 0) {
      uVar1 = FUN_004aaa00(iVar3);
      FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x14,uVar1);
    }
    iVar6 = DAT_0067e470;
    iVar3 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
    *(int *)(iVar3 + 0x60) = DAT_0067e470;
    uVar1 = *(undefined4 *)(DAT_006a5e80 + iVar6 * 0x48);
    *(undefined4 *)(iVar3 + 0x58) = 1;
    *(undefined4 *)(iVar3 + 0x48) = uVar1;
    if (*(int *)(iVar3 + 0x5c) == 1) {
      *(undefined4 *)(iVar3 + 0x58) = 0;
      (**(code **)(**(int **)(iVar3 + 0x54) + 0xc))(*(int **)(iVar3 + 0x54),iVar3);
    }
    if (DAT_006a6254 != DAT_0067e470) {
      DAT_006a6254 = DAT_0067e470;
      iVar3 = (**(code **)(*DAT_006a621c + 0x5c))
                        (DAT_006a621c,1,*(undefined4 *)(DAT_006a5e80 + DAT_0067e470 * 0x48));
      if (iVar3 != 0) {
        uVar1 = FUN_004aaa00(iVar3);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x122,uVar1);
      }
    }
    iVar6 = 0x14;
    iVar3 = param_1;
    do {
      iVar2 = (**(code **)(*DAT_006a621c + 0x74))
                        (DAT_006a621c,5,2,iVar3,*(undefined4 *)(param_1 + 0x11a4),1);
      if (iVar2 != 0) {
        FUN_004afee0(s__s___d__DrawPrimitive_error_004fa194,
                     s_D__work_rcsk_Code_game_rse_Spawn_004fa168,0x231);
      }
      iVar3 = iVar3 + 0xe0;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (DAT_0053b9b0 == 0) {
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,0);
    }
  }
  return;
}

