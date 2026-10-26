/*
 * FUN_0046bf80 at 0046bf80
 * undefined FUN_0046bf80(void)
 * Address ranges: 0046bf80-0046c12b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046bf80(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  undefined1 local_dc [16];
  undefined1 local_cc [16];
  undefined1 local_bc [16];
  undefined1 local_ac [16];
  undefined1 local_9c [16];
  undefined1 local_8c [16];
  undefined1 local_7c [16];
  undefined1 local_6c [32];
  undefined1 local_4c [20];
  undefined1 local_38 [16];
  undefined1 local_28 [19];
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004d0306;
  local_10 = ExceptionList;
  iVar2 = *(int *)(param_1 + 8);
  local_14 = &stack0xffffff18;
  local_8 = 0;
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      ExceptionList = &local_10;
      FUN_0046c910();
    }
    else if (iVar2 != 2) {
      ExceptionList = &local_10;
      local_14 = &stack0xffffff18;
      FUN_0040b4f0(0);
      uVar5 = 0xffffffff;
      pcVar6 = &DAT_004f5958;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(&DAT_004f5958,~uVar5 - 1);
      local_8._0_1_ = 1;
      uVar3 = FUN_00463d20(local_7c,100);
      local_8._0_1_ = 2;
      local_28[0] = local_15;
      FUN_0040b4f0(0);
      uVar5 = 0xffffffff;
      pcVar6 = s_D__work_rcsk_Code_game_Rco_Speci_004f5960;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_D__work_rcsk_Code_game_Rco_Speci_004f5960,~uVar5 - 1);
      local_8._0_1_ = 3;
      local_38[0] = local_15;
      FUN_0040b4f0(0);
      uVar5 = 0xffffffff;
      pcVar6 = s_HeadUp_Display_exception_in__004f5990;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_HeadUp_Display_exception_in__004f5990,~uVar5 - 1);
      local_8._0_1_ = 4;
      uVar4 = FUN_00459040(local_dc,local_38,local_28);
      local_8._0_1_ = 5;
      uVar4 = FUN_0041b630(local_cc,uVar4,&DAT_004f595c);
      local_8._0_1_ = 6;
      uVar3 = FUN_00459040(local_ac,uVar4,uVar3);
      local_8._0_1_ = 7;
      uVar3 = FUN_00459040(local_8c,uVar3,local_4c);
      local_8._0_1_ = 8;
      uVar3 = FUN_0041b630(local_9c,uVar3,s_Unreachable_code_004f5944);
      local_8._0_1_ = 9;
      uVar3 = FUN_0041b630(local_bc,uVar3,&DAT_004f5940);
      local_8 = CONCAT31(local_8._1_3_,10);
      FUN_00459dc0(uVar3);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_6c,&DAT_004d6580);
    }
  }
  ExceptionList = local_10;
  return;
}

