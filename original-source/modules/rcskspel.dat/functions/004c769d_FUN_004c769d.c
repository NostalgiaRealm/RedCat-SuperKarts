/*
 * FUN_004c769d at 004c769d
 * undefined FUN_004c769d(void)
 * Address ranges: 004c769d-004c76df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004c769d(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_00503448;
  if (DAT_00503448 != param_1) {
    do {
      piVar1 = piVar1 + 3;
      if (&DAT_00503448 + DAT_005034c8 * 3 <= piVar1) break;
    } while (*piVar1 != param_1);
  }
  if ((&DAT_00503448 + DAT_005034c8 * 3 <= piVar1) || (*piVar1 != param_1)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}

