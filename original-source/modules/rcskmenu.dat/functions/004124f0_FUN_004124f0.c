/*
 * FUN_004124f0 at 004124f0
 * undefined FUN_004124f0(void)
 * Address ranges: 004124f0-00412528
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004124f0(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  (**(code **)(*(int *)piVar1[1] + 0xc))((int *)piVar1[1],piVar1[4] - piVar1[5],1);
  FUN_00411f34(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

