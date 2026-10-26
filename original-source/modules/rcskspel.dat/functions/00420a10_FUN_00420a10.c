/*
 * FUN_00420a10 at 00420a10
 * undefined FUN_00420a10(void)
 * Address ranges: 00420a10-00420a61
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00420a10(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e3c38,0x3a,param_1);
  if (*(int *)(&DAT_00508b0c + iVar1 * 0x10) == 0) {
    FUN_004afee0(s__s___d__NULL_pointer_for_command_004e3c80,
                 s_D__work_rcsk_Code_game_ev_main_c_004e3c5c,0x3c,param_1);
  }
  iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e3cb4,0x3f,param_1);
  (**(code **)(&DAT_00508b0c + iVar1 * 0x10))();
  return;
}

