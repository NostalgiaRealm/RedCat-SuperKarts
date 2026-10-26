/*
 * FUN_0044b5f4 at 0044b5f4
 * undefined FUN_0044b5f4(void)
 * Address ranges: 0044b5f4-0044b62b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044b5f4(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  *(undefined1 *)(piVar1 + 0xe) = 0;
  FUN_0044b6a0((int)piVar1);
  FUN_00429748((HWND)piVar1[10]);
  FUN_004147c4(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

