/*
 * FUN_00420ab0 at 00420ab0
 * undefined FUN_00420ab0(void)
 * Address ranges: 00420ab0-00420aec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00420ab0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e3d20,0x6e,param_1);
  if (*(int *)(&DAT_00508b10 + iVar1 * 0x10) != 0) {
    iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e3d44,0x70,param_1);
    (**(code **)(&DAT_00508b10 + iVar1 * 0x10))();
  }
  return;
}

