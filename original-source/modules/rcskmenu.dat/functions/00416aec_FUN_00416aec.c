/*
 * FUN_00416aec at 00416aec
 * undefined FUN_00416aec(void)
 * Address ranges: 00416aec-00416b0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00416aec(int *param_1,char param_2)

{
  int *piVar1;
  char extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  DeleteCriticalSection((LPCRITICAL_SECTION)(piVar1 + 2));
  if ('\0' < extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

