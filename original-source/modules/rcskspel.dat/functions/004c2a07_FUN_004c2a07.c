/*
 * FUN_004c2a07 at 004c2a07
 * undefined FUN_004c2a07(void)
 * Address ranges: 004c2a07-004c2a37
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c2a07(undefined4 param_1,int param_2,undefined4 param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_004c29d2(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}

