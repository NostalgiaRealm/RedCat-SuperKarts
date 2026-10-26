/*
 * FUN_004c0b6a at 004c0b6a
 * undefined FUN_004c0b6a(void)
 * Address ranges: 004c0b6a-004c0be3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c0b6a(uint param_1)

{
  int *piVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_006b6b60) {
    iVar2 = (param_1 & 0x1f) * 8;
    piVar1 = (int *)((&DAT_006b6a60)[(int)param_1 >> 5] + iVar2);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_00502ae4 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_004c0bc3;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_004c0bc3:
      *(undefined4 *)((&DAT_006b6a60)[(int)param_1 >> 5] + iVar2) = 0xffffffff;
      return 0;
    }
  }
  DAT_006b66ec = 0;
  _DAT_006b66e8 = 9;
  return 0xffffffff;
}

