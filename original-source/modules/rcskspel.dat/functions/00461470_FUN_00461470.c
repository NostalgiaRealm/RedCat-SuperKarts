/*
 * FUN_00461470 at 00461470
 * undefined FUN_00461470(void)
 * Address ranges: 00461470-0046148a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00461470(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_004612e0(param_1);
  if (piVar1 == (int *)0x0) {
    return;
  }
  (**(code **)(*piVar1 + 0x14))();
  return;
}

