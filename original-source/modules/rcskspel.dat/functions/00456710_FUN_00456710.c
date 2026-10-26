/*
 * FUN_00456710 at 00456710
 * undefined FUN_00456710(void)
 * Address ranges: 00456710-00456774
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00456710(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = __ftol(s_D__work_rcsk_Code_game_Bon_shotb_004f2048,0x2e2);
  uVar1 = __ftol(uVar1);
  uVar1 = __ftol(uVar1);
  FUN_00430dd0(uVar1);
  FUN_00430dd0(param_2,1,3,s_D__work_rcsk_Code_game_Bon_shotb_004f2074,0x2e3);
  *(undefined4 *)(&DAT_00543d40 + param_2 * 0x20 + param_1 * 0x60) = param_3;
  return;
}

