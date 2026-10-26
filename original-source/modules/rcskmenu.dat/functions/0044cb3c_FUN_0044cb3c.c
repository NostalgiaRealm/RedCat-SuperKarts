/*
 * FUN_0044cb3c at 0044cb3c
 * undefined FUN_0044cb3c(void)
 * Address ranges: 0044cb3c-0044cb67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044cb3c(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0044cc10((int)piVar1);
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

