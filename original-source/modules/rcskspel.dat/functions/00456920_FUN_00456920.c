/*
 * FUN_00456920 at 00456920
 * undefined FUN_00456920(void)
 * Address ranges: 00456920-00456973
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00456920(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_00430dd0(param_2,1,3,s_D__work_rcsk_Code_game_Bon_shotb_004f21d4,0x344);
  uVar1 = __ftol(s_D__work_rcsk_Code_game_Bon_shotb_004f2200,0x345);
  FUN_00430dd0(param_3,0,uVar1);
  (&DAT_00543d4c)[param_1 * 0x18 + param_2 * 8] = param_3;
  return;
}

