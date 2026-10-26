/*
 * FUN_00420cf0 at 00420cf0
 * undefined FUN_00420cf0(void)
 * Address ranges: 00420cf0-00420d50
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00420cf0(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00508bd8 == 0) {
    FUN_004afee0(s__s___d__Game_actions_not_initted_004e4030,
                 s_D__work_rcsk_Code_game_ev_main_c_004e400c,0x11f);
  }
  iVar2 = 0;
  do {
    iVar1 = FUN_00420af0(s_D__work_rcsk_Code_game_ev_main_c_004e4054,0x126,iVar2);
    if (*(int *)(&DAT_00508b14 + iVar1 * 0x10) == 0) {
      iVar1 = FUN_00420a10(iVar2);
      if (iVar1 != 0) {
        FUN_00420c80(iVar2);
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xd);
  return;
}

