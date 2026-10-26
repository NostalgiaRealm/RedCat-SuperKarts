/*
 * FUN_0041ad24 at 0041ad24
 * undefined FUN_0041ad24(void)
 * Address ranges: 0041ad24-0041ad5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041ad24(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  if ((HENHMETAFILE)piVar1[2] != (HENHMETAFILE)0x0) {
    DeleteEnhMetaFile((HENHMETAFILE)piVar1[2]);
  }
  FUN_00416a28((HGDIOBJ)piVar1[5]);
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

