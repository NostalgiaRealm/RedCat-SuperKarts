/*
 * FUN_0049f250 at 0049f250
 * undefined FUN_0049f250(void)
 * Address ranges: 0049f250-0049f29f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049f250(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined1 local_100 [256];
  
  if ((param_1 < param_2) || (param_3 < param_1)) {
    FUN_004bea92(local_100,s_Value_out_of_range_in_File___s_L_004fc644,param_4,param_5,param_1,
                 param_2,param_3);
    FUN_0049f2e0(local_100);
  }
  return;
}

