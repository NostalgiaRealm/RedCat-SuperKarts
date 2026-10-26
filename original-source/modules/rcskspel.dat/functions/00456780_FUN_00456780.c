/*
 * FUN_00456780 at 00456780
 * undefined FUN_00456780(void)
 * Address ranges: 00456780-004567e4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00456780(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = __ftol(s_D__work_rcsk_Code_game_Bon_shotb_004f20a0,0x2f4);
  uVar1 = __ftol(uVar1);
  uVar1 = __ftol(uVar1);
  FUN_00430dd0(uVar1);
  FUN_00430dd0(param_2,1,3,s_D__work_rcsk_Code_game_Bon_shotb_004f20cc,0x2f5);
  (&DAT_00543d44)[param_1 * 0x18 + param_2 * 8] = param_3;
  return;
}

