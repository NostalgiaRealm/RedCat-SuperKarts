/*
 * FUN_004c0af3 at 004c0af3
 * undefined FUN_004c0af3(void)
 * Address ranges: 004c0af3-004c0b69
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c0af3(uint param_1,HANDLE param_2)

{
  int iVar1;
  DWORD nStdHandle;
  
  if (param_1 < DAT_006b6b60) {
    iVar1 = (param_1 & 0x1f) * 8;
    if (*(int *)((&DAT_006b6a60)[(int)param_1 >> 5] + iVar1) == -1) {
      if (DAT_00502ae4 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_004c0b49;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_004c0b49:
      *(HANDLE *)((&DAT_006b6a60)[(int)param_1 >> 5] + iVar1) = param_2;
      return 0;
    }
  }
  DAT_006b66ec = 0;
  _DAT_006b66e8 = 9;
  return 0xffffffff;
}

