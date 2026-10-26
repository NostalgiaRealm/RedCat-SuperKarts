/*
 * FUN_00424d20 at 00424d20
 * undefined FUN_00424d20(void)
 * Address ranges: 00424d20-00424db8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424d20(void)

{
  int iVar1;
  undefined4 *puVar2;
  CHAR local_40 [64];
  
  FUN_004b1d60(s_SndGfx_ini_004e6eec);
  FUN_004b1e70(s_PROGRESS_004e6f00,s_COUNT_004e6ef8,DAT_0050de5c);
  if ((DAT_0050de5c < 0) || (1000 < DAT_0050de5c)) {
    FUN_004afee0(s__s___d__g_nr_times_called_incorr_004e6f30,
                 s_D__work_rcsk_Code_game_gfx_pbar__004e6f0c,0x6f,DAT_0050de5c);
  }
  iVar1 = 0;
  if (0 < DAT_0050de5c) {
    puVar2 = &DAT_0050bf1c;
    do {
      wsprintfA(local_40,s_percent_d_004e6f5c,iVar1);
      FUN_004b1e70(s_PROGRESS_004e6f68,local_40,*puVar2);
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < DAT_0050de5c);
  }
  return;
}

