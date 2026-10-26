/*
 * FUN_004030bc at 004030bc
 * undefined4 __register FUN_004030bc(int param_1, int param_2)
 * Address ranges: 004030ba-004030ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004030bc(int param_1,int param_2)

{
  while( true ) {
    if (param_1 == param_2) {
      return CONCAT31((int3)((uint)param_1 >> 8),1);
    }
    if (*(int **)(param_1 + -0x24) == (int *)0x0) break;
    param_1 = **(int **)(param_1 + -0x24);
  }
  return 0;
}

