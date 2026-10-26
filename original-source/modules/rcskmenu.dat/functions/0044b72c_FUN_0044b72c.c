/*
 * FUN_0044b72c at 0044b72c
 * undefined FUN_0044b72c(void)
 * Address ranges: 0044b72c-0044b739
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044b72c(int param_1,char param_2)

{
  if (param_2 != *(char *)(param_1 + 0x38)) {
    *(char *)(param_1 + 0x38) = param_2;
    FUN_0044b6a0(param_1);
  }
  return;
}

