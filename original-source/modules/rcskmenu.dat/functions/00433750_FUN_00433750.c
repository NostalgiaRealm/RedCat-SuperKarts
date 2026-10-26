/*
 * FUN_00433750 at 00433750
 * undefined FUN_00433750(void)
 * Address ranges: 00433750-004337b9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00433750(int *param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  while (0 < (int)((undefined4 *)piVar1[0x10])[2]) {
    iVar2 = FUN_0040f798((undefined4 *)piVar1[0x10]);
    FUN_0043430c((int)piVar1,iVar2);
  }
  FUN_00402eac((int *)piVar1[0x11]);
  FUN_00433a14(piVar1);
  FUN_00402eac((int *)piVar1[0x10]);
  piVar1[0x10] = 0;
  if ((int *)piVar1[0x12] != (int *)0x0) {
    FUN_00402eac((int *)piVar1[0x12]);
  }
  FUN_004147c4(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

