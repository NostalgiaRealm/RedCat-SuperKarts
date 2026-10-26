/*
 * FUN_0040ec04 at 0040ec04
 * undefined __register FUN_0040ec04(int param_1, int param_2, int param_3, int * param_4, int param_5)
 * Address ranges: 0040ec04-0040ec1f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040ec04(int param_1,int param_2,int param_3,int *param_4,int param_5)

{
  *param_4 = param_1;
  param_4[1] = param_2;
  param_4[2] = param_3 + param_1;
  param_4[3] = param_2 + param_5;
  return;
}

