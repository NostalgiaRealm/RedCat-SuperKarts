/*
 * FUN_004107f8 at 004107f8
 * undefined __register FUN_004107f8(int * param_1)
 * Address ranges: 004107f8-00410808
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004107f8(int *param_1)

{
  param_1[1] = param_1[1] + -1;
  if (param_1[1] == 0) {
    (**(code **)(*param_1 + 0x30))(param_1,0);
  }
  return;
}

