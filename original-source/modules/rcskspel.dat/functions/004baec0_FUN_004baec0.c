/*
 * FUN_004baec0 at 004baec0
 * undefined FUN_004baec0(void)
 * Address ranges: 004baec0-004baef1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004baec0(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_006aba24;
  while (((piVar1[-1] != param_1 || (*piVar1 == 0)) &&
         ((piVar1[0x16] != param_1 || (piVar1[0x17] == 0))))) {
    piVar1 = piVar1 + 2;
    if (0x6aba63 < (int)piVar1) {
      return 0;
    }
  }
  return 1;
}

