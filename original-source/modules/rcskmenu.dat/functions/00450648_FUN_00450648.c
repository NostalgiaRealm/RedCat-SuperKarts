/*
 * FUN_00450648 at 00450648
 * undefined FUN_00450648(void)
 * Address ranges: 00450648-00450674
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00450648(int *param_1,char param_2)

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

