/*
 * FUN_004477f8 at 004477f8
 * undefined FUN_004477f8(void)
 * Address ranges: 004477f8-00447843
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004477f8(int *param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 extraout_ECX;
  byte extraout_DL;
  
  piVar2 = FUN_0040320c(param_1,param_2);
  if (piVar2[0xc] != 0) {
    iVar1 = piVar2[5];
    *(int *)(iVar1 + 0x28) = piVar2[0xc];
    *(int *)(iVar1 + 0x2c) = piVar2[0xd];
  }
  FUN_0044881c((int)piVar2,(int *)piVar2[0x19],extraout_ECX);
  FUN_00402eac((int *)piVar2[4]);
  FUN_00402e9c(piVar2,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar2);
  }
  return;
}

