/*
 * FUN_004ad1f0 at 004ad1f0
 * undefined FUN_004ad1f0(void)
 * Address ranges: 004ad1f0-004ad2b7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ad1f0(void)

{
  DAT_006a6304 = 0;
  _strncpy(&DAT_006a630c,s_draw_order_004fe124,0x19);
  _strncpy(&DAT_006a6325,s_draw_info_t_004fe118,0x19);
  if (DAT_006a6304 != 0) {
    if (DAT_006a6304 == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a6325,&DAT_006a630c,
                   DAT_006a62fc);
      FUN_004bc150(DAT_006a62f8);
    }
    if (DAT_006a6304 != 0) {
      FUN_004bc150(DAT_006a6308);
      DAT_006a6304 = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_006a62f8 = 0;
  DAT_006a62fc = 0;
  _DAT_006a6300 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_006a6325,&DAT_006a630c,0);
  DAT_006a6308 = 0;
  DAT_006a6304 = 0;
  return;
}

