/*
 * FUN_00452220 at 00452220
 * undefined FUN_00452220(void)
 * Address ranges: 00452220-0045227c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00452220(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_004afce0(s_CBonusController__Point_004f1aa4);
  iVar2 = (*(code *)**(undefined4 **)(param_1 + 0x30))
                    (s_D__work_rcsk_Code_game_Bon_Main__004f1ac0,0x3ea);
  iVar1 = (int)param_2;
  FUN_00430dd0(param_2,0,iVar2 + -1);
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x34) + 4) + iVar1 * 4) == 0) {
    param_2 = s_CBonusController__GetPoint__Inva_004f1ae4;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_2,&DAT_004d5538);
  }
  return;
}

