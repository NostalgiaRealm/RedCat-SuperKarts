/*
 * FUN_00478390 at 00478390
 * undefined FUN_00478390(void)
 * Address ranges: 00478390-004783b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00478390(int *param_1,char param_2)

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

