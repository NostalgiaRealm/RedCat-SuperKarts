/*
 * FUN_0045fa10 at 0045fa10
 * undefined FUN_0045fa10(void)
 * Address ranges: 0045fa10-0045fa4a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045fa10(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[0x84]);
  FUN_00402eac((int *)piVar1[0x82]);
  FUN_004470e4(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

