/*
 * FUN_0042c680 at 0042c680
 * undefined FUN_0042c680(void)
 * Address ranges: 0042c680-0042c754
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0042c680(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd01a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = FUN_0042abc0(param_1);
  switch(uVar1) {
  case 0:
  case 2:
  case 4:
  case 5:
    DAT_0053be60 = FUN_004b1ed0(s_PLAYER_004ea114,s_position_004ea108);
    break;
  case 1:
  case 3:
    DAT_0053be60 = 0;
    break;
  default:
    uVar1 = FUN_0042abc0(s_D__work_rcsk_Code_game_Gm_ini_cp_004ea11c,0x5c0);
    FUN_004afee0(s_Unknown_race_type__d___s___d__004ea140,uVar1);
  }
  iVar2 = FUN_0042abe0();
  if (iVar2 < DAT_0053be60) {
    FUN_00431640();
    local_4 = 0;
    FUN_004afce0(s_Artificially_adapted_player_info_004ea160,DAT_0053be60,iVar2);
    local_4 = 0xffffffff;
    DAT_0053be60 = iVar2;
    FUN_00431680();
  }
  ExceptionList = local_c;
  return;
}

