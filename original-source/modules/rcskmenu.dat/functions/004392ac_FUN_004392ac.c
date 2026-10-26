/*
 * FUN_004392ac at 004392ac
 * undefined __register FUN_004392ac(int * param_1, char param_2)
 * Address ranges: 004392ac-004392e0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004392ac(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[10]);
  FUN_00402eac((int *)piVar1[0xe]);
  FUN_004147c4(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

