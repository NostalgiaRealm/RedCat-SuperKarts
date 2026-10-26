/*
 * FUN_0042c170 at 0042c170
 * undefined FUN_0042c170(void)
 * Address ranges: 0042c170-0042c228
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042c170(void)

{
  FUN_004b1d60(s_track_INI_004e9d14);
  DAT_0053a6a0 = FUN_004b1ed0(&DAT_004e9d28,s_COUNT_004e9d20);
  if ((DAT_0053a6a0 < 1) || (0x1e < DAT_0053a6a0)) {
    FUN_004afee0(s__load_track_info___s__d____Inval_004e9d54,
                 s_D__work_rcsk_Code_game_Gm_ini_cp_004e9d30,0x48d,DAT_0053a6a0);
  }
  FUN_004afce0(s_set_game_etappe_004e9d88);
  FUN_004b1d60(s_Race_INI_004e9d9c);
  DAT_0053b9b4 = FUN_004b1ed0(s_ETAPPE_004e9db0,s_ETAPPE_004e9da8);
  if ((DAT_0053b9b4 < 0) || (DAT_0053a6a0 < DAT_0053b9b4)) {
    FUN_004afee0(s__load_etappe_info___s__d____Inva_004e9ddc,
                 s_D__work_rcsk_Code_game_Gm_ini_cp_004e9db8,0x49b,DAT_0053b9b4);
  }
  FUN_0042ab60(DAT_0053b9b4);
  DAT_0053ba08 = FUN_004b1ed0(s_ETAPPE_004e9e18,s_DIRECTION_004e9e0c);
  return;
}

