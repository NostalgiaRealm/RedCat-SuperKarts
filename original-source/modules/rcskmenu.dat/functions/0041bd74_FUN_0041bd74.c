/*
 * FUN_0041bd74 at 0041bd74
 * undefined FUN_0041bd74(void)
 * Address ranges: 0041bd74-0041bdcd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041bd74(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  if (piVar1[5] != 0) {
    FUN_0041bae0(piVar1[5]);
    DeleteObject((HGDIOBJ)piVar1[5]);
    piVar1[5] = 0;
  }
  (**(code **)*piVar1)();
  if ((HANDLE)piVar1[0x19] != (HANDLE)0x0) {
    CloseHandle((HANDLE)piVar1[0x19]);
  }
  FUN_0040bfec(piVar1 + 0x1b);
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

