/*
 * FUN_004c916c at 004c916c
 * undefined FUN_004c916c(void)
 * Address ranges: 004c916c-004c9186
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004c916c(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*param_1 != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 1;
  } while (iVar1 < 3);
  return 1;
}

