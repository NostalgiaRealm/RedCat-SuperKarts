/*
 * FUN_00420c80 at 00420c80
 * undefined FUN_00420c80(void)
 * Address ranges: 00420c80-00420ced
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00420c80(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_00508bd8 == 0) {
    FUN_004afee0(s__s___d__Game_Actions_not_initted_004e3f64,
                 s_D__work_rcsk_Code_game_ev_main_c_004e3f40,0xfe);
  }
  iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e3f88,0x102,param_1);
  if (*(int *)(&DAT_00508b14 + iVar1 * 0x10) != 0) {
    FUN_004afee0(s__s___d__Trying_to_delete_a_free_g_004e3fd0,
                 s_D__work_rcsk_Code_game_ev_main_c_004e3fac,0x104,param_1);
  }
  FUN_00420ab0(param_1);
  FUN_00420990(param_1);
  return;
}

