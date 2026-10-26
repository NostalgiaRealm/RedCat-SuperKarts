/*
 * FUN_0041b0b4 at 0041b0b4
 * undefined __register FUN_0041b0b4(int param_1)
 * Address ranges: 0041b0b4-0041b0da
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b0b4(int param_1)

{
  int iVar1;
  undefined4 extraout_ECX;
  
  FUN_0041bd54(*(int **)(param_1 + 0x20));
  iVar1 = FUN_00402e7c((int *)&PTR_FUN_00416690,'\x01',extraout_ECX);
  *(int *)(param_1 + 0x20) = iVar1;
  FUN_0041bd50(iVar1);
  return;
}

