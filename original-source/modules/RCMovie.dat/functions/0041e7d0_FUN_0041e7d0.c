/*
 * FUN_0041e7d0 at 0041e7d0
 * int __stdcall FUN_0041e7d0(void)
 * Address ranges: 0041e7d0-0041e7f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0041e7d0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_0043e214;
  while ((piVar2[-1] != 0 || (*piVar2 != 0))) {
    piVar2 = piVar2 + 2;
    iVar1 = iVar1 + 1;
    if (0x43e2b3 < (int)piVar2) {
      return -1;
    }
  }
  return iVar1;
}

