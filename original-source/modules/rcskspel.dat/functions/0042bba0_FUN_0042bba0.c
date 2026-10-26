/*
 * FUN_0042bba0 at 0042bba0
 * undefined FUN_0042bba0(void)
 * Address ranges: 0042bba0-0042bbea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042bba0(void)

{
  FUN_004afce0(s_set_visible_chunks_004e9928);
  FUN_004b1d60(s_game_ini_004e993c);
  DAT_0053b9d0 = FUN_004b1ed0(s_OPTIONS_004e9958,s_VISIBLECHUNKS_004e9948);
  if (DAT_0053b9d0 < 10) {
    DAT_0053b9d0 = 10;
    return;
  }
  if (0x32 < DAT_0053b9d0) {
    DAT_0053b9d0 = 0x32;
  }
  return;
}

