/*
 * FUN_00452280 at 00452280
 * undefined FUN_00452280(void)
 * Address ranges: 00452280-004522dc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00452280(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_004afce0(s_CBonusController__ShotBonus_004f1b18);
  iVar2 = (*(code *)**(undefined4 **)(param_1 + 0x28))
                    (s_D__work_rcsk_Code_game_Bon_Main__004f1b38,0x401);
  iVar1 = (int)param_2;
  FUN_00430dd0(param_2,0,iVar2 + -1);
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x2c) + 4) + iVar1 * 4) == 0) {
    param_2 = s_CBonusController__GetShotBonus__I_004f1b5c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_2,&DAT_004d5538);
  }
  return;
}

