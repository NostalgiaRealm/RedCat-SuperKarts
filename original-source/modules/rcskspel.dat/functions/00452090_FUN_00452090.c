/*
 * FUN_00452090 at 00452090
 * undefined FUN_00452090(void)
 * Address ranges: 00452090-004520f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00452090(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_004afce0(s_CBonusController__OwnedBonus_004f19b4);
  iVar2 = (int)param_2;
  if (param_2 == (char *)0xffffffff) {
    iVar2 = DAT_00508610;
  }
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x20))
                    (s_D__work_rcsk_Code_game_Bon_Main__004f19d4,0x356);
  FUN_00430dd0(iVar2,0,iVar1 + -1);
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x24) + 4) + iVar2 * 4) == 0) {
    param_2 = s_CBonusController__GetRacerBonus__004f19f8;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_2,&DAT_004d5538);
  }
  return;
}

