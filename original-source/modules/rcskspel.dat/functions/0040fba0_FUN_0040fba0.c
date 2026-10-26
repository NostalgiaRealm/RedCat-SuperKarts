/*
 * FUN_0040fba0 at 0040fba0
 * undefined FUN_0040fba0(void)
 * Address ranges: 0040fba0-0040fbd6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0040fba0(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < DAT_00508610)) {
    return *(undefined4 *)(param_1 + 0x1cc + param_2 * 4);
  }
  FUN_004afee0(s__s__d____invalid_racer_index__d_004df644,
               s_D__work_rcsk_Code_game_ai_rcr_se_004df618,0x248,param_2);
  return 0;
}

