/*
 * FUN_00411bfc at 00411bfc
 * undefined __register FUN_00411bfc(int * param_1, char param_2)
 * Address ranges: 00411bfc-00411c27
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411bfc(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00411c28(piVar1);
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

