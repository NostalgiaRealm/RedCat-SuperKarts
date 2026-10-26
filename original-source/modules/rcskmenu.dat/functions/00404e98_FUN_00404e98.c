/*
 * FUN_00404e98 at 00404e98
 * undefined __register FUN_00404e98(int * param_1, int param_2, int param_3)
 * Address ranges: 00404e98-00404ebe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404e98(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (param_2 != 0) {
    LOCK();
    *(int *)(param_2 + -8) = *(int *)(param_2 + -8) + 1;
    UNLOCK();
  }
  if (iVar2 != 0) {
    LOCK();
    piVar1 = (int *)(iVar2 + -8);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      *(int *)(iVar2 + -8) = *(int *)(iVar2 + -8) + 1;
      FUN_00404e5c(param_1,param_3);
    }
  }
  *param_1 = param_2;
  return;
}

