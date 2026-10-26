/*
 * FUN_00403b74 at 00403b74
 * undefined __register FUN_00403b74(int * param_1, int param_2)
 * Address ranges: 00403b74-00403ba2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403b74(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  do {
    iVar2 = *param_1;
    if ((iVar2 != 0) && (*param_1 = 0, 0 < *(int *)(iVar2 + -8))) {
      LOCK();
      piVar1 = (int *)(iVar2 + -8);
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (*piVar1 == 0) {
        FUN_0040272c(iVar2 + -8);
      }
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  return;
}

