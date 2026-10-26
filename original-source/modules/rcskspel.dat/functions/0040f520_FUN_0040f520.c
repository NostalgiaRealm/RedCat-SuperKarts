/*
 * FUN_0040f520 at 0040f520
 * undefined FUN_0040f520(void)
 * Address ranges: 0040f520-0040f562
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0040f520(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < DAT_00508610) {
    piVar2 = (int *)(param_1 + 0x1cc);
    do {
      if (*piVar2 == param_2) {
        FUN_004afee0(s__s__d____A_racer_was_specified_m_004df2f0,
                     s_D__work_rcsk_Code_game_ai_rcr_se_004df2c4,0x74);
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < DAT_00508610);
  }
  return;
}

