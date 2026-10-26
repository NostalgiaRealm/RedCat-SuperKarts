/*
 * FUN_004266c0 at 004266c0
 * undefined __register FUN_004266c0(int param_1, int param_2)
 * Address ranges: 004266c0-004266de
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004266c0(int param_1,int param_2)

{
  undefined4 extraout_ECX;
  
  FUN_0040f504(*(int **)(param_1 + 0x24),param_2);
  *(int *)(param_2 + 0x4c) = param_1;
  FUN_00414858(param_2,param_1,extraout_ECX);
  return;
}

