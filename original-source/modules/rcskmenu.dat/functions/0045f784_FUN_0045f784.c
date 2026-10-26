/*
 * FUN_0045f784 at 0045f784
 * undefined FUN_0045f784(void)
 * Address ranges: 0045f784-0045f7a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045f784(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0045dfa8(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

