/*
 * FUN_0040ffd0 at 0040ffd0
 * undefined __register FUN_0040ffd0(int * param_1, int * param_2, undefined4 param_3)
 * Address ranges: 0040ffd0-0040fff7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040ffd0(int *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[1];
  if (param_2 != piVar1) {
    if (piVar1 != (int *)0x0) {
      FUN_00410568(piVar1,(int)param_1,param_3);
    }
    if (param_2 != (int *)0x0) {
      FUN_0041050c(param_2,param_1);
    }
  }
  return;
}

