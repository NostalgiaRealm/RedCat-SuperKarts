/*
 * FUN_0043ceec at 0043ceec
 * undefined __register FUN_0043ceec(int param_1, int * param_2)
 * Address ranges: 0043ceec-0043cf14
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043ceec(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  FUN_0043cd10(param_1,(int)param_2);
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_0043ad04);
  if ((char)uVar1 != '\0') {
    *(int *)(param_1 + 0x38) = param_2[0xe];
  }
  return;
}

