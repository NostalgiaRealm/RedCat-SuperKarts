/*
 * FUN_0042c570 at 0042c570
 * undefined FUN_0042c570(void)
 * Address ranges: 0042c570-0042c67a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042c570(void)

{
  undefined4 uVar1;
  undefined1 local_84 [32];
  undefined1 local_64 [100];
  
  FUN_004afce0(s_Entry_write_player_info_004ea054);
  FUN_004b1d60(s_Race_INI_004ea070);
  FUN_004b1e70(s_PLAYER_004ea088,s_finished_004ea07c,DAT_0053be50);
  if (DAT_0053be50 != 0) {
    uVar1 = FUN_00435490();
    FUN_004b1e70(s_PLAYER_004ea098,s_damage_004ea090,uVar1);
    FUN_004b1e70(s_PLAYER_004ea0ac,s_tracktime_004ea0a0,DAT_0053be58);
    FUN_004b1e70(s_PLAYER_004ea0c0,s_position_004ea0b4,DAT_0053be60);
    FUN_004513c0();
    uVar1 = FUN_004521b0();
    FUN_004b1e70(s_PLAYER_004ea0d4,s_EUROSTARS_004ea0c8,uVar1);
    FUN_004b1e70(s_PLAYER_004ea0e8,s_FASTEST_LAP_004ea0dc,DAT_0053be5c);
    FUN_004bea92(local_84,&DAT_004ea0f0,DAT_00508610);
    FUN_004bea92(local_64,s__d__d__d_004ea0f4,DAT_0053be2c,DAT_0053be60,DAT_0053be58);
    FUN_004b1e30(s_RACERS_004ea100,local_84,local_64);
  }
  return;
}

