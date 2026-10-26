/*
 * FUN_0042b220 at 0042b220
 * undefined FUN_0042b220(void)
 * Address ranges: 0042b220-0042b33b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042b220(void)

{
  int iVar1;
  
  FUN_004b1d60(s_SndGfx_ini_004e8fd4);
  DAT_0053ba24 = FUN_004b1ed0(s_GFX_OPTIONS_004e8fe8,s_clouds_004e8fe0);
  DAT_0053ba28 = FUN_004b1ed0(s_GFX_OPTIONS_004e9000,s_finish_flag_004e8ff4);
  DAT_0053ba2c = FUN_004b1ed0(s_GFX_OPTIONS_004e9018,s_skidmarks_004e900c);
  DAT_0053ba30 = FUN_004b1ed0(s_GFX_OPTIONS_004e9034,s_fade_skmarks_004e9024);
  DAT_0053ba38 = FUN_004b1ed0(s_GFX_OPTIONS_004e904c,s_particles_004e9040);
  _DAT_0053ba3c = FUN_004b1ed0(s_GFX_OPTIONS_004e9064,s_part_rain_004e9058);
  _DAT_0053ba40 = FUN_004b1ed0(s_GFX_OPTIONS_004e9080,s_disable_overlay_004e9070);
  DAT_0053ba44 = FUN_004b1ed0(s_GFX_OPTIONS_004e909c,s_overlay_detail_004e908c);
  DAT_0053ba50 = FUN_004b1ed0(s_GFX_OPTIONS_004e90b8,s_object_lights_004e90a8);
  DAT_0053ba5c = FUN_004b1ed0(s_GFX_OPTIONS_004e90cc,s_gamma_004e90c4);
  DAT_0053ba60 = FUN_004b1ed0(s_GFX_OPTIONS_004e90e8,s_alpha_blending_004e90d8);
  DAT_0053ba78 = FUN_004b1ed0(s_GFX_OPTIONS_004e9100,s_jetstreams_004e90f4);
  iVar1 = FUN_004b1ed0(s_GFX_OPTIONS_004e9118,s_windowed_004e910c);
  if (iVar1 == 1) {
    FUN_004afca0(1);
  }
  return;
}

