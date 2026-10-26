/*
 * FUN_0043e120 at 0043e120
 * undefined __register FUN_0043e120(int * param_1, int param_2)
 * Address ranges: 0043e120-0043e13e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e120(int *param_1,int param_2)

{
  FUN_0040f848((int *)*param_1,param_2);
  if (*(int *)(*param_1 + 8) == 0) {
    FUN_00402eac((int *)*param_1);
    *param_1 = 0;
  }
  return;
}

