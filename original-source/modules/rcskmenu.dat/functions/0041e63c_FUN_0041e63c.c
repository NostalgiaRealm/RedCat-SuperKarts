/*
 * FUN_0041e63c at 0041e63c
 * undefined FUN_0041e63c(void)
 * Address ranges: 0041e63c-0041e664
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e63c(int *param_1,char param_2)

{
  int *piVar1;
  char extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0041e834((int)piVar1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(piVar1 + 2));
  if ('\0' < extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

