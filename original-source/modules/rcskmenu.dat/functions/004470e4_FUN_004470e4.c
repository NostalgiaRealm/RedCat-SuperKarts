/*
 * FUN_004470e4 at 004470e4
 * undefined __register FUN_004470e4(int * param_1, char param_2)
 * Address ranges: 004470e4-00447113
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004470e4(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[0x7c]);
  FUN_004418ac(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

