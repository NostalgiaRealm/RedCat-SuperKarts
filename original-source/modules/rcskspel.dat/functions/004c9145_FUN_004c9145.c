/*
 * FUN_004c9145 at 004c9145
 * undefined FUN_004c9145(void)
 * Address ranges: 004c9145-004c915f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c9145(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  param_1 = param_1 - (int)param_2;
  iVar1 = 3;
  do {
    *(undefined4 *)(param_1 + (int)param_2) = *param_2;
    param_2 = param_2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

