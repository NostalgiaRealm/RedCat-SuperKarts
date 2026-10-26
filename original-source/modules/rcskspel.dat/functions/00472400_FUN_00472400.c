/*
 * FUN_00472400 at 00472400
 * undefined FUN_00472400(void)
 * Address ranges: 00472400-0047245f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00472400(int param_1)

{
  if ((param_1 < 0) || (0x20 < param_1)) {
    FUN_004afee0(s__s__d___tga_close__Illegal_handl_004f6ea8,
                 s_D__work_rcsk_Code_game_rrrtga_cp_004f6e84,0xcb,param_1);
  }
  param_1 = param_1 * 0xe;
  if (((&DAT_00544bc0)[param_1] != '\0') && (*(int *)(&DAT_00544bc2 + param_1) != 0)) {
    FUN_004bff99(*(int *)(&DAT_00544bc2 + param_1));
  }
  (&DAT_00544bc0)[param_1] = 0;
  *(undefined4 *)(&DAT_00544bc2 + param_1) = 0;
  return;
}

