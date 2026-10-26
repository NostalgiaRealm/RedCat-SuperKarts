/*
 * FUN_0048f7c0 at 0048f7c0
 * undefined FUN_0048f7c0(void)
 * Address ranges: 0048f7c0-0048f89d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0048f7c0(void)

{
  DAT_0067ee2c = 0;
  _strncpy(&DAT_0067ee34,s_main_objects_004fa4b0,0x19);
  _strncpy(&DAT_0067ee4d,s_c_obj_main_004fa4a4,0x19);
  if (DAT_0067ee2c != 0) {
    if (DAT_0067ee2c == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_0067ee4d,&DAT_0067ee34,
                   DAT_0067ee24);
      if (DAT_0067ee20 != 0) {
        FUN_004bc150(DAT_0067ee20 + -4);
      }
    }
    if (DAT_0067ee2c != 0) {
      FUN_004bc150(DAT_0067ee30);
      DAT_0067ee2c = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_0067ee20 = 0;
  DAT_0067ee24 = 0;
  DAT_0067ee28 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_0067ee4d,&DAT_0067ee34,0);
  DAT_0067ee30 = 0;
  DAT_0067ee2c = 0;
  FUN_004be654(&LAB_0048f8a0);
  return;
}

