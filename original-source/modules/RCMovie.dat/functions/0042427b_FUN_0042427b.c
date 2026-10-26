/*
 * FUN_0042427b at 0042427b
 * undefined4 __cdecl FUN_0042427b(uint param_1)
 * Address ranges: 0042427b-004242f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0042427b(uint param_1)

{
  int *piVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_0043f920) {
    iVar2 = (param_1 & 0x1f) * 8;
    piVar1 = (int *)((&DAT_0043f820)[(int)param_1 >> 5] + iVar2);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_004370e4 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_004242d4;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_004242d4:
      *(undefined4 *)((&DAT_0043f820)[(int)param_1 >> 5] + iVar2) = 0xffffffff;
      return 0;
    }
  }
  DAT_0043e2c4 = 0;
  _DAT_0043e2c0 = 9;
  return 0xffffffff;
}

