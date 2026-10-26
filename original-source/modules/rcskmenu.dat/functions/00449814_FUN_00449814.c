/*
 * FUN_00449814 at 00449814
 * undefined FUN_00449814(void)
 * Address ranges: 00449814-00449841
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00449814(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_004498c0(piVar1,(HWND)0x0);
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

