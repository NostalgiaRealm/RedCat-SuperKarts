/*
 * FUN_00467b1c at 00467b1c
 * undefined __register FUN_00467b1c(int * param_1, int param_2)
 * Address ranges: 00467b1c-00467b5c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00467b1c(int *param_1,int param_2)

{
  int *piVar1;
  int aiStack_10 [2];
  
  FUN_00440a04(param_1,param_2);
  FUN_00406c20(*(undefined4 *)(param_2 + 8),aiStack_10);
  piVar1 = (int *)FUN_00467a8c(param_1,aiStack_10);
  if ((piVar1 != (int *)0x0) && (*(char *)((int)param_1 + 0x20d) == '\0')) {
    FUN_0043fc90(piVar1,'\0',-1);
  }
  return;
}

