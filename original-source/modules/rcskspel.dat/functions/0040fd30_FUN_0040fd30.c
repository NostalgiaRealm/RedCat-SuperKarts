/*
 * FUN_0040fd30 at 0040fd30
 * undefined FUN_0040fd30(void)
 * Address ranges: 0040fd30-0040fd68
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0040fd30(int param_1,int param_2)

{
  if ((0 < param_2) && (param_2 < 6)) {
    return *(undefined4 *)(param_1 + 0x1a0 + param_2 * 4);
  }
  FUN_004afee0(s__s__d____Reaction_rate__d_not_in_004df818,
               s_D__work_rcsk_Code_game_ai_rcr_se_004df7ec,0x2ed,param_2,1,5);
  return 0;
}

