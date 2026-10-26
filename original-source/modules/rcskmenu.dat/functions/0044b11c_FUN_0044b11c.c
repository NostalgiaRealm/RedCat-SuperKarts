/*
 * FUN_0044b11c at 0044b11c
 * undefined FUN_0044b11c(void)
 * Address ranges: 0044b11c-0044b14b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044b11c(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[0x4a]);
  FUN_0044681c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

