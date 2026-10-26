/*
 * FUN_004103d0 at 004103d0
 * undefined FUN_004103d0(void)
 * Address ranges: 004103d0-00410419
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004103d0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == -1) {
    return -1;
  }
  iVar1 = 0;
  if (0 < DAT_00508610) {
    piVar2 = &DAT_00503f5c;
    do {
      if (*piVar2 == param_1) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x47;
    } while (iVar1 < DAT_00508610);
  }
  FUN_004afee0(s__s__d____Person__d__INTEL_INI__n_004dfc8c,
               s_D__work_rcsk_Code_game_ai_rcr_ut_004dfc64,0x7d,param_1);
  return -2;
}

