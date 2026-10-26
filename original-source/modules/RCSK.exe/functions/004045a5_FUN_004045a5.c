/*
 * FUN_004045a5 at 004045a5
 * undefined4 __cdecl FUN_004045a5(uint param_1, HANDLE param_2)
 * Address ranges: 004045a5-0040461b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004045a5(uint param_1,HANDLE param_2)

{
  int iVar1;
  DWORD nStdHandle;
  
  if (param_1 < DAT_0040a120) {
    iVar1 = (param_1 & 0x1f) * 8;
    if (*(int *)((&DAT_0040a020)[(int)param_1 >> 5] + iVar1) == -1) {
      if (DAT_00408244 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_004045fb;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_004045fb:
      *(HANDLE *)((&DAT_0040a020)[(int)param_1 >> 5] + iVar1) = param_2;
      return 0;
    }
  }
  DAT_00408c08 = 0;
  DAT_00408c04 = 9;
  return 0xffffffff;
}

