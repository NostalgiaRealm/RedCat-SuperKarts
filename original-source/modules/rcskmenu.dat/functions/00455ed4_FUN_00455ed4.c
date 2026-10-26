/*
 * FUN_00455ed4 at 00455ed4
 * undefined FUN_00455ed4(void)
 * Address ranges: 00455ed4-00455eff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00455ed4(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00455fb8((int)piVar1);
  FUN_004147c4(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

