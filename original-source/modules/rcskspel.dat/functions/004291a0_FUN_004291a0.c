/*
 * FUN_004291a0 at 004291a0
 * undefined FUN_004291a0(void)
 * Address ranges: 004291a0-00429206
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004291a0(int param_1)

{
  if (DAT_004e7be8 == 1) {
    FUN_004afee0(s__s__d____Function___s___Unable_t_004e8430,
                 s_D__work_rcsk_Code_game_gm_body_c_004e840c,0x157,
                 s_skelet2d_set_renderfocus___004e83f0);
  }
  if (param_1 != 0) {
    if (param_1 != 1) {
      FUN_004afee0(s__s__d____Function___s___Illegal_p_004e84a8,
                   s_D__work_rcsk_Code_game_gm_body_c_004e8484,0x163,
                   s_skelet2d_set_renderfocus___004e83f0,param_1);
      return;
    }
    DAT_004e7bec = 2;
    return;
  }
  DAT_004e7bec = 1;
  return;
}

