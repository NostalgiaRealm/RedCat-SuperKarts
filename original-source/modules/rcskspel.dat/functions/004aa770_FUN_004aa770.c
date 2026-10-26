/*
 * FUN_004aa770 at 004aa770
 * undefined FUN_004aa770(void)
 * Address ranges: 004aa770-004aa837
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004aa770(void)

{
  DAT_006a5f3c = 0;
  _strncpy(&DAT_006a5f44,s_frame3d_ptr_004fd40c,0x19);
  _strncpy(&DAT_006a5f5d,s_frame3d_t_004fd400,0x19);
  if (DAT_006a5f3c != 0) {
    if (DAT_006a5f3c == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a5f5d,&DAT_006a5f44,
                   DAT_006a5f34);
      FUN_004bc150(DAT_006a5f30);
    }
    if (DAT_006a5f3c != 0) {
      FUN_004bc150(DAT_006a5f40);
      DAT_006a5f3c = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_006a5f30 = 0;
  DAT_006a5f34 = 0;
  DAT_006a5f38 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_006a5f5d,&DAT_006a5f44,0);
  DAT_006a5f40 = 0;
  DAT_006a5f3c = 0;
  return;
}

