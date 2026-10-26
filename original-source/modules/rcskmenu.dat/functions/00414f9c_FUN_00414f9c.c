/*
 * FUN_00414f9c at 00414f9c
 * undefined FUN_00414f9c(void)
 * Address ranges: 00414f9c-00414fce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414f9c(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  if (piVar1[4] != 0) {
    FUN_00415184(piVar1[4],(int)piVar1);
  }
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

