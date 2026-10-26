/*
 * FUN_0049c910 at 0049c910
 * undefined FUN_0049c910(void)
 * Address ranges: 0049c910-0049c9ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049c910(void)

{
  DAT_006a5bac = 0;
  _strncpy(&DAT_006a5bb4,s_g_planes_004fbbf4,0x19);
  _strncpy(&DAT_006a5bcd,s_c_plane_004fbbec,0x19);
  if (DAT_006a5bac != 0) {
    if (DAT_006a5bac == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a5bcd,&DAT_006a5bb4,
                   DAT_006a5ba4);
      if (DAT_006a5ba0 != 0) {
        FUN_004bc150(DAT_006a5ba0 + -4);
      }
    }
    if (DAT_006a5bac != 0) {
      FUN_004bc150(DAT_006a5bb0);
      DAT_006a5bac = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_006a5ba0 = 0;
  DAT_006a5ba4 = 0;
  DAT_006a5ba8 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_006a5bcd,&DAT_006a5bb4,0);
  DAT_006a5bb0 = 0;
  DAT_006a5bac = 0;
  FUN_004be654(&LAB_0049c9f0);
  return;
}

