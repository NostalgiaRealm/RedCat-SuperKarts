/*
 * FUN_004300a4 at 004300a4
 * undefined FUN_004300a4(void)
 * Address ranges: 004300a4-00430148
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004300a4(int *param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  byte extraout_DL;
  int iVar3;
  int iVar4;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[0x1d]);
  FUN_00402eac((int *)piVar1[0x1f]);
  FUN_00402eac((int *)piVar1[0x1e]);
  FUN_00402eac((int *)piVar1[0x12]);
  FUN_00402eac((int *)piVar1[0x11]);
  FUN_00402eac((int *)piVar1[0x10]);
  FUN_00402eac((int *)piVar1[9]);
  FUN_00402eac((int *)piVar1[10]);
  FUN_00402eac((int *)piVar1[0x1c]);
  if ((piVar1[0x13] != 0) && (iVar3 = *(int *)(piVar1[0x13] + 8), -1 < iVar3 + -1)) {
    iVar4 = 0;
    do {
      piVar2 = (int *)FUN_0040f6b0((undefined4 *)piVar1[0x13],iVar4);
      FUN_00402eac(piVar2);
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  FUN_00402eac((int *)piVar1[0x13]);
  FUN_0043033c((int)piVar1);
  FUN_004147c4(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

