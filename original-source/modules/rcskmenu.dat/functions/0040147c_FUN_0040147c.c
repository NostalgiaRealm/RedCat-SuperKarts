/*
 * FUN_0040147c at 0040147c
 * undefined __register FUN_0040147c(int * param_1)
 * Address ranges: 0040147c-00401493
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040147c(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_1[1];
  iVar2 = *param_1;
  *piVar1 = iVar2;
  *(int **)(iVar2 + 4) = piVar1;
  *param_1 = (int)DAT_0047d454;
  DAT_0047d454 = param_1;
  return;
}

