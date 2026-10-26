/*
 * FUN_00403b0c at 00403b0c
 * undefined __cdecl FUN_00403b0c(uint param_1, int param_2, int * param_3, int * param_4)
 * Address ranges: 00403b0c-00403b3c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00403b0c(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_00403ad7(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}

