/*
 * FUN_0043f21c at 0043f21c
 * undefined __register FUN_0043f21c(int * param_1, undefined4 param_2)
 * Address ranges: 0043f21c-0043f249
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f21c(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  for (; param_1 != (int *)0x0; param_1 = (int *)param_1[9]) {
    uVar1 = FUN_00403024(param_1,(int)&PTR_FUN_00427e2c);
    if ((char)uVar1 != '\0') {
      FUN_0042d720((int)param_1,param_2);
    }
  }
  return;
}

