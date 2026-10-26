/*
 * FUN_00493a40 at 00493a40
 * undefined FUN_00493a40(void)
 * Address ranges: 00493a40-00493a6c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00493a40(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1 - param_2 >> 0x1f;
  iVar1 = (param_1 - param_2 ^ uVar2) - uVar2;
  if (DAT_00680b2c / 2 < iVar1) {
    return DAT_00680b2c - iVar1;
  }
  return iVar1;
}

