/*
 * FUN_004567f0 at 004567f0
 * undefined FUN_004567f0(void)
 * Address ranges: 004567f0-00456854
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004567f0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_00430dd0(param_2,1,3,s_D__work_rcsk_Code_game_Bon_shotb_004f20f8,0x309);
  uVar1 = __ftol(s_D__work_rcsk_Code_game_Bon_shotb_004f2124,0x30a);
  uVar1 = __ftol(uVar1);
  uVar1 = __ftol(uVar1);
  FUN_00430dd0(uVar1);
  (&DAT_00543d54)[param_1 * 0x18 + param_2 * 8] = param_3;
  return;
}

