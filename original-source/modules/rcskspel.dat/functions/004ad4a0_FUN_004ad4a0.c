/*
 * FUN_004ad4a0 at 004ad4a0
 * undefined FUN_004ad4a0(void)
 * Address ranges: 004ad4a0-004ad567
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ad4a0(void)

{
  DAT_006a634c = 0;
  _strncpy(&DAT_006a6354,s_vertex_ptr_004fe13c,0x19);
  _strncpy(&DAT_006a636d,s_vertex_t_004fe130,0x19);
  if (DAT_006a634c != 0) {
    if (DAT_006a634c == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a636d,&DAT_006a6354,
                   DAT_006a6344);
      FUN_004bc150(DAT_006a6340);
    }
    if (DAT_006a634c != 0) {
      FUN_004bc150(DAT_006a6350);
      DAT_006a634c = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_006a6340 = 0;
  DAT_006a6344 = 0;
  _DAT_006a6348 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_006a636d,&DAT_006a6354,0);
  DAT_006a6350 = 0;
  DAT_006a634c = 0;
  return;
}

