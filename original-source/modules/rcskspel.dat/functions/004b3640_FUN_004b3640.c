/*
 * FUN_004b3640 at 004b3640
 * undefined FUN_004b3640(void)
 * Address ranges: 004b3640-004b36b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_004b3640(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5
            )

{
  int iVar1;
  
  FUN_004afce0(s__s__d__004fffc4,s_C__libraries_dxdraw_Rcpcx_cpp_004fff00,0x3f7);
  iVar1 = 0;
  if (0 < param_4) {
    do {
      FUN_004afce0(s__s__d__004fffc4,s_C__libraries_dxdraw_Rcpcx_cpp_004fff00,0x3f9);
      FUN_004b3560(param_1,param_2,iVar1,param_3,param_5);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_4);
  }
  FUN_004afce0(s__s__d__004fffc4,s_C__libraries_dxdraw_Rcpcx_cpp_004fff00,0x3fc);
  return 0;
}

