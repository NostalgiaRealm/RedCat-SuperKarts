/*
 * FUN_00410070 at 00410070
 * undefined FUN_00410070(void)
 * Address ranges: 00410070-004100b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410070(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  piVar1[3] = 1;
  if (piVar1[2] != 0) {
    FUN_0041016c(piVar1);
  }
  FUN_00402eac((int *)piVar1[2]);
  FUN_0040fc7c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

