/*
 * FUN_0044681c at 0044681c
 * undefined __register FUN_0044681c(int * param_1, char param_2)
 * Address ranges: 0044681c-0044685a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044681c(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  if (piVar1 == DAT_0047b9b8) {
    FUN_0043cb14((int *)0x0);
  }
  FUN_00402eac((int *)piVar1[0x48]);
  FUN_0043e920(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

