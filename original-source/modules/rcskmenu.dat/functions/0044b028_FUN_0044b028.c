/*
 * FUN_0044b028 at 0044b028
 * undefined __register FUN_0044b028(int param_1, LPRECT param_2, undefined4 param_3, int param_4)
 * Address ranges: 0044b028-0044b086
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044b028(int param_1,LPRECT param_2,undefined4 param_3,int param_4)

{
  FUN_00417cc8(*(int **)(param_1 + 0x10),1);
  param_2->bottom = param_2->bottom + -1;
  param_2->right = param_2->right + -1;
  for (; 0 < param_4; param_4 = param_4 + -1) {
    FUN_0044af64();
    InflateRect(param_2,-1,-1);
  }
  param_2->bottom = param_2->bottom + 1;
  param_2->right = param_2->right + 1;
  return;
}

