/*
 * FUN_0040fc7c at 0040fc7c
 * undefined __register FUN_0040fc7c(int * param_1, char param_2)
 * Address ranges: 0040fc7c-0040fca7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040fc7c(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00412424((int)piVar1);
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

