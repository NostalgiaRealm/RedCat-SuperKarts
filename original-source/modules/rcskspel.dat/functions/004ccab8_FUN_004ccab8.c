/*
 * FUN_004ccab8 at 004ccab8
 * undefined FUN_004ccab8(void)
 * Address ranges: 004ccab8-004ccae4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004ccab8(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((param_3 == 10) && (param_1 < 0)) {
    uVar1 = 1;
    param_3 = 10;
  }
  else {
    uVar1 = 0;
  }
  FUN_004ccae5(param_1,param_2,param_3,uVar1);
  return param_2;
}

