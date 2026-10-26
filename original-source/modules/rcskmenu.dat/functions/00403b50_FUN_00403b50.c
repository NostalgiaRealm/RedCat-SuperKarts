/*
 * FUN_00403b50 at 00403b50
 * int * __register FUN_00403b50(int * param_1)
 * Address ranges: 00403b50-00403b72
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00403b50(int *param_1)

{
  int *piVar1;
  int iVar2;
  
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
  return param_1;
}

