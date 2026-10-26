/*
 * FUN_004aa8c0 at 004aa8c0
 * undefined FUN_004aa8c0(void)
 * Address ranges: 004aa8c0-004aa987
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004aa8c0(void)

{
  DAT_006a5f84 = 0;
  _strncpy(&DAT_006a5f8c,s_anims3d_ptr_004fd424,0x19);
  _strncpy(&DAT_006a5fa5,s_anim3d_t_004fd418,0x19);
  if (DAT_006a5f84 != 0) {
    if (DAT_006a5f84 == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a5fa5,&DAT_006a5f8c,
                   DAT_006a5f7c);
      FUN_004bc150(DAT_006a5f78);
    }
    if (DAT_006a5f84 != 0) {
      FUN_004bc150(DAT_006a5f88);
      DAT_006a5f84 = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_006a5f78 = 0;
  DAT_006a5f7c = 0;
  DAT_006a5f80 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_006a5fa5,&DAT_006a5f8c,0);
  DAT_006a5f88 = 0;
  DAT_006a5f84 = 0;
  return;
}

