/*
 * FUN_004544dc at 004544dc
 * undefined FUN_004544dc(void)
 * Address ranges: 004544dc-00454500
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004544dc(int *param_1,char param_2)

{
  int *piVar1;
  char extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  if ((int *)piVar1[1] != (int *)0x0) {
    FUN_00402eac((int *)piVar1[1]);
  }
  if ('\0' < extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

