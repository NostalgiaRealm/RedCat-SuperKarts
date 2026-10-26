/*
 * FUN_004505ec at 004505ec
 * undefined __register FUN_004505ec(int * param_1)
 * Address ranges: 004505ec-004505fa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004505ec(int *param_1)

{
  param_1[5] = param_1[5] + -1;
  if (param_1[5] < 1) {
    FUN_00402eac(param_1);
  }
  return;
}

