/*
 * FUN_0041059c at 0041059c
 * undefined __register FUN_0041059c(int * param_1, char param_2)
 * Address ranges: 0041059c-004105c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041059c(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0041106c((int)piVar1,(int *)0x0);
  FUN_0040fc7c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

