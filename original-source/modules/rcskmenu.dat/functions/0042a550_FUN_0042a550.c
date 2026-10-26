/*
 * FUN_0042a550 at 0042a550
 * undefined __register FUN_0042a550(int * param_1, char param_2)
 * Address ranges: 0042a550-0042a58a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042a550(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[0x7c]);
  FUN_00402eac((int *)piVar1[0x7d]);
  FUN_004418ac(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

