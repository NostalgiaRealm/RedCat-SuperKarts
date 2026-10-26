/*
 * FUN_004148ec at 004148ec
 * undefined __register FUN_004148ec(int param_1, int param_2, undefined4 param_3)
 * Address ranges: 004148ec-00414916
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004148ec(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar1 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',param_3);
    *(undefined4 *)(param_1 + 0x10) = uVar1;
  }
  FUN_0040f504(*(int **)(param_1 + 0x10),param_2);
  *(int *)(param_2 + 4) = param_1;
  return;
}

