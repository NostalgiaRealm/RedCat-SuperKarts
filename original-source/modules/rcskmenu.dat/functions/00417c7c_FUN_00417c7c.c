/*
 * FUN_00417c7c at 00417c7c
 * undefined __register FUN_00417c7c(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00417c7c-00417c8f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417c7c(int *param_1,undefined4 param_2,undefined4 param_3)

{
  if ((char)param_2 != (char)param_1[6]) {
    *(char *)(param_1 + 6) = (char)param_2;
    FUN_00403088(param_1,param_2,param_3);
  }
  return;
}

