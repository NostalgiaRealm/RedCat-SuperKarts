/*
 * FUN_004585bc at 004585bc
 * undefined FUN_004585bc(void)
 * Address ranges: 004585bc-004585e0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004585bc(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0044dc14(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

