/*
 * FUN_0041e0cc at 0041e0cc
 * undefined FUN_0041e0cc(void)
 * Address ranges: 0041e0cc-0041e128
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e0cc(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_2 != (int *)0x0) &&
     (uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_004169a0), (char)uVar1 == '\0')) {
    FUN_0040fca8(param_1,param_2);
    return;
  }
  if (param_2 == (int *)0x0) {
    FUN_0041e3a4((int)param_1,0,0);
  }
  else {
    FUN_0041bd50(param_2[8]);
    FUN_0041bd54((int *)param_1[8]);
    param_1[8] = param_2[8];
  }
  (**(code **)(*param_1 + 0x10))(param_1,param_1);
  return;
}

