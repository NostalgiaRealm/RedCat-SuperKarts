/*
 * FUN_004b9970 at 004b9970
 * undefined FUN_004b9970(void)
 * Address ranges: 004b9970-004b99ba
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b9970(void)

{
  HLOCAL pvVar1;
  
  if (DAT_006ab944 != 0) {
    pvVar1 = LocalFree(DAT_006ab93c);
    if (pvVar1 != (HLOCAL)0x0) {
      FUN_004afee0(s__s__d____failure_to_free_file_li_00501aac,
                   s_C__libraries_dxdraw_Fileio_cpp_00501928,0x1b9);
      return;
    }
    FUN_004bf2c5(DAT_006ab934);
    DAT_006ab944 = 0;
  }
  return;
}

