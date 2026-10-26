/*
 * FUN_0040fae0 at 0040fae0
 * undefined FUN_0040fae0(void)
 * Address ranges: 0040fae0-0040fb0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040fae0(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0040fb34((int)piVar1,0);
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

