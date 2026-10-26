/*
 * FUN_0041520c at 0041520c
 * undefined FUN_0041520c(void)
 * Address ranges: 0041520c-00415243
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041520c(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  if ((char)piVar1[4] == '\x01') {
    FUN_00402eac((int *)piVar1[3]);
    piVar1[3] = 0;
  }
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

