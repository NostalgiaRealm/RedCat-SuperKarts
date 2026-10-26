/*
 * FUN_00403ba4 at 00403ba4
 * undefined __register FUN_00403ba4(int * param_1, undefined4 * param_2)
 * Address ranges: 00403ba4-00403be6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403ba4(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 != (undefined4 *)0x0) {
    if ((uint)param_2[-2] < 0x80000000) {
      LOCK();
      param_2[-2] = param_2[-2] + 1;
      UNLOCK();
    }
    else {
      puVar3 = FUN_00403c14(param_2[-1]);
      FUN_0040282c(param_2,puVar3,param_2[-1]);
      param_2 = puVar3;
    }
  }
  LOCK();
  iVar2 = *param_1;
  *param_1 = (int)param_2;
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

