/*
 * FUN_004028f0 at 004028f0
 * undefined FUN_004028f0(void)
 * Address ranges: 004028f0-00402917
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004028f0(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_00503ef0;
  while ((piVar1[4] != param_1 || (*piVar1 == -1))) {
    piVar1 = piVar1 + 0x47;
    if (0x504f93 < (int)piVar1) {
      return 0;
    }
  }
  return 1;
}

