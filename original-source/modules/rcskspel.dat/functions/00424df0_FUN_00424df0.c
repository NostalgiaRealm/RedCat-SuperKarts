/*
 * FUN_00424df0 at 00424df0
 * undefined FUN_00424df0(void)
 * Address ranges: 00424df0-00424ebc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00424df0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_0050de64 == 0) {
    FUN_004afee0(s__s___d__Progress_clock_wasn_t_in_004e6f98,
                 s_D__work_rcsk_Code_game_gfx_pbar__004e6f74,0xa5,param_1);
  }
  if (DAT_0050de68 == 0) {
    DAT_0050de64 = 0;
    return;
  }
  if ((DAT_0050de5c < 0) || (1000 < DAT_0050de5c)) {
    FUN_004afee0(s__s___d__g_nr_times_called_incorr_004e6fe4,
                 s_D__work_rcsk_Code_game_gfx_pbar__004e6fc0,0xb0,DAT_0050de5c);
  }
  GetTickCount();
  iVar1 = DAT_0050de5c;
  iVar3 = 0;
  if (0 < DAT_0050de5c) {
    do {
      iVar2 = __ftol();
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      else if (100 < iVar2) {
        iVar2 = 100;
      }
      (&DAT_0050bf1c)[iVar3] = iVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  FUN_00424d20();
  DAT_0050de64 = 0;
  return;
}

