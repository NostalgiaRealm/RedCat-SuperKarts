/*
 * FUN_00411d18 at 00411d18
 * undefined FUN_00411d18(void)
 * Address ranges: 00411d18-00411d67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00411d18(int *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  
  if (((param_1[3] < 0) || ((int)param_3 < 0)) || (iVar1 = param_1[3] + param_3, iVar1 < 1)) {
    param_3 = 0;
  }
  else {
    if (param_1[2] < iVar1) {
      if (param_1[4] < iVar1) {
        FUN_00411c40(param_1,iVar1);
      }
      param_1[2] = iVar1;
    }
    FUN_0040282c(param_2,(undefined4 *)(param_1[1] + param_1[3]),param_3);
    param_1[3] = iVar1;
  }
  return param_3;
}

