/*
 * FUN_004b9840 at 004b9840
 * undefined FUN_004b9840(void)
 * Address ranges: 004b9840-004b98d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b9840(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    FUN_004afee0(s__s__d____null_ptr_assignment___005019c4,s_C__libraries_dxdraw_Fileio_cpp_00501928
                 ,0x166);
    return;
  }
  if (DAT_006ab944 == 0) {
    FUN_004afce0(s__s__d____file_close_00501a94,s_C__libraries_dxdraw_Fileio_cpp_00501928,0x16c);
    FUN_004bf2c5(param_1);
    return;
  }
  iVar1 = FUN_004ccbb9(DAT_006ab934);
  iVar2 = FUN_004ccbb9(param_1);
  if (iVar2 == iVar1) {
    if (DAT_006ab944 == 0) {
      FUN_004afee0(s__s__d____unopened_resource_file_a_00501a68,
                   s_C__libraries_dxdraw_Fileio_cpp_00501928,0x173);
      return;
    }
  }
  else {
    FUN_004bf2c5(param_1);
  }
  return;
}

