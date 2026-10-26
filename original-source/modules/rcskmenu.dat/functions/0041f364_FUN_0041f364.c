/*
 * FUN_0041f364 at 0041f364
 * undefined FUN_0041f364(void)
 * Address ranges: 0041f364-0041f390
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041f364(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[1]);
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

