/*
 * FUN_004599f0 at 004599f0
 * undefined FUN_004599f0(void)
 * Address ranges: 004599f0-00459c76
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004599f0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  char *pcVar7;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [28];
  undefined1 local_9c [16];
  undefined1 local_8c [16];
  undefined1 local_7c [16];
  undefined1 local_6c [16];
  undefined1 local_5c [16];
  undefined1 local_4c [16];
  undefined1 local_3c [16];
  undefined1 local_2c [16];
  undefined1 local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ce0db;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x50) == -1) {
    ExceptionList = &local_c;
    iVar2 = FUN_0049ff90(param_2,0,FUN_004a0610);
    *(int *)(param_1 + 0x50) = iVar2;
    if (iVar2 == -1) {
      uVar3 = FUN_00463d20(local_4c,param_2);
      local_4 = 0;
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar7 = &DAT_004f297c;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(&DAT_004f297c,~uVar6 - 1);
      local_4._0_1_ = 1;
      uVar4 = FUN_00463d20(local_1c,0xae);
      local_4._0_1_ = 2;
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar7 = s_D__work_rcsk_Code_game_Hud_Eleme_004f2984;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_D__work_rcsk_Code_game_Hud_Eleme_004f2984,~uVar6 - 1);
      local_4._0_1_ = 3;
      FUN_0040b4f0(0);
      uVar6 = 0xffffffff;
      pcVar7 = s_HeadUp_Display_exception_in__004f29ac;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_HeadUp_Display_exception_in__004f29ac,~uVar6 - 1);
      local_4._0_1_ = 4;
      uVar5 = FUN_00459040(local_9c,local_e8,local_c8);
      local_4._0_1_ = 5;
      uVar5 = FUN_0041b630(local_6c,uVar5,&DAT_004f2980);
      local_4._0_1_ = 6;
      uVar4 = FUN_00459040(local_2c,uVar5,uVar4);
      local_4._0_1_ = 7;
      uVar4 = FUN_00459040(local_8c,uVar4,local_d8);
      local_4._0_1_ = 8;
      uVar4 = FUN_0041b630(local_7c,uVar4,s_Unable_to_create_object_for_anim_004f2954);
      local_4._0_1_ = 9;
      uVar3 = FUN_00459040(local_5c,uVar4,uVar3);
      local_4._0_1_ = 10;
      uVar3 = FUN_0041b630(local_3c,uVar3,&DAT_004f2950);
      local_4 = CONCAT31(local_4._1_3_,0xb);
      FUN_00459dc0(uVar3);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_b8,&DAT_004d6580);
    }
    *(undefined4 *)(iVar2 * 0xa9 + DAT_006a5c38 + 0xa5) = 1;
    *(undefined1 *)(DAT_006a5c38 + *(int *)(param_1 + 0x50) * 0xa9 + 0x90) = 1;
  }
  iVar2 = *(int *)(param_1 + 0x50);
  if (*(int *)(DAT_006a5c38 + iVar2 + 4 + iVar2 * 0xa8) != param_2) {
    *(int *)(DAT_006a5c38 + iVar2 + 4 + iVar2 * 0xa8) = param_2;
  }
  ExceptionList = local_c;
  return;
}

