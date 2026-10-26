/*
 * FUN_0044246c at 0044246c
 * undefined __register FUN_0044246c(int param_1, int * param_2)
 * Address ranges: 0044246c-004424b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044246c(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  
  if (param_2 != (int *)0x0) {
    uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_0043be00);
    if ((char)uVar1 == '\0') {
      FUN_0043e0f8((int *)(param_1 + 0x134),(int)param_2,extraout_ECX);
    }
    else {
      FUN_0043e0f8((int *)(param_1 + 0x180),(int)param_2,extraout_ECX);
      FUN_0043e0f8((int *)(param_1 + 0x16c),(int)param_2,extraout_ECX_00);
    }
    param_2[9] = param_1;
  }
  return;
}

