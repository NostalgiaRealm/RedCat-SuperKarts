/*
 * FUN_004a7320 at 004a7320
 * undefined FUN_004a7320(void)
 * Address ranges: 004a7320-004a7405
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a7320(void)

{
  int iVar1;
  
  DAT_006a5eec = 0;
  _strncpy(&DAT_006a5ef4,s_c_mesh_004fd11c,0x19);
  _strncpy(&DAT_006a5f0d,s__d3d_mesh_ptr_004fd10c,0x19);
  if (DAT_006a5eec != 0) {
    if (DAT_006a5eec == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a5f0d,&DAT_006a5ef4,
                   DAT_006a5ee4);
      if (DAT_006a5ee0 != 0) {
        iVar1 = DAT_006a5ee0 + -4;
        FUN_004be99e(DAT_006a5ee0,0xbc,*(undefined4 *)(DAT_006a5ee0 + -4),FUN_004a82a0);
        FUN_004bc150(iVar1);
      }
    }
    if (DAT_006a5eec != 0) {
      FUN_004bc150(DAT_006a5ef0);
      DAT_006a5eec = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_006a5ee0 = 0;
  DAT_006a5ee4 = 0;
  DAT_006a5ee8 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_006a5f0d,&DAT_006a5ef4,0);
  DAT_006a5ef0 = 0;
  DAT_006a5eec = 0;
  return;
}

