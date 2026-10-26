/*
 * FUN_004257f4 at 004257f4
 * undefined FUN_004257f4(void)
 * Address ranges: 004257f4-00425816
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004257f4(int *param_1)

{
  int *piVar1;
  
  piVar1 = FUN_004298bc(param_1);
  if (piVar1 != (int *)0x0) {
    piVar1[0x8d] = param_1[0x7f];
  }
  FUN_004408fc((int)param_1);
  return;
}

