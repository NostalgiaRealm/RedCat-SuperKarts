/*
 * FUN_00428f10 at 00428f10
 * undefined FUN_00428f10(void)
 * Address ranges: 00428f10-00428f6c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00428f10(int param_1)

{
  if (DAT_004e7be8 == 1) {
    FUN_004afee0(s__s__d____Function___s___Unable_t_004e7f20,
                 s_D__work_rcsk_Code_game_gm_body_c_004e7efc,0x8c,
                 s_skelet2d_set_mouse_type___004e7ee0);
  }
  if ((param_1 < 1) || (2 < param_1)) {
    FUN_004afee0(s__s__d____Function___s___Illegal_m_004e7f98,
                 s_D__work_rcsk_Code_game_gm_body_c_004e7f74,0x91,
                 s_skelet2d_set_mouse_type___004e7ee0,param_1,1,2);
  }
  DAT_004e7bb8 = param_1;
  return;
}

