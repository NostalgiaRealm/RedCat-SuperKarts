/*
 * FUN_00403b3d at 00403b3d
 * undefined __cdecl FUN_00403b3d(char * param_1, int param_2, int * param_3, int * param_4)
 * Address ranges: 00403b3d-00403b74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00403b3d(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_00403ad7((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}

