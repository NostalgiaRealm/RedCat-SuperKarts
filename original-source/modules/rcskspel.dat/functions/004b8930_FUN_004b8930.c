/*
 * FUN_004b8930 at 004b8930
 * undefined FUN_004b8930(void)
 * Address ranges: 004b8930-004b89a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b8930(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    DAT_006ab928 = 0;
    return 1;
  }
  iVar1 = DAT_006ab928;
  if (DAT_006ab918 == 0) {
    FUN_004afee0(s_s__d____error_attempting_to_find_00501338,
                 s_C__libraries_dxdraw_Hwinfo_cpp_0050137c,0x3e);
    iVar1 = DAT_006ab928;
  }
  while( true ) {
    if (iVar1 == DAT_006ab8c8) {
      DAT_006ab928 = 0;
      return -1;
    }
    if (*(int *)(DAT_006ab8c4 + 4 + iVar1 * 8) == 3) break;
    iVar1 = iVar1 + 1;
  }
  DAT_006ab928 = iVar1 + 1;
  return iVar1 + 0x41;
}

