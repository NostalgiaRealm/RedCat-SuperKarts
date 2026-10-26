/*
 * FUN_0048a170 at 0048a170
 * undefined FUN_0048a170(void)
 * Address ranges: 0048a170-0048a419
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048a170(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined1 uStack_55;
  undefined4 auStack_4c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d14f8;
  local_c = ExceptionList;
  if (*(char *)(param_1 + 0x3b) != '\0') {
    ExceptionList = &local_c;
    if (DAT_0053b9b0 == 0) {
      ExceptionList = &local_c;
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,1);
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x13,2);
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x14,2);
    }
    thunk_FUN_00489f50();
    puVar7 = &DAT_006a5c90;
    puVar8 = auStack_4c;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    puVar7 = auStack_4c;
    puVar8 = &DAT_006a61dc;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    iVar5 = (**(code **)(*DAT_006a621c + 0x68))(DAT_006a621c,1,&DAT_006a61dc);
    if (iVar5 != 0) {
      uVar2 = FUN_004aaa00(iVar5);
      FUN_004afee0(s__s__d_____FOG__error_setting_tra_004e300c,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0x14,uVar2);
    }
    iVar6 = DAT_00545108;
    iVar5 = *(int *)(DAT_006a6290 + DAT_004fd9fc * 4);
    *(int *)(iVar5 + 0x60) = DAT_00545108;
    uVar2 = *(undefined4 *)(DAT_006a5e80 + iVar6 * 0x48);
    *(undefined4 *)(iVar5 + 0x58) = 1;
    *(undefined4 *)(iVar5 + 0x48) = uVar2;
    if (*(int *)(iVar5 + 0x5c) == 1) {
      FUN_00423930();
    }
    if (DAT_006a6254 != DAT_00545108) {
      DAT_006a6254 = DAT_00545108;
      iVar5 = (**(code **)(*DAT_006a621c + 0x5c))
                        (DAT_006a621c,1,*(undefined4 *)(DAT_006a5e80 + DAT_00545108 * 0x48));
      if (iVar5 != 0) {
        uVar2 = FUN_004aaa00(iVar5);
        FUN_004afee0(s__s__d_____TEXTURE__error_setting_004e5fe4,
                     s____Libs_win3dlib_Include_d3dev_i_004e3040,0x122,uVar2);
      }
    }
    iVar5 = (**(code **)*param_1)();
    piVar1 = DAT_006a621c;
    if (3 < iVar5) {
      uVar2 = *(undefined4 *)(param_1[1] + 4);
      iVar5 = *DAT_006a621c;
      uVar3 = (**(code **)*param_1)(1);
      iVar5 = (**(code **)(iVar5 + 0x74))(piVar1,5,2,uVar2,uVar3);
      if (iVar5 != 0) {
        FUN_004afee0(s__s___d__DrawPrimitive_error_004f9f68,
                     s_D__work_rcsk_Code_game_rse_jetst_004f9f3c,0x275);
      }
    }
    if (*(char *)((int)param_1 + 0x102) != '\0') {
      iVar5 = (**(code **)*param_1)();
      puVar4 = operator_new(0x10);
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = (undefined1 *)0x0;
      }
      else {
        *(undefined4 *)(puVar4 + 4) = 0;
        *puVar4 = uStack_55;
        *(undefined4 *)(puVar4 + 8) = 0;
        *(undefined4 *)(puVar4 + 0xc) = 0;
      }
      uStack_4 = 0;
      if (-1 < iVar5 + -2) {
        iVar6 = iVar5 + -1;
        iVar5 = (iVar5 + -2) * 0x20;
        do {
          FUN_0048b000(*(undefined4 *)(puVar4 + 8),*(int *)(param_1[1] + 4) + iVar5);
          iVar5 = iVar5 + -0x20;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      iVar5 = *(int *)(puVar4 + 4);
      if (((iVar5 != 0) && (iVar6 = *(int *)(puVar4 + 8) - iVar5 >> 5, 3 < iVar6)) &&
         (iVar5 = (**(code **)(*DAT_006a621c + 0x74))(DAT_006a621c,5,2,iVar5,iVar6,1), iVar5 != 0))
      {
        FUN_004afee0(s__s___d__DrawPrimitive_error_004f9fb4,
                     s_D__work_rcsk_Code_game_rse_jetst_004f9f88,0x28a);
      }
      uStack_4 = 0xffffffff;
      if (puVar4 != (undefined1 *)0x0) {
        FUN_0048b600(*(undefined4 *)(puVar4 + 4),*(undefined4 *)(puVar4 + 8));
        FUN_004bc150(*(undefined4 *)(puVar4 + 4));
        *(undefined4 *)(puVar4 + 4) = 0;
        *(undefined4 *)(puVar4 + 8) = 0;
        *(undefined4 *)(puVar4 + 0xc) = 0;
        FUN_004bc150(puVar4);
      }
    }
    if (DAT_0053b9b0 == 0) {
      (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0x1b,0);
    }
  }
  ExceptionList = local_c;
  return;
}

