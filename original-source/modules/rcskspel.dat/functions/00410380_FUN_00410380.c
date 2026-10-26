/*
 * FUN_00410380 at 00410380
 * undefined FUN_00410380(void)
 * Address ranges: 00410380-004103cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00410380(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (DAT_0053be28 == param_1) {
    return -1;
  }
  iVar1 = 0;
  if (0 < DAT_00508610) {
    piVar2 = &DAT_00503ef0;
    do {
      if (*piVar2 == param_1) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x47;
    } while (iVar1 < DAT_00508610);
  }
  FUN_004afee0(s__s__d____Object___d__is_not_an_A_004dfc38,
               s_D__work_rcsk_Code_game_ai_rcr_ut_004dfc10,0x5e,param_1);
  return 0;
}

