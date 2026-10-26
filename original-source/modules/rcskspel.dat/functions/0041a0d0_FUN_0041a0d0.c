/*
 * FUN_0041a0d0 at 0041a0d0
 * undefined FUN_0041a0d0(void)
 * Address ranges: 0041a0d0-0041a1fc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a0d0(void)

{
  undefined **ppuVar1;
  
  FUN_00419260();
  FUN_004b1850(0,0,0,s_Tweak_settings_menu_004e2014);
  FUN_004b1850(0,0x14,0x28,s___Upgrade_motor_004e2028);
  if (DAT_0053bef0 == 0) {
    ppuVar1 = &PTR_DAT_004e2040;
  }
  else {
    ppuVar1 = (undefined **)&DAT_004e2038;
  }
  FUN_004b1850(0,200,0x28,ppuVar1);
  FUN_004b1850(0,0x14,0x3c,s___Upgrade_gearbox_004e2044);
  if (DAT_0053bf00 == 0) {
    ppuVar1 = &PTR_DAT_004e2060;
  }
  else {
    ppuVar1 = (undefined **)&DAT_004e2058;
  }
  FUN_004b1850(0,200,0x3c,ppuVar1);
  FUN_004b1850(0,0x14,0x50,s___Tires_004e2064);
  if (DAT_0053bef4 == 0) {
    ppuVar1 = &PTR_DAT_004e2074;
  }
  else {
    ppuVar1 = (undefined **)&DAT_004e206c;
  }
  FUN_004b1850(0,200,0x50,ppuVar1);
  FUN_004b1850(0,0x14,100,s___Player_car_004e2078);
  FUN_004b1850(0,200,100,&DAT_004e2088,DAT_0053be2c);
  FUN_004b1850(0,0x14,0x78,s___Copy_current_to_car_F12____004e208c);
  FUN_004b1850(0,200,0x78,&DAT_004e20ac,DAT_004e17d0);
  FUN_004b1850(0,0,0xa0,s_Escape_to_leave_menu_004e20b0);
  return;
}

