/*
 * FUN_0043a648 at 0043a648
 * undefined FUN_0043a648(void)
 * Address ranges: 0043a648-0043a678
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043a648(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0043a5b8(DAT_0047d798,(int)piVar1);
  FUN_004392ac(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

