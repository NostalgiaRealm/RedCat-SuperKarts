/*
 * FUN_004c2a38 at 004c2a38
 * undefined FUN_004c2a38(void)
 * Address ranges: 004c2a38-004c2a6f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c2a38(char *param_1,int param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_004c29d2((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}

