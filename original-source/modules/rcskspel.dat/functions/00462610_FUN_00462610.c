/*
 * FUN_00462610 at 00462610
 * undefined FUN_00462610(void)
 * Address ranges: 00462610-00462745
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00462610(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_40 [11];
  undefined4 *puStack_14;
  undefined4 *puStack_c;
  undefined4 *puStack_4;
  
  puVar3 = local_40;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar3 = local_40;
  puVar4 = &DAT_006a619c;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar2 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,2,&DAT_006a619c);
  if (iVar2 != 0) {
    uVar1 = FUN_004aaa00(iVar2);
    FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                 s____Libs_win3dlib_Include_d3dev_i_004e3040,0x36,uVar1);
  }
  puVar3 = puStack_4;
  puVar4 = (undefined4 *)&stack0xffffffb4;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = (undefined4 *)&stack0xffffffb4;
  puVar4 = &DAT_006a615c;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar2 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,3,&DAT_006a615c);
  if (iVar2 != 0) {
    uVar1 = FUN_004aaa00(iVar2);
    FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                 s____Libs_win3dlib_Include_d3dev_i_004e3040,0x59,uVar1);
  }
  if (DAT_006a625c != 1) {
    DAT_006a625c = 1;
    iVar2 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,7,1);
    if (iVar2 != 0) {
      uVar1 = FUN_004aaa00(iVar2);
      FUN_004afee0(s__s__d_____ZBUFFER__error_setting_004e434c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x150,uVar1);
    }
  }
  if (*(char *)(param_1 + 0x89) != '\0') {
    (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,0);
  }
  (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x11,*puStack_c);
  (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x12,*puStack_14);
  return;
}

