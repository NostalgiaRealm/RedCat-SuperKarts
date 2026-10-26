/*
 * FUN_004574e4 at 004574e4
 * undefined FUN_004574e4(void)
 * Address ranges: 004574e4-00457517
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004574e4(int *param_1,char param_2)

{
  int *piVar1;
  char extraout_DL;
  int iVar2;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  iVar2 = 0;
  do {
    FUN_00402eac((int *)piVar1[iVar2 + 1]);
    iVar2 = iVar2 + 1;
  } while (iVar2 != 4);
  FUN_00402eac((int *)piVar1[5]);
  if ('\0' < extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

