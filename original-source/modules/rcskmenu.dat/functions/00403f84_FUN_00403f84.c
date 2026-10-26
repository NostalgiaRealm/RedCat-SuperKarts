/*
 * FUN_00403f84 at 00403f84
 * undefined __register FUN_00403f84(int param_1)
 * Address ranges: 00403f84-00403f92
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403f84(int param_1)

{
  if ((param_1 != 0) && (-1 < *(int *)(param_1 + -8))) {
    LOCK();
    *(int *)(param_1 + -8) = *(int *)(param_1 + -8) + 1;
    UNLOCK();
  }
  return;
}

