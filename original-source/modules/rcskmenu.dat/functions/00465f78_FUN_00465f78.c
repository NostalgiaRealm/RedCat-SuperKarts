/*
 * FUN_00465f78 at 00465f78
 * undefined __register FUN_00465f78(int * param_1, char param_2)
 * Address ranges: 00465f78-00465fc8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00465f78(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0040bfec(piVar1 + 0x7c);
  FUN_0040bfec(piVar1 + 0x84);
  FUN_0040bfec(piVar1 + 0x82);
  FUN_0040bfec(piVar1 + 0x7e);
  FUN_004418ac(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

