/*
 * FUN_00455144 at 00455144
 * undefined __register FUN_00455144(int * param_1, char param_2)
 * Address ranges: 00455144-00455195
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00455144(int *param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  while (0 < (int)((undefined4 *)piVar1[1])[2]) {
    piVar2 = (int *)FUN_0040f6b0((undefined4 *)piVar1[1],0);
    FUN_00402eac(piVar2);
    FUN_0040f550((int *)piVar1[1],0);
  }
  FUN_00402eac((int *)piVar1[1]);
  FUN_0044dc14(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

