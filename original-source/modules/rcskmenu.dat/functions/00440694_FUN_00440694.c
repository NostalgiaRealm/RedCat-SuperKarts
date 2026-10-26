/*
 * FUN_00440694 at 00440694
 * undefined __register FUN_00440694(int param_1, int * param_2)
 * Address ranges: 00440694-004406b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440694(int param_1,int *param_2)

{
  *(int *)(param_1 + 0x30) = *param_2;
  *(int *)(param_1 + 0x34) = param_2[1];
  *(int *)(param_1 + 0x38) = param_2[2] - *param_2;
  *(int *)(param_1 + 0x3c) = param_2[3] - param_2[1];
  FUN_0043ed90(param_1);
  return;
}

