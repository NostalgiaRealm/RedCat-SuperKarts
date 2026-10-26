/*
 * FUN_00411730 at 00411730
 * undefined FUN_00411730(void)
 * Address ranges: 00411730-004117f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00411730(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  char cVar2;
  
  if (param_3 == 0) {
    iVar1 = *(int *)(param_2 * 0x50 + 0x18 + DAT_00680ae0);
    if (iVar1 != -1) {
      cVar2 = FUN_004116d0(param_1,iVar1,param_4,param_5);
      if (cVar2 == '\x01') {
        return iVar1;
      }
    }
  }
  else if (param_3 == 1) {
    iVar1 = *(int *)(param_2 * 0x50 + 0x14 + DAT_00680ae0);
    if (iVar1 != -1) {
      cVar2 = FUN_004115a0(param_1,iVar1,param_5);
      if (cVar2 == '\x01') {
        return iVar1;
      }
    }
  }
  else if ((param_3 == 2) && (iVar1 = *(int *)(param_2 * 0x50 + 0x1c + DAT_00680ae0), iVar1 != -1))
  {
    cVar2 = FUN_004116d0(param_1,iVar1,param_4,param_5);
    if (cVar2 == '\x01') {
      return iVar1;
    }
  }
  return -1;
}

