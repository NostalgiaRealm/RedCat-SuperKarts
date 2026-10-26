/*
 * FUN_0041bb98 at 0041bb98
 * undefined FUN_0041bb98(void)
 * Address ranges: 0041bb98-0041bbc3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041bb98(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0041bbc4(piVar1);
  FUN_004180b4(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

