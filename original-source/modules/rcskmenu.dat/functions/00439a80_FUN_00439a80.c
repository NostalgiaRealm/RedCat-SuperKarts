/*
 * FUN_00439a80 at 00439a80
 * undefined __register FUN_00439a80(int param_1, int param_2)
 * Address ranges: 00439a80-00439ab9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00439a80(int param_1,int param_2)

{
  undefined4 extraout_ECX;
  
  if (*(int *)(param_1 + 0x3c) != 0) {
    FUN_0043430c(*(int *)(param_1 + 0x3c),*(int *)(param_1 + 0x38));
  }
  *(int *)(param_1 + 0x3c) = param_2;
  if (param_2 != 0) {
    FUN_00434350(param_2,*(int *)(param_1 + 0x38));
    FUN_00414858(*(int *)(param_1 + 0x3c),param_1,extraout_ECX);
  }
  FUN_00439348(param_1);
  return;
}

