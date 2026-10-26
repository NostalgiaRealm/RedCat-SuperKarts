/*
 * FUN_0043e9f0 at 0043e9f0
 * undefined FUN_0043e9f0(void)
 * Address ranges: 0043e9f0-0043ea17
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e9f0(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2 != (int *)param_1[9]) {
    uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_0043be00);
    if ((char)uVar1 != '\0') {
      (**(code **)(*param_1 + 0x60))(param_1,param_2);
    }
  }
  return;
}

