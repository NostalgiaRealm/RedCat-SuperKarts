/*
 * FUN_00465c90 at 00465c90
 * undefined FUN_00465c90(void)
 * Address ranges: 00465c90-00465f0b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00465c90(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined1 local_68 [32];
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  undefined1 local_28 [19];
  undefined1 local_15;
  undefined1 *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004cf8d6;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  local_14 = &stack0xffffff1c;
  local_8 = 0;
  iVar4 = param_1[2];
  if (iVar4 == 0) {
    iVar4 = FUN_0044ff80();
    if (param_1[0xf] == iVar4) goto LAB_00465e80;
  }
  else {
    if (iVar4 == 1) {
      local_14 = &stack0xffffff1c;
      cVar1 = FUN_00466220();
      if (cVar1 == '\0') {
        (**(code **)(*param_1 + 0x18))();
        (**(code **)(*param_1 + 0xc))();
      }
      else {
        (**(code **)(*param_1 + 0x10))();
      }
      goto LAB_00465e80;
    }
    if (iVar4 != 2) {
      local_14 = &stack0xffffff1c;
      FUN_0040b4f0(0);
      uVar5 = 0xffffffff;
      pcVar6 = &DAT_004f4528;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(&DAT_004f4528,~uVar5 - 1);
      local_8._0_1_ = 1;
      uVar2 = FUN_00463d20(local_d8,0x89);
      local_8._0_1_ = 2;
      local_28[0] = local_15;
      FUN_0040b4f0(0);
      uVar5 = 0xffffffff;
      pcVar6 = s_D__work_rcsk_Code_game_Rco_Bonus_004f4530;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Bonus_004f4530,~uVar5 - 1);
      local_8._0_1_ = 3;
      local_38[0] = local_15;
      FUN_0040b4f0(0);
      uVar5 = 0xffffffff;
      pcVar6 = s_HeadUp_Display_exception_in__004f4558;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_HeadUp_Display_exception_in__004f4558,~uVar5 - 1);
      local_8._0_1_ = 4;
      uVar3 = FUN_00459040(local_78,local_38,local_28);
      local_8._0_1_ = 5;
      uVar3 = FUN_0041b630(local_c8,uVar3,&DAT_004f452c);
      local_8._0_1_ = 6;
      uVar2 = FUN_00459040(local_a8,uVar3,uVar2);
      local_8._0_1_ = 7;
      uVar2 = FUN_00459040(local_88,uVar2,local_48);
      local_8._0_1_ = 8;
      uVar2 = FUN_0041b630(local_98,uVar2,s_Unknown_state_in_CRcoBonus_004f450c);
      local_8._0_1_ = 9;
      uVar2 = FUN_0041b630(local_b8,uVar2,&DAT_004f4508);
      local_8 = CONCAT31(local_8._1_3_,10);
      FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_68,&DAT_004d6580);
    }
    local_14 = &stack0xffffff1c;
    cVar1 = FUN_00466220();
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0x1c))();
      goto LAB_00465e80;
    }
    (**(code **)(*param_1 + 0x18))();
  }
  (**(code **)(*param_1 + 0xc))();
LAB_00465e80:
  iVar4 = FUN_00459cb0();
  FUN_00458440(DAT_006a5c38 + iVar4 * 0xa9 + 0x74);
  iVar4 = FUN_00459cb0();
  FUN_00458460(*(char *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x90) != '\0');
  iVar4 = FUN_0044ff80();
  param_1[0xf] = iVar4;
  iVar4 = FUN_004500b0();
  param_1[0x10] = iVar4;
  iVar4 = FUN_004503c0();
  param_1[0x12] = iVar4;
  *unaff_FS_OFFSET = local_10;
  return;
}

