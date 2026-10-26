/*
 * FUN_00476580 at 00476580
 * undefined FUN_00476580(void)
 * Address ranges: 00476580-004765c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_00476580(int param_1,uint param_2)

{
  if ((*(int *)(param_1 + 4) == 0) ||
     ((uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 5) <= param_2)) {
    FUN_004afee0(s__s__d____color_index_invalid_004f7d34,s_D__work_rcsk_Code_game_ssr_m25_g_004f7d0c
                 ,0x23d);
  }
  return param_2 * 0x20 + *(int *)(param_1 + 4);
}

