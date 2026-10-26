/*
 * FUN_00426570 at 00426570
 * undefined FUN_00426570(void)
 * Address ranges: 00426570-004265bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426570(int *param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[10]);
  while (0 < (int)((undefined4 *)piVar1[9])[2]) {
    piVar2 = (int *)FUN_0040f798((undefined4 *)piVar1[9]);
    FUN_00402eac(piVar2);
  }
  FUN_00402eac((int *)piVar1[9]);
  FUN_004147c4(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

