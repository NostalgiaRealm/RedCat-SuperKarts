/*
 * FUN_0044127c at 0044127c
 * undefined FUN_0044127c(void)
 * Address ranges: 0044127c-0044129b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0044127c(int param_1)

{
  char cVar1;
  
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))();
    if (cVar1 != '\0') {
      return 0;
    }
  }
  return 1;
}

