/*
 * FUN_0049cd80 at 0049cd80
 * undefined FUN_0049cd80(void)
 * Address ranges: 0049cd80-0049ce5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049cd80(void)

{
  DAT_006a5bf4 = 0;
  _strncpy(&DAT_006a5bfc,s_g_rails_004fbc08,0x19);
  _strncpy(&DAT_006a5c15,s_c_rail_004fbc00,0x19);
  if (DAT_006a5bf4 != 0) {
    if (DAT_006a5bf4 == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a5c15,&DAT_006a5bfc,
                   DAT_006a5bec);
      if (DAT_006a5be8 != 0) {
        FUN_004bc150(DAT_006a5be8 + -4);
      }
    }
    if (DAT_006a5bf4 != 0) {
      FUN_004bc150(DAT_006a5bf8);
      DAT_006a5bf4 = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_006a5be8 = 0;
  DAT_006a5bec = 0;
  DAT_006a5bf0 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_006a5c15,&DAT_006a5bfc,0);
  DAT_006a5bf8 = 0;
  DAT_006a5bf4 = 0;
  FUN_004be654(&LAB_0049ce60);
  return;
}

