/*
 * FUN_00494610 at 00494610
 * undefined FUN_00494610(void)
 * Address ranges: 00494610-004946ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00494610(void)

{
  DAT_00680b34 = 0;
  _strncpy(&DAT_00680b3c,s_g_chunks_004faf6c,0x19);
  _strncpy(&DAT_00680b55,s_c_chunk_004faf64,0x19);
  if (DAT_00680b34 != 0) {
    if (DAT_00680b34 == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_00680b55,&DAT_00680b3c,
                   DAT_00680b2c);
      if (DAT_00680b28 != 0) {
        FUN_004bc150(DAT_00680b28 + -4);
      }
    }
    if (DAT_00680b34 != 0) {
      FUN_004bc150(DAT_00680b38);
      DAT_00680b34 = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_00680b28 = 0;
  DAT_00680b2c = 0;
  DAT_00680b30 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_00680b55,&DAT_00680b3c,0);
  DAT_00680b38 = 0;
  DAT_00680b34 = 0;
  FUN_004be654(&LAB_004946f0);
  return;
}

