/*
 * FUN_00462320 at 00462320
 * undefined FUN_00462320(void)
 * Address ranges: 00462320-00462602
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00462320(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int **ppiVar4;
  int *apiStack_64 [6];
  undefined4 *puStack_1c;
  undefined4 *puStack_14;
  
  apiStack_64[5] = (int *)param_4;
  apiStack_64[4] = (int *)0x11;
  apiStack_64[3] = DAT_006a621c;
  apiStack_64[2] = (int *)0x46233a;
  (**(code **)(*DAT_006a621c + 0x58))();
  apiStack_64[2] = (int *)param_2;
  apiStack_64[1] = (int *)0x11;
  apiStack_64[0] = DAT_006a621c;
  (**(code **)(*DAT_006a621c + 0x58))();
  if (*(char *)(param_1 + 0x88) == '\0') {
    if (DAT_006a6274 == 1) goto LAB_00462427;
    DAT_006a6274 = 1;
    iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x11,2);
    if (iVar1 != 0) {
      uVar2 = FUN_004aaa00(iVar1);
      FUN_004afee0(s__s__d_____FILTERING__error_setti_004e5f24,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x169,uVar2);
    }
    iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x12,2);
  }
  else {
    if (DAT_006a6274 == 2) goto LAB_00462427;
    DAT_006a6274 = 2;
    iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x11,2);
    if (iVar1 != 0) {
      uVar2 = FUN_004aaa00(iVar1);
      FUN_004afee0(s__s__d_____FILTERING__error_setti_004e5f24,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x169,uVar2);
    }
    iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x12,2);
  }
  if (iVar1 != 0) {
    uVar2 = FUN_004aaa00(iVar1);
    FUN_004afee0(s__s__d_____FILTERING__error_setti_004e5f24,
                 s____Libs_win3dlib_Include_d3dev_i_004e3040,0x16c,uVar2);
  }
LAB_00462427:
  if (DAT_006a625c != 0) {
    DAT_006a625c = 0;
    iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,7,0);
    if (iVar1 != 0) {
      uVar2 = FUN_004aaa00(iVar1);
      FUN_004afee0(s__s__d_____ZBUFFER__error_setting_004e434c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x150,uVar2);
    }
  }
  if (*(char *)(param_1 + 0x89) == '\0') {
    iVar1 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
    *(undefined4 *)(iVar1 + 0x60) = 0;
    uVar2 = *DAT_006a5e80;
    *(undefined4 *)(iVar1 + 0x58) = 1;
    *(undefined4 *)(iVar1 + 0x48) = uVar2;
    if (*(int *)(iVar1 + 0x5c) == 1) {
      FUN_00423930();
    }
    if (DAT_006a6254 != 0) {
      DAT_006a6254 = 0;
      iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,1,*DAT_006a5e80);
      if (iVar1 != 0) {
        uVar2 = FUN_004aaa00(iVar1);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x122,uVar2);
      }
    }
  }
  else {
    (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,1);
    (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x13,5);
    (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x14,6);
  }
  puVar3 = &DAT_006a619c;
  ppiVar4 = apiStack_64 + 3;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar4 = (int *)*puVar3;
    puVar3 = puVar3 + 1;
    ppiVar4 = ppiVar4 + 1;
  }
  ppiVar4 = apiStack_64 + 3;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puStack_14 = *ppiVar4;
    ppiVar4 = ppiVar4 + 1;
    puStack_14 = puStack_14 + 1;
  }
  puVar3 = &DAT_006a5c90;
  ppiVar4 = apiStack_64 + 3;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar4 = (int *)*puVar3;
    puVar3 = puVar3 + 1;
    ppiVar4 = ppiVar4 + 1;
  }
  ppiVar4 = apiStack_64 + 3;
  puVar3 = &DAT_006a619c;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *ppiVar4;
    ppiVar4 = ppiVar4 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,2,&DAT_006a619c);
  if (iVar1 != 0) {
    uVar2 = FUN_004aaa00(iVar1);
    FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                 s____Libs_win3dlib_Include_d3dev_i_004e3040,0x36,uVar2);
  }
  puVar3 = &DAT_006a615c;
  ppiVar4 = apiStack_64;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar4 = (int *)*puVar3;
    puVar3 = puVar3 + 1;
    ppiVar4 = ppiVar4 + 1;
  }
  ppiVar4 = apiStack_64;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puStack_1c = *ppiVar4;
    ppiVar4 = ppiVar4 + 1;
    puStack_1c = puStack_1c + 1;
  }
  puVar3 = (undefined4 *)(param_1 + 0x48);
  ppiVar4 = apiStack_64;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar4 = (int *)*puVar3;
    puVar3 = puVar3 + 1;
    ppiVar4 = ppiVar4 + 1;
  }
  ppiVar4 = apiStack_64;
  puVar3 = &DAT_006a615c;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *ppiVar4;
    ppiVar4 = ppiVar4 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,3,&DAT_006a615c);
  if (iVar1 != 0) {
    uVar2 = FUN_004aaa00(iVar1);
    FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                 s____Libs_win3dlib_Include_d3dev_i_004e3040,0x59,uVar2);
  }
  return;
}

