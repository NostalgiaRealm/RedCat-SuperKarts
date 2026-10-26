/*
 * FUN_004614b0 at 004614b0
 * undefined FUN_004614b0(void)
 * Address ranges: 004614b0-004614ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004614b0(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_004612e0(param_1);
  if (piVar1 == (int *)0x0) {
    return;
  }
  (**(code **)(*piVar1 + 0x1c))();
  return;
}

