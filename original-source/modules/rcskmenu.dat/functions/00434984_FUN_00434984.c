/*
 * FUN_00434984 at 00434984
 * undefined FUN_00434984(void)
 * Address ranges: 00434984-004349b6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00434984(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  if (piVar1[1] != 0) {
    FUN_0043430c(piVar1[1],(int)piVar1);
  }
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

