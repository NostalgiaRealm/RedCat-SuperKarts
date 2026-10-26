/*
 * FUN_0040bf00 at 0040bf00
 * undefined FUN_0040bf00(void)
 * Address ranges: 0040bf00-0040bf3d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040bf00(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0040bf7c((int)piVar1);
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  CloseHandle((HANDLE)piVar1[7]);
  DeleteCriticalSection((LPCRITICAL_SECTION)(piVar1 + 1));
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

