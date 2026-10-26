/*
 * FUN_00477fd0 at 00477fd0
 * undefined FUN_00477fd0(void)
 * Address ranges: 00477fd0-00477fe9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00477fd0(int *param_1,int param_2)

{
  if (((param_2 != 0) && (param_2 != 1)) && (param_2 != 3)) {
    param_2 = *param_1;
  }
  param_1[1] = param_2;
  return;
}

