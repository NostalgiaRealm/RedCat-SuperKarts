/*
 * FUN_00424648 at 00424648
 * undefined FUN_00424648(void)
 * Address ranges: 00424648-004246b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424648(int *param_1,char param_2)

{
  bool bVar1;
  int *piVar2;
  byte extraout_DL;
  
  piVar2 = FUN_0040320c(param_1,param_2);
  bVar1 = FUN_00445a20((int)piVar2);
  if (bVar1) {
    (**(code **)(*piVar2 + 0x9c))();
  }
  FUN_00429670(piVar2[0x85]);
  FUN_00429670(piVar2[0x84]);
  FUN_00402eac((int *)piVar2[0x7d]);
  FUN_00402eac((int *)piVar2[0x7c]);
  FUN_00402eac((int *)piVar2[0x89]);
  FUN_004418ac(piVar2,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar2);
  }
  return;
}

