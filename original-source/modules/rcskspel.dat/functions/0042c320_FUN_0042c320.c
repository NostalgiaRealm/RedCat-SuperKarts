/*
 * FUN_0042c320 at 0042c320
 * undefined FUN_0042c320(void)
 * Address ranges: 0042c320-0042c3a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042c320(void)

{
  int iVar1;
  
  FUN_004b1d60(s_Race_INI_004e9f20);
  iVar1 = FUN_004b1ed0(s_game_settings_004e9f38,s_fx_volume_004e9f2c);
  if (iVar1 < 0x65) {
    if (iVar1 < 0) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 100;
  }
  FUN_004afce0(s__s__d____Effects_setting__d_004e9f6c,s_D__work_rcsk_Code_game_Gm_ini_cp_004e9f48,
               0x4dd,iVar1);
  DAT_0053b9a4 = FUN_004b1ed0(s_game_settings_004e9f98,s_mx_volume_004e9f8c);
  if (100 < DAT_0053b9a4) {
    _DAT_0053b9a8 = iVar1;
    DAT_0053b9a4 = 100;
    return;
  }
  if (DAT_0053b9a4 < 0) {
    DAT_0053b9a4 = 0;
  }
  _DAT_0053b9a8 = iVar1;
  return;
}

