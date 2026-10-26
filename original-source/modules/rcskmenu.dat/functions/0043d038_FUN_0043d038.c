/*
 * FUN_0043d038 at 0043d038
 * undefined FUN_0043d038(void)
 * Address ranges: 0043d038-0043d064
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043d038(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[0x10]);
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

