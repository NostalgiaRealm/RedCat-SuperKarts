/*
 * FUN_00415080 at 00415080
 * undefined __register FUN_00415080(int * param_1, char param_2)
 * Address ranges: 00415080-004150c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00415080(int *param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_004147c4(piVar1,extraout_DL & 0xfc);
  while (0 < (int)((undefined4 *)piVar1[0x10])[2]) {
    iVar2 = FUN_0040f798((undefined4 *)piVar1[0x10]);
    FUN_00415184((int)piVar1,iVar2);
  }
  FUN_00402eac((int *)piVar1[0x10]);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

