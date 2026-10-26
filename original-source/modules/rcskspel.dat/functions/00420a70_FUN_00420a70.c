/*
 * FUN_00420a70 at 00420a70
 * undefined FUN_00420a70(void)
 * Address ranges: 00420a70-00420aac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00420a70(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e3cd8,0x54,param_1);
  if (*(int *)(&DAT_00508b08 + iVar1 * 0x10) != 0) {
    iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e3cfc,0x57,param_1);
    (**(code **)(&DAT_00508b08 + iVar1 * 0x10))();
  }
  return;
}

