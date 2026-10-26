/*
 * FUN_004616a4 at 004616a4
 * undefined FUN_004616a4(void)
 * Address ranges: 004616a4-004616c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004616a4(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0045d464(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

