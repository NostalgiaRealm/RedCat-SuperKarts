/*
 * FUN_004453f4 at 004453f4
 * undefined __register FUN_004453f4(int param_1)
 * Address ranges: 004453f4-00445409
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004453f4(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x24);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xac))(piVar1,param_1);
  }
  return;
}

