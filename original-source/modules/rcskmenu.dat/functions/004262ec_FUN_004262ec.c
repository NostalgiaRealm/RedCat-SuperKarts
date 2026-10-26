/*
 * FUN_004262ec at 004262ec
 * undefined FUN_004262ec(void)
 * Address ranges: 004262ec-0042631e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004262ec(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  if (piVar1[0x13] != 0) {
    FUN_004266e0(piVar1[0x13],(int)piVar1);
  }
  FUN_00415080(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

