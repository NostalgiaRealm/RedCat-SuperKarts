/*
 * FUN_00422105 at 00422105
 * undefined __cdecl FUN_00422105(char * param_1, int param_2, int * param_3, int * param_4)
 * Address ranges: 00422105-0042213c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00422105(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_0042209f((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}

