/*
 * FUN_004888b0 at 004888b0
 * undefined FUN_004888b0(void)
 * Address ranges: 004888b0-00488a36
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004888b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_40 [16];
  
  if (*(char *)(param_1 + 0x13c) != '\0') {
    if (DAT_0053b9b0 == 0) {
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,1);
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x13,2);
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x14,2);
    }
    puVar6 = (undefined4 *)&stack0xffffffbc;
    puVar4 = (undefined4 *)&stack0xffffffbc;
    puVar5 = &DAT_006a5c90;
    for (iVar3 = 0x10; puVar6 = puVar6 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
    }
    puVar6 = &DAT_006a61dc;
    for (iVar3 = 0x10; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar4;
      puVar6 = puVar6 + 1;
    }
    iVar3 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,1,&DAT_006a61dc);
    if (iVar3 != 0) {
      uVar2 = FUN_004aaa00(iVar3);
      FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x14,uVar2);
    }
    iVar1 = DAT_005450fc;
    iVar3 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
    *(int *)(iVar3 + 0x60) = DAT_005450fc;
    uVar2 = *(undefined4 *)(DAT_006a5e80 + iVar1 * 0x48);
    *(undefined4 *)(iVar3 + 0x58) = 1;
    *(undefined4 *)(iVar3 + 0x48) = uVar2;
    if (*(int *)(iVar3 + 0x5c) == 1) {
      *(undefined4 *)(iVar3 + 0x58) = 0;
      (**(code **)(**(int **)(iVar3 + 0x54) + 0xc))(*(int **)(iVar3 + 0x54),iVar3);
    }
    if (DAT_006a6254 != DAT_005450fc) {
      DAT_006a6254 = DAT_005450fc;
      iVar3 = (**(code **)(*DAT_006a621c + 0x5c))
                        (DAT_006a621c,1,*(undefined4 *)(DAT_006a5e80 + DAT_005450fc * 0x48));
      if (iVar3 != 0) {
        uVar2 = FUN_004aaa00(iVar3);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x122,uVar2);
      }
    }
    iVar3 = (**(code **)(*DAT_006a621c + 0x74))
                      (DAT_006a621c,5,2,param_1,*(undefined4 *)(param_1 + 0x154),1);
    if (iVar3 != 0) {
      FUN_004afee0(s__s___d__DrawPrimitive_error_004f9ee8,
                   s_D__work_rcsk_Code_game_rse_JetFl_004f9ec0,0x191);
    }
    if (DAT_0053b9b0 == 0) {
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,0);
    }
  }
  return;
}

