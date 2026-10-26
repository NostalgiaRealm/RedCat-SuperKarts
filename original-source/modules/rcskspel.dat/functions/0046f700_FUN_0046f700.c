/*
 * FUN_0046f700 at 0046f700
 * undefined FUN_0046f700(void)
 * Address ranges: 0046f700-0046f76e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046f700(int param_1,int *param_2,int *param_3,int *param_4)

{
  *param_2 = param_1 / 60000;
  *param_3 = (param_1 % 60000) / 1000;
  *param_4 = ((param_1 % 60000) % 1000) / 10;
  return;
}

