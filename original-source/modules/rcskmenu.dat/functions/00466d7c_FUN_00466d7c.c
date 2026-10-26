/*
 * FUN_00466d7c at 00466d7c
 * undefined __register FUN_00466d7c(int * param_1, int * param_2)
 * Address ranges: 00466d7c-00466daf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466d7c(int *param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[0x7d];
  if (param_2 != piVar1) {
    if (piVar1 != (int *)0x0) {
      FUN_004675bc(piVar1,param_1);
    }
    (**(code **)(*param_1 + 0x60))(param_1,param_2);
    if (param_2 != (int *)0x0) {
      FUN_00467514((int)param_2,(int)param_1);
    }
  }
  return;
}

