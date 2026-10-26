/*
 * FUN_00411b70 at 00411b70
 * undefined FUN_00411b70(void)
 * Address ranges: 00411b70-00411b94
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411b70(int *param_1,char param_2)

{
  int *piVar1;
  char extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  if (-1 < piVar1[1]) {
    FUN_004080ac((HANDLE)piVar1[1]);
  }
  if ('\0' < extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

