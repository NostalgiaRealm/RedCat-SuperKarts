/*
 * FUN_00403be8 at 00403be8
 * undefined __register FUN_00403be8(int * param_1, int param_2)
 * Address ranges: 00403be8-00403c10
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403be8(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((param_2 != 0) && (-1 < *(int *)(param_2 + -8))) {
    LOCK();
    *(int *)(param_2 + -8) = *(int *)(param_2 + -8) + 1;
    UNLOCK();
  }
  LOCK();
  iVar2 = *param_1;
  *param_1 = param_2;
  UNLOCK();
  if ((iVar2 != 0) && (0 < *(int *)(iVar2 + -8))) {
    LOCK();
    piVar1 = (int *)(iVar2 + -8);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      FUN_0040272c(iVar2 + -8);
    }
  }
  return;
}

