/*
 * FUN_0046c414 at 0046c414
 * undefined FUN_0046c414(void)
 * Address ranges: 0046c414-0046c460
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046c414(int *param_1,char param_2,undefined4 param_3)

{
  int *piVar1;
  byte extraout_DL;
  undefined4 uStack_c;
  
  uStack_c = param_3;
  piVar1 = FUN_0040320c(param_1,param_2);
  if (*(ushort *)((int)piVar1 + 0x2da) != 0) {
    mciSendCommandA((uint)*(ushort *)((int)piVar1 + 0x2da),0x804,2,(DWORD_PTR)&uStack_c);
  }
  FUN_0046c5f8((int)piVar1);
  FUN_004470e4(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

