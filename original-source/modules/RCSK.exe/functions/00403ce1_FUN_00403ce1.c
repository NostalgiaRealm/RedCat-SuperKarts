/*
 * FUN_00403ce1 at 00403ce1
 * int * __cdecl FUN_00403ce1(int param_1)
 * Address ranges: 00403ce1-00403d23
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __cdecl FUN_00403ce1(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_004083c8;
  if (DAT_004083c8 != param_1) {
    do {
      piVar1 = piVar1 + 3;
      if (&DAT_004083c8 + DAT_00408448 * 3 <= piVar1) break;
    } while (*piVar1 != param_1);
  }
  if ((&DAT_004083c8 + DAT_00408448 * 3 <= piVar1) || (*piVar1 != param_1)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}

