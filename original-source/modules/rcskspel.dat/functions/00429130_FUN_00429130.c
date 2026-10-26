/*
 * FUN_00429130 at 00429130
 * undefined FUN_00429130(void)
 * Address ranges: 00429130-0042918b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00429130(int param_1)

{
  if (DAT_004e7be8 == 1) {
    FUN_004afee0(s__s__d____Function___s___Unable_t_004e8328,
                 s_D__work_rcsk_Code_game_gm_body_c_004e8304,0x13c,s_skelet2d_set_debug___004e82ec);
  }
  if ((param_1 != 0) && (param_1 != 1)) {
    FUN_004afee0(s__s__d____Function___s___Illegal_d_004e83a0,
                 s_D__work_rcsk_Code_game_gm_body_c_004e837c,0x141,s_skelet2d_set_debug___004e82ec,
                 param_1,0,1);
  }
  DAT_004e7bf8 = param_1;
  return;
}

