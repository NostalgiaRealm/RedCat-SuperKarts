/*
 * FUN_004424b8 at 004424b8
 * undefined __register FUN_004424b8(int param_1, int * param_2)
 * Address ranges: 004424b8-004424ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004424b8(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_0043be00);
  if ((char)uVar1 == '\0') {
    FUN_0043e120((int *)(param_1 + 0x134),(int)param_2);
  }
  else {
    FUN_0043e120((int *)(param_1 + 0x16c),(int)param_2);
    FUN_0043e120((int *)(param_1 + 0x180),(int)param_2);
  }
  param_2[9] = 0;
  return;
}

