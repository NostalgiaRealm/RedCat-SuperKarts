/*
 * FUN_0042642c at 0042642c
 * undefined FUN_0042642c(void)
 * Address ranges: 0042642c-00426454
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042642c(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
    uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_004260b4);
    if ((char)uVar1 != '\0') {
      FUN_00426404(param_1,(int)param_2);
    }
  }
  return;
}

