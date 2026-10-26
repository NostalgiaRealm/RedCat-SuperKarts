/*
 * FUN_00487780 at 00487780
 * undefined FUN_00487780(void)
 * Address ranges: 00487780-0048790c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00487780(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_40 [16];
  
  if (*(char *)(param_1 + 0x724) != '\0') {
    puVar4 = &DAT_006a5c90;
    puVar5 = local_40;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = local_40;
    puVar5 = &DAT_006a61dc;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    iVar3 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,1,&DAT_006a61dc);
    if (iVar3 != 0) {
      uVar2 = FUN_004aaa00(iVar3);
      FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x14,uVar2);
    }
    iVar1 = DAT_005450f4;
    iVar3 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
    *(int *)(iVar3 + 0x60) = DAT_005450f4;
    uVar2 = *(undefined4 *)(DAT_006a5e80 + iVar1 * 0x48);
    *(undefined4 *)(iVar3 + 0x58) = 1;
    *(undefined4 *)(iVar3 + 0x48) = uVar2;
    if (*(int *)(iVar3 + 0x5c) == 1) {
      *(undefined4 *)(iVar3 + 0x58) = 0;
      (**(code **)(**(int **)(iVar3 + 0x54) + 0xc))(*(int **)(iVar3 + 0x54),iVar3);
    }
    if (DAT_006a6254 != DAT_005450f4) {
      DAT_006a6254 = DAT_005450f4;
      iVar3 = (**(code **)(*DAT_006a621c + 0x5c))
                        (DAT_006a621c,1,*(undefined4 *)(DAT_006a5e80 + DAT_005450f4 * 0x48));
      if (iVar3 != 0) {
        uVar2 = FUN_004aaa00(iVar3);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x122,uVar2);
      }
    }
    iVar3 = (**(code **)(*DAT_006a621c + 0x74))
                      (DAT_006a621c,4,2,param_1,*(int *)(param_1 + 0x734) << 3,1);
    if (iVar3 != 0) {
      FUN_004afee0(s__s___d__DrawPrimitive_error_004f9df4,
                   s_D__work_rcsk_Code_game_rse_Homin_004f9dc8,0x1df);
    }
    iVar3 = (**(code **)(*DAT_006a621c + 0x74))
                      (DAT_006a621c,4,2,param_1 + 0x300,*(int *)(param_1 + 0x734) << 3,1);
    if (iVar3 != 0) {
      FUN_004afee0(s__s___d__DrawPrimitive_error_004f9e40,
                   s_D__work_rcsk_Code_game_rse_Homin_004f9e14,0x1e5);
    }
    if (DAT_0053b9b0 == 0) {
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,0);
    }
  }
  return;
}

