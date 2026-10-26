/*
 * FUN_004a2b40 at 004a2b40
 * undefined FUN_004a2b40(void)
 * Address ranges: 004a2b40-004a2c22
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a2b40(void)

{
  int iVar1;
  
  DAT_006a5e8c = 0;
  _strncpy(&DAT_006a5e94,s_c_texture_004fc9f0,0x19);
  _strncpy(&DAT_006a5ead,s__d3d_texture_ptr_004fc9dc,0x19);
  if (DAT_006a5e8c != 0) {
    if (DAT_006a5e8c == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a5ead,&DAT_006a5e94,
                   DAT_006a5e84);
      if (DAT_006a5e80 != 0) {
        iVar1 = DAT_006a5e80 + -4;
        FUN_004be99e(DAT_006a5e80,0x48,*(undefined4 *)(DAT_006a5e80 + -4),FUN_004a3c00);
        FUN_004bc150(iVar1);
      }
    }
    if (DAT_006a5e8c != 0) {
      FUN_004bc150(DAT_006a5e90);
      DAT_006a5e8c = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_006a5e80 = 0;
  DAT_006a5e84 = 0;
  DAT_006a5e88 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_006a5ead,&DAT_006a5e94,0);
  DAT_006a5e90 = 0;
  DAT_006a5e8c = 0;
  return;
}

