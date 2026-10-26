/*
 * FUN_004290c0 at 004290c0
 * undefined FUN_004290c0(void)
 * Address ranges: 004290c0-0042911b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004290c0(int param_1)

{
  if (DAT_004e7be8 == 1) {
    FUN_004afee0(s__s__d____Function___s___Unable_t_004e8224,
                 s_D__work_rcsk_Code_game_gm_body_c_004e8200,0x122,
                 s_skelet2d_set_show_palette___004e81e4);
  }
  if ((param_1 < 0) || (1 < param_1)) {
    FUN_004afee0(s__s__d____Function___s___Illegal_s_004e829c,
                 s_D__work_rcsk_Code_game_gm_body_c_004e8278,0x127,
                 s_skelet2d_set_show_palette___004e81e4,param_1,0,1);
  }
  DAT_004e7be4 = param_1;
  return;
}

