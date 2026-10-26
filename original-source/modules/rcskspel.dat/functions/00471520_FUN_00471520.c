/*
 * FUN_00471520 at 00471520
 * undefined FUN_00471520(void)
 * Address ranges: 00471520-00471550
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00471520(int param_1,int param_2)

{
  if ((param_2 < 0) || (0xb < param_2)) {
    FUN_004afee0(s__s__d____Illegal_index__d_004f6874,s_D__work_rcsk_Code_game_rcr_stop__004f6844,
                 0x1f9,param_2);
  }
  return *(undefined4 *)(param_1 + param_2 * 4);
}

