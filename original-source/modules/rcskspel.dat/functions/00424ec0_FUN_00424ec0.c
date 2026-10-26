/*
 * FUN_00424ec0 at 00424ec0
 * undefined FUN_00424ec0(void)
 * Address ranges: 00424ec0-00424f69
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424ec0(void)

{
  DWORD DVar1;
  int iVar2;
  
  if (DAT_0050de68 != 0) {
    if ((DAT_0050de5c < 0) || (999 < DAT_0050de5c)) {
      FUN_004afee0(s__s___d__g_nr_times_called_incorr_004e7034,
                   s_D__work_rcsk_Code_game_gfx_pbar__004e7010,0xe6,DAT_0050de5c);
    }
    DVar1 = GetTickCount();
    (&DAT_0050cebc)[DAT_0050de5c] = DVar1 - DAT_0050de60;
    DAT_0050de5c = DAT_0050de5c + 1;
    return;
  }
  if ((DAT_0050de5c < 0) || (999 < DAT_0050de5c)) {
    FUN_004afee0(s__s___d__g_nr_times_called_incorr_004e7084,
                 s_D__work_rcsk_Code_game_gfx_pbar__004e7060,0xf5,DAT_0050de5c);
  }
  iVar2 = (&DAT_0050bf1c)[DAT_0050de5c];
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if (100 < iVar2) {
    iVar2 = 100;
  }
  FUN_00424f70(iVar2);
  DAT_0050de5c = DAT_0050de5c + 1;
  return;
}

