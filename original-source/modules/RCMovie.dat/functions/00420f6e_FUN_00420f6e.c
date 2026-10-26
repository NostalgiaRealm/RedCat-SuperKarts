/*
 * FUN_00420f6e at 00420f6e
 * int * __cdecl FUN_00420f6e(int param_1)
 * Address ranges: 00420f6e-00420fb0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __cdecl FUN_00420f6e(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_00437130;
  if (DAT_00437130 != param_1) {
    do {
      piVar1 = piVar1 + 3;
      if (&DAT_00437130 + DAT_004371b0 * 3 <= piVar1) break;
    } while (*piVar1 != param_1);
  }
  if ((&DAT_00437130 + DAT_004371b0 * 3 <= piVar1) || (*piVar1 != param_1)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}

