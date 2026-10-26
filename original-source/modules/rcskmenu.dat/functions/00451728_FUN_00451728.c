/*
 * FUN_00451728 at 00451728
 * undefined FUN_00451728(void)
 * Address ranges: 00451728-00451762
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00451728(int *param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  piVar2 = FUN_004516b8(piVar1,extraout_EDX,extraout_ECX);
  FUN_004524e4((int)piVar1,(int)piVar2);
  FUN_00402eac((int *)piVar1[8]);
  FUN_0040fc7c(piVar1,(byte)extraout_EDX & 0xfc);
  if ('\0' < (char)(byte)extraout_EDX) {
    FUN_004031fc(piVar1);
  }
  return;
}

