/*
 * FUN_00453c50 at 00453c50
 * undefined FUN_00453c50(void)
 * Address ranges: 00453c50-00453c87
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00453c50(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[0x4b]);
  piVar1[0x4b] = 0;
  FUN_0044681c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

