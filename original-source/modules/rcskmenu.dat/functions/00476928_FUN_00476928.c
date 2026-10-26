/*
 * FUN_00476928 at 00476928
 * undefined FUN_00476928(void)
 * Address ranges: 00476928-0047695b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00476928(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  if ((int *)piVar1[0xe0] != (int *)0x0) {
    FUN_00402eac((int *)piVar1[0xe0]);
  }
  FUN_0045d464(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

