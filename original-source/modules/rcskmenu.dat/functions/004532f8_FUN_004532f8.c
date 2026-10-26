/*
 * FUN_004532f8 at 004532f8
 * undefined FUN_004532f8(void)
 * Address ranges: 004532f8-0045336e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004532f8(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  uint uVar2;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_004534f4((int)piVar1,0x4403);
  FUN_0040bfec(piVar1 + 0x14);
  uVar2 = 0;
  do {
    FUN_00402eac((int *)piVar1[(uVar2 & 0x7f) + 9]);
    piVar1[(uVar2 & 0x7f) + 9] = 0;
    uVar2 = uVar2 + 1;
  } while ((char)uVar2 != '\a');
  if ((HGDIOBJ)piVar1[0x10] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)piVar1[0x10]);
    piVar1[0x10] = 0;
  }
  FUN_00402eac((int *)piVar1[0x13]);
  FUN_004147c4(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

