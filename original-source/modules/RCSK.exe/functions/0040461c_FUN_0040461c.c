/*
 * FUN_0040461c at 0040461c
 * undefined4 __cdecl FUN_0040461c(uint param_1)
 * Address ranges: 0040461c-00404695
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040461c(uint param_1)

{
  int *piVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_0040a120) {
    iVar2 = (param_1 & 0x1f) * 8;
    piVar1 = (int *)((&DAT_0040a020)[(int)param_1 >> 5] + iVar2);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_00408244 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_00404675;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_00404675:
      *(undefined4 *)((&DAT_0040a020)[(int)param_1 >> 5] + iVar2) = 0xffffffff;
      return 0;
    }
  }
  DAT_00408c08 = 0;
  DAT_00408c04 = 9;
  return 0xffffffff;
}

