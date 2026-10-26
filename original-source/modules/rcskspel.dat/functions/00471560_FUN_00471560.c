/*
 * FUN_00471560 at 00471560
 * undefined FUN_00471560(void)
 * Address ranges: 00471560-00471594
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_00471560(int param_1,int param_2)

{
  if ((param_2 < 0) || (0xb < param_2)) {
    FUN_004afee0(s__s__d____Illegal_index__d_004f68c0,s_D__work_rcsk_Code_game_rcr_stop__004f6890,
                 0x20f,param_2);
  }
  return param_1 + 0x90 + param_2 * 8;
}

