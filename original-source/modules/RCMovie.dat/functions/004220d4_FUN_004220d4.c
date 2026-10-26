/*
 * FUN_004220d4 at 004220d4
 * undefined __cdecl FUN_004220d4(uint param_1, int param_2, int * param_3, int * param_4)
 * Address ranges: 004220d4-00422104
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004220d4(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_0042209f(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}

