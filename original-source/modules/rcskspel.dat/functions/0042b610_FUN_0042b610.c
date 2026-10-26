/*
 * FUN_0042b610 at 0042b610
 * undefined FUN_0042b610(void)
 * Address ranges: 0042b610-0042b675
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042b610(void)

{
  FUN_004b1d60(s_game_ini_004e93bc);
  DAT_0053ba1c = FUN_004b1ed0(s_OPTIONS_004e93d0,s_NRLAPS_004e93c8);
  if ((DAT_0053ba1c < 1) || (999 < DAT_0053ba1c)) {
    FUN_004afee0(s__s___d__Incorrect_value_for_nr_o_004e93fc,
                 s_D__work_rcsk_Code_game_Gm_ini_cp_004e93d8,0x22a,DAT_0053ba1c);
  }
  if ((&DAT_0053a6a4)[DAT_0053b9b4 * 0x25] == 0) {
    DAT_0053ba1c = 1;
  }
  return;
}

