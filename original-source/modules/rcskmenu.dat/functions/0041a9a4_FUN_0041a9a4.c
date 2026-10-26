/*
 * FUN_0041a9a4 at 0041a9a4
 * undefined FUN_0041a9a4(void)
 * Address ranges: 0041a9a4-0041a9fe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a9a4(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (int *)0x0) {
    FUN_0041a8f4(param_1,(undefined4 *)0x0);
    return;
  }
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_00416588);
  if ((char)uVar1 == '\0') {
    uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_004164a4);
    if ((char)uVar1 == '\0') {
      FUN_0040fca8(param_1,param_2);
    }
    else {
      FUN_0041a8f4(param_1,param_2);
    }
  }
  else {
    FUN_0041a8f4(param_1,(undefined4 *)param_2[1]);
  }
  return;
}

