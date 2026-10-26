/*
 * FUN_00476510 at 00476510
 * undefined FUN_00476510(void)
 * Address ranges: 00476510-0047655f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_00476510(int param_1,uint param_2)

{
  if ((*(int *)(param_1 + 0x14) == 0) ||
     ((uint)((*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14)) / 0x60) <= param_2)) {
    FUN_004afee0(s__s__d____car_index_invalid_004f7cf0,s_D__work_rcsk_Code_game_ssr_m25_g_004f7cc8,
                 0x21e);
  }
  return param_2 * 0x60 + *(int *)(param_1 + 0x14);
}

