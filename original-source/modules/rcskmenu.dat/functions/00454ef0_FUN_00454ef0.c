/*
 * FUN_00454ef0 at 00454ef0
 * undefined FUN_00454ef0(void)
 * Address ranges: 00454ef0-00454f1c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454ef0(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[1]);
  FUN_0044dc14(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

