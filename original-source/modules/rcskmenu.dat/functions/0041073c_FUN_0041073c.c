/*
 * FUN_0041073c at 0041073c
 * undefined __register FUN_0041073c(int * param_1)
 * Address ranges: 0041073c-00410752
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041073c(int *param_1)

{
  if (param_1[1] == 0) {
    (**(code **)(*param_1 + 0x30))(param_1,1);
  }
  param_1[1] = param_1[1] + 1;
  return;
}

