/*
 * FUN_004522e0 at 004522e0
 * undefined FUN_004522e0(void)
 * Address ranges: 004522e0-0045233c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004522e0(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_004afce0(s_CBonusController__ShotBonus_004f1b94);
  iVar2 = (*(code *)**(undefined4 **)(param_1 + 0x28))
                    (s_D__work_rcsk_Code_game_Bon_Main__004f1bb4,0x418);
  iVar1 = (int)param_2;
  FUN_00430dd0(param_2,0,iVar2 + -1);
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x2c) + 4) + iVar1 * 4) == 0) {
    param_2 = s_CBonusController__GetShotBonus__I_004f1bd8;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_2,&DAT_004d5538);
  }
  return;
}

