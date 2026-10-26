/*
 * FUN_0043e2d8 at 0043e2d8
 * undefined FUN_0043e2d8(void)
 * Address ranges: 0043e2d8-0043e303
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e2d8(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0043e3ac(piVar1);
  FUN_004180b4(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

