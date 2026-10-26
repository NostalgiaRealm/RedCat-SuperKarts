/*
 * FUN_0040fe84 at 0040fe84
 * undefined __register FUN_0040fe84(int * param_1, char param_2)
 * Address ranges: 0040fe84-0040feb1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040fe84(int *param_1,char param_2)

{
  int *piVar1;
  undefined4 extraout_ECX;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0040ffd0(piVar1,(int *)0x0,extraout_ECX);
  FUN_0040fc7c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

