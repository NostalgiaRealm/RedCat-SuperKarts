/*
 * FUN_0040f4e4 at 0040f4e4
 * undefined __register FUN_0040f4e4(int * param_1, char param_2)
 * Address ranges: 0040f4e4-0040f503
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f4e4(int *param_1,char param_2)

{
  int *piVar1;
  char extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  (**(code **)(*piVar1 + 8))();
  if ('\0' < extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

