/*
 * FUN_00454d20 at 00454d20
 * undefined FUN_00454d20(void)
 * Address ranges: 00454d20-00454d5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454d20(int *param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  char extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  while (0 < (int)((undefined4 *)piVar1[2])[2]) {
    piVar2 = (int *)FUN_0040f6b0((undefined4 *)piVar1[2],0);
    FUN_00402eac(piVar2);
    FUN_0040f550((int *)piVar1[2],0);
  }
  if ('\0' < extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

