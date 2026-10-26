/*
 * FUN_0042690c at 0042690c
 * undefined FUN_0042690c(void)
 * Address ranges: 0042690c-00426940
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042690c(int *param_1,char param_2)

{
  int *piVar1;
  uint extraout_EDX;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[0x1e]);
  FUN_00402eac((int *)piVar1[0x1f]);
  FUN_004262ec(piVar1,extraout_EDX & 0xfffffffc);
  if ('\0' < (char)extraout_EDX) {
    FUN_004031fc(piVar1);
  }
  return;
}

