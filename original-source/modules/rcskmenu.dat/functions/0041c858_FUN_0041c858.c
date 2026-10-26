/*
 * FUN_0041c858 at 0041c858
 * undefined FUN_0041c858(void)
 * Address ranges: 0041c858-0041c893
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041c858(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0041cf04((int)piVar1);
  FUN_0041bd54((int *)piVar1[8]);
  FUN_00402eac((int *)piVar1[9]);
  FUN_0040fc7c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

