/*
 * FUN_0048e740 at 0048e740
 * undefined FUN_0048e740(void)
 * Address ranges: 0048e740-0048e777
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __thiscall FUN_0048e740(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = param_1;
  if (0 < param_1[0xe0]) {
    do {
      if (*piVar2 == param_2) {
        return param_1 + iVar1 * 7;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 7;
    } while (iVar1 < param_1[0xe0]);
  }
  return (int *)0x0;
}

