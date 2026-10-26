/*
 * FUN_004715a0 at 004715a0
 * undefined FUN_004715a0(void)
 * Address ranges: 004715a0-004715d1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004715a0(int param_1,int param_2)

{
  if ((param_2 < 0) || (0xb < param_2)) {
    FUN_004afee0(s__s__d____Illegal_index__d_004f690c,s_D__work_rcsk_Code_game_rcr_stop__004f68dc,
                 0x225,param_2);
  }
  return param_1 + 0x30 + param_2 * 8;
}

