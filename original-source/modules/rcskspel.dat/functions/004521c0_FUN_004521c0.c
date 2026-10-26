/*
 * FUN_004521c0 at 004521c0
 * undefined FUN_004521c0(void)
 * Address ranges: 004521c0-0045221c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004521c0(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_004afce0(s_CBonusController__Point_004f1a30);
  iVar2 = (*(code *)**(undefined4 **)(param_1 + 0x30))
                    (s_D__work_rcsk_Code_game_Bon_Main__004f1a4c,0x3d3);
  iVar1 = (int)param_2;
  FUN_00430dd0(param_2,0,iVar2 + -1);
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x34) + 4) + iVar1 * 4) == 0) {
    param_2 = s_CBonusController__GetPoint__Inva_004f1a70;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_2,&DAT_004d5538);
  }
  return;
}

