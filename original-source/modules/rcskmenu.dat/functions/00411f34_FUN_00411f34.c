/*
 * FUN_00411f34 at 00411f34
 * undefined __register FUN_00411f34(int * param_1, char param_2)
 * Address ranges: 00411f34-00411f5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411f34(int *param_1,char param_2)

{
  int *piVar1;
  char extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  if (piVar1[2] != 0) {
    FUN_0040272c(piVar1[2]);
  }
  if ('\0' < extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

