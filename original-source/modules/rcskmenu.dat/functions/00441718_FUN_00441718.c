/*
 * FUN_00441718 at 00441718
 * undefined __register FUN_00441718(int param_1, int * param_2)
 * Address ranges: 00441718-00441739
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00441718(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  FUN_0043e568(param_1,param_2);
  uVar1 = FUN_0040303c(param_2,(int)&PTR_FUN_0043be00);
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  return;
}

