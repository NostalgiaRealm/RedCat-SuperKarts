/*
 * FUN_00493b30 at 00493b30
 * undefined FUN_00493b30(void)
 * Address ranges: 00493b30-00493c0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00493b30(void)

{
  DAT_00680aec = 0;
  _strncpy(&DAT_00680af4,s_g_driver_map_004faca0,0x19);
  _strncpy(&DAT_00680b0d,s_c_waypoint_004fac94,0x19);
  if (DAT_00680aec != 0) {
    if (DAT_00680aec == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_00680b0d,&DAT_00680af4,
                   DAT_00680ae4);
      if (DAT_00680ae0 != 0) {
        FUN_004bc150(DAT_00680ae0 + -4);
      }
    }
    if (DAT_00680aec != 0) {
      FUN_004bc150(DAT_00680af0);
      DAT_00680aec = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_00680ae0 = 0;
  DAT_00680ae4 = 0;
  DAT_00680ae8 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_00680b0d,&DAT_00680af4,0);
  DAT_00680af0 = 0;
  DAT_00680aec = 0;
  FUN_004be654(&LAB_00493c10);
  return;
}

