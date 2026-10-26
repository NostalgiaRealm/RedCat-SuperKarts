/*
 * FUN_00456860 at 00456860
 * undefined FUN_00456860(void)
 * Address ranges: 00456860-004568c4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00456860(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_00430dd0(param_2,1,3,s_D__work_rcsk_Code_game_Bon_shotb_004f2150,0x31c);
  uVar1 = __ftol(s_D__work_rcsk_Code_game_Bon_shotb_004f217c,0x31d);
  uVar1 = __ftol(uVar1);
  uVar1 = __ftol(uVar1);
  FUN_00430dd0(uVar1);
  (&DAT_00543d58)[param_1 * 0x18 + param_2 * 8] = param_3;
  return;
}

