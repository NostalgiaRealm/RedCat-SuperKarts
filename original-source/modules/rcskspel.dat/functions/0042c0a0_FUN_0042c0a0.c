/*
 * FUN_0042c0a0 at 0042c0a0
 * undefined FUN_0042c0a0(void)
 * Address ranges: 0042c0a0-0042c165
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042c0a0(void)

{
  undefined4 uVar1;
  
  FUN_004b1d60(s_Race_INI_004e9c2c);
  _DAT_0053be74 = FUN_004b1ed0(s_GAME_SETTINGS_004e9c40,s_groep_004e9c38);
  FUN_004afce0(s_Entry_load_player_info_004e9c50);
  FUN_004b1d60(s_Race_INI_004e9c68);
  FUN_004b1ed0(s_PLAYER_004e9c7c,s_money_004e9c74);
  FUN_004afce0(s_set_game_playercar_004e9c84);
  DAT_0053be2c = FUN_004b1ed0(s_PLAYER_004e9c9c,&PTR_DAT_004e9c98);
  if (DAT_0053be2c < 7) {
    if ((DAT_0053be2c < 0) || (9 < DAT_0053be2c)) {
      FUN_004afee0(s__set_player_info___s__d____Inval_004e9cc8,
                   s_D__work_rcsk_Code_game_Gm_ini_cp_004e9ca4,0x440,DAT_0053be2c);
    }
  }
  else {
    DAT_0053be2c = 6;
  }
  DAT_0053be08 = FUN_004b1ed0(s_PLAYER_004e9cfc,s_copland_004e9cf4);
  FUN_0042c680();
  uVar1 = FUN_004b1ed0(s_PLAYER_004e9d0c,s_DAMAGE_004e9d04);
  FUN_004354a0(uVar1);
  return;
}

