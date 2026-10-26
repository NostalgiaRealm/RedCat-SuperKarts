/*
 * FUN_00420ba0 at 00420ba0
 * undefined FUN_00420ba0(void)
 * Address ranges: 00420ba0-00420c7f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00420ba0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (0xc < param_1) {
    FUN_004afee0(s__s__d____Too_many_game_actions_004e3e20,
                 s_D__work_rcsk_Code_game_ev_main_c_004e3dfc,0xd3);
  }
  if (DAT_00508bd8 == 0) {
    FUN_004afee0(s__s___d__Game_Actions_not_initted_004e3e68,
                 s_D__work_rcsk_Code_game_ev_main_c_004e3e44,0xd8);
  }
  iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e3e8c,0xdc,param_1);
  if (*(int *)(&DAT_00508b14 + iVar1 * 0x10) != 0) {
    iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e3eb0,0xe2,param_1);
    *(undefined4 *)(&DAT_00508b0c + iVar1 * 0x10) = param_3;
    iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e3ed4,0xe3,param_1);
    *(undefined4 *)(&DAT_00508b08 + iVar1 * 0x10) = param_2;
    iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e3ef8,0xe4,param_1);
    *(undefined4 *)(&DAT_00508b10 + iVar1 * 0x10) = param_4;
    FUN_00420a70(param_1);
    iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e3f1c,0xea,param_1);
    *(undefined4 *)(&DAT_00508b14 + iVar1 * 0x10) = 0;
  }
  return;
}

