/*
 * FUN_0041106c at 0041106c
 * undefined __register FUN_0041106c(int param_1, int * param_2)
 * Address ranges: 0041106c-0041109c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041106c(int param_1,int *param_2)

{
  if (*(int *)(param_1 + 8) != 0) {
    (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  }
  FUN_004054a8((int *)(param_1 + 8),param_2);
  if (*(int *)(param_1 + 8) != 0) {
    (**(code **)(**(int **)(param_1 + 8) + 0xc))(*(int **)(param_1 + 8),param_1);
  }
  return;
}

