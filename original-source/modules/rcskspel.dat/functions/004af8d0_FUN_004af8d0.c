/*
 * FUN_004af8d0 at 004af8d0
 * undefined FUN_004af8d0(void)
 * Address ranges: 004af8d0-004af997
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004af8d0(void)

{
  DAT_006a63fc = 0;
  _strncpy(&DAT_006a6404,s_light_ptr_004fe870,0x19);
  _strncpy(&DAT_006a641d,s_light_t_004fe868,0x19);
  if (DAT_006a63fc != 0) {
    if (DAT_006a63fc == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a641d,&DAT_006a6404,
                   DAT_006a63f4);
      FUN_004bc150(DAT_006a63f0);
    }
    if (DAT_006a63fc != 0) {
      FUN_004bc150(DAT_006a6400);
      DAT_006a63fc = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_006a63f0 = 0;
  DAT_006a63f4 = 0;
  _DAT_006a63f8 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_006a641d,&DAT_006a6404,0);
  DAT_006a6400 = 0;
  DAT_006a63fc = 0;
  return;
}

