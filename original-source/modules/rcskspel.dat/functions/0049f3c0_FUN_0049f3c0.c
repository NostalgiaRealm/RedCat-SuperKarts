/*
 * FUN_0049f3c0 at 0049f3c0
 * undefined FUN_0049f3c0(void)
 * Address ranges: 0049f3c0-0049f4a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049f3c0(void)

{
  int iVar1;
  
  DAT_006a5c44 = 0;
  _strncpy(&DAT_006a5c4c,s__d3d_objects_004fc6f8,0x19);
  _strncpy(&DAT_006a5c65,s_c_3dobject_004fc6ec,0x19);
  if (DAT_006a5c44 != 0) {
    if (DAT_006a5c44 == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a5c65,&DAT_006a5c4c,
                   DAT_006a5c3c);
      if (DAT_006a5c38 != 0) {
        iVar1 = DAT_006a5c38 + -4;
        FUN_004be99e(DAT_006a5c38,0xa9,*(undefined4 *)(DAT_006a5c38 + -4),FUN_004aa0b0);
        FUN_004bc150(iVar1);
      }
    }
    if (DAT_006a5c44 != 0) {
      FUN_004bc150(DAT_006a5c48);
      DAT_006a5c44 = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_006a5c38 = 0;
  DAT_006a5c3c = 0;
  DAT_006a5c40 = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,&DAT_006a5c65,&DAT_006a5c4c,0);
  DAT_006a5c48 = 0;
  DAT_006a5c44 = 0;
  return;
}

