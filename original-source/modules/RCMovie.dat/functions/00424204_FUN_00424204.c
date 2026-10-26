/*
 * FUN_00424204 at 00424204
 * undefined4 __cdecl FUN_00424204(uint param_1, HANDLE param_2)
 * Address ranges: 00424204-0042427a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00424204(uint param_1,HANDLE param_2)

{
  int iVar1;
  DWORD nStdHandle;
  
  if (param_1 < DAT_0043f920) {
    iVar1 = (param_1 & 0x1f) * 8;
    if (*(int *)((&DAT_0043f820)[(int)param_1 >> 5] + iVar1) == -1) {
      if (DAT_004370e4 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_0042425a;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_0042425a:
      *(HANDLE *)((&DAT_0043f820)[(int)param_1 >> 5] + iVar1) = param_2;
      return 0;
    }
  }
  DAT_0043e2c4 = 0;
  _DAT_0043e2c0 = 9;
  return 0xffffffff;
}

