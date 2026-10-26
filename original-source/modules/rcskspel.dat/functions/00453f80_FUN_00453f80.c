/*
 * FUN_00453f80 at 00453f80
 * undefined FUN_00453f80(void)
 * Address ranges: 00453f80-00453fca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00453f80(float param_1)

{
  if ((0.4 <= param_1) && (param_1 <= 10.0)) {
    _DAT_00543d50 = param_1;
    return;
  }
  FUN_004afee0(s_Time_out_of_bounds___s__d__004f1e14,s_D__work_rcsk_Code_game_Bon_point_004f1dec,
               0x49);
  _DAT_00543d50 = param_1;
  return;
}

