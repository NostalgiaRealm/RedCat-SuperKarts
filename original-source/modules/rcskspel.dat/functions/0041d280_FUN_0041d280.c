/*
 * FUN_0041d280 at 0041d280
 * undefined FUN_0041d280(void)
 * Address ranges: 0041d280-0041d39e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041d280(void)

{
  undefined4 *puVar1;
  float10 fVar2;
  
  if (DAT_0053ba6c != 0) {
    fVar2 = (float10)FUN_0041d1d0(0);
    _DAT_004e2ab8 = (float)fVar2;
    fVar2 = (float10)FUN_0041d1d0(1);
    _DAT_004e2abc = (float)fVar2;
    fVar2 = (float10)FUN_0041d1d0(2);
    DAT_004e2ac0 = (float)fVar2;
    fVar2 = (float10)FUN_0041d1d0(3);
    _DAT_004e2ac4 = (float)fVar2;
  }
  puVar1 = &DAT_00508648;
  do {
    puVar1[-10] = 0;
    *puVar1 = 1;
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x508670);
  FUN_004afce0(s_Calling__init_cameras__004e2dcc);
  FUN_004980d0(10);
  FUN_004afce0(s_Calling__init_player_camera__004e2de4);
  FUN_0041dee0();
  FUN_004afce0(s_Calling__init_start_camera__004e2e04);
  FUN_0041cc30(1);
  FUN_004afce0(s_Calling__init_temp_camera__004e2e24);
  FUN_0041d3a0(8);
  FUN_004afce0(s_Calling__init_ai_cockpit_camera__004e2e40);
  FUN_0041d4a0(9);
  FUN_004afce0(s_Calling__init_topview_camera__004e2e64);
  FUN_0041d540(3);
  FUN_004afce0(s_Calling__init_tankstation_camera_004e2e84);
  FUN_0041cc50(4);
  FUN_004afce0(s_Calling__init_any_camera__004e2ea8);
  FUN_0041cbf0(6);
  FUN_0041cc10(7);
  FUN_004afce0(s_Calling__add_camera__004e2ec4);
  DAT_00508634 = FUN_00498280();
  FUN_004afce0(s_Calling__change_active_camera__004e2edc);
  FUN_0041d6c0(0);
  FUN_004afce0(s_Exiting__init_game_cameras__004e2efc);
  return;
}

