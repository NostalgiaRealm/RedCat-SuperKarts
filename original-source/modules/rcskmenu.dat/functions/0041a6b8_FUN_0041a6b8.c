/*
 * FUN_0041a6b8 at 0041a6b8
 * undefined FUN_0041a6b8(void)
 * Address ranges: 0041a6b8-0041a6e0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a6b8(int *param_1,char param_2)

{
  int *piVar1;
  char extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[1]);
  FUN_00402eac((int *)piVar1[2]);
  if ('\0' < extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

