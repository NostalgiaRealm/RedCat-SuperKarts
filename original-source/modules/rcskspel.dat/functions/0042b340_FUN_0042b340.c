/*
 * FUN_0042b340 at 0042b340
 * undefined FUN_0042b340(void)
 * Address ranges: 0042b340-0042b48c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042b340(void)

{
  uint uVar1;
  
  FUN_004b1d60(s_SndGfx_ini_004e9124);
  uVar1 = FUN_004b1ed0(s_SPECIAL_EFFECTS_004e9144,s_squash_speed_limit_004e9130);
  DAT_0053ba7c = (float)uVar1;
  uVar1 = FUN_004b1ed0(s_SPECIAL_EFFECTS_004e916c,s_squash_shake_strength_004e9154);
  _DAT_0053ba80 = (float)uVar1;
  DAT_0053ba88 = FUN_004b1ed0(s_SPECIAL_EFFECTS_004e9188,s_squash_time_004e917c);
  uVar1 = FUN_004b1ed0(s_SPECIAL_EFFECTS_004e91a8,s_squash_ratio_004e9198);
  DAT_0053ba84 = (float)uVar1 * 0.1;
  uVar1 = FUN_004b1ed0(s_SPECIAL_EFFECTS_004e91cc,s_squash_hit_angle_004e91b8);
  _DAT_0053ba8c = (float)uVar1;
  uVar1 = FUN_004b1ed0(s_SPECIAL_EFFECTS_004e91f0,s_squash_extra_range_004e91dc);
  _DAT_0053ba90 = (float)uVar1;
  if (_DAT_0053ba8c == 0.0) {
    _DAT_0053ba8c = 100.0;
  }
  DAT_0053ba9c = FUN_004b1ed0(s_SPECIAL_EFFECTS_004e920c,s_ice_enabled_004e9200);
  uVar1 = FUN_004b1ed0(s_SPECIAL_EFFECTS_004e922c,s_ice_skid_factor_004e921c);
  DAT_0053ba98 = (float)uVar1;
  uVar1 = FUN_004b1ed0(s_SPECIAL_EFFECTS_004e924c,s_ice_speed_limit_004e923c);
  _DAT_0053ba94 = (float)uVar1;
  return;
}

