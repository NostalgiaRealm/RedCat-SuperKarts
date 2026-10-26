/*
 * FUN_00420b40 at 00420b40
 * undefined FUN_00420b40(void)
 * Address ranges: 00420b40-00420b9d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00420b40(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00508bd8 == 0) {
    FUN_004afee0(s__s___d__Game_actions_not_initted_004e3db4,
                 s_D__work_rcsk_Code_game_ev_main_c_004e3d90,0xb1);
  }
  iVar2 = 0;
  do {
    iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e3dd8,0xb8,iVar2);
    if (*(int *)(&DAT_00508b14 + iVar1 * 0x10) == 0) {
      FUN_00420c80(iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xd);
  DAT_00508bd8 = 0;
  return;
}

