/*
 * FUN_0045d464 at 0045d464
 * undefined __register FUN_0045d464(int * param_1, char param_2)
 * Address ranges: 0045d464-0045d488
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045d464(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0042b17c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

