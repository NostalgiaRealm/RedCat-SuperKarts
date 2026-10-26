/*
 * FUN_0042c6bc at 0042c6bc
 * undefined __register FUN_0042c6bc(int param_1, int * param_2, undefined4 param_3)
 * Address ranges: 0042c6bc-0042c6dc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042c6bc(int param_1,int *param_2,undefined4 param_3)

{
  *(int **)(param_1 + 0x248) = param_2;
  if (param_2 != (int *)0x0) {
    FUN_00414858((int)param_2,param_1,param_3);
    FUN_00437fb0(param_2,0);
  }
  return;
}

