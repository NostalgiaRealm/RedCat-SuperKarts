/*
 * FUN_004112dc at 004112dc
 * undefined FUN_004112dc(void)
 * Address ranges: 004112dc-00411335
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004112dc(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  piVar1[8] = 0;
  piVar1[9] = 0;
  piVar1[10] = 0;
  piVar1[0xb] = 0;
  FUN_0041059c(piVar1,extraout_DL & 0xfc);
  if (piVar1[4] != 0) {
    FUN_004043f8((VARIANTARG *)piVar1[3],"\x0e\vTStringItem\b",piVar1[4]);
  }
  piVar1[4] = 0;
  (**(code **)(*piVar1 + 0x28))(piVar1,0);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

