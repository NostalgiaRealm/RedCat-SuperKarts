/*
 * FUN_0049ad80 at 0049ad80
 * undefined FUN_0049ad80(void)
 * Address ranges: 0049ad80-0049ae51
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049ad80(void)

{
  DAT_006847dc = 0;
  _strncpy(&DAT_006847e4,s_c_damage__004fb88c,0x19);
  _strncpy(&DAT_006847fd,s_g_damages_004fb880,0x19);
  if (DAT_006847dc != 0) {
    if (DAT_006847dc == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006847fd,&DAT_006847e4,
                   DAT_006847d4);
      FUN_004bc150(DAT_006847d0);
    }
    if (DAT_006847dc != 0) {
      FUN_004bc150(DAT_006847e0);
      DAT_006847dc = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_006847d0 = 0;
  DAT_006847d4 = 0;
  DAT_006847d8 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_006847fd,&DAT_006847e4,0);
  DAT_006847e0 = 0;
  DAT_006847dc = 0;
  FUN_004be654(&LAB_0049ae60);
  return;
}

