/*
 * FUN_004028c0 at 004028c0
 * undefined FUN_004028c0(void)
 * Address ranges: 004028c0-004028e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004028c0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_00503ef0;
  do {
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 0x47;
    iVar1 = iVar1 + 1;
  } while ((int)piVar2 < 0x504f94);
  if (iVar1 == 0xf) {
    iVar1 = -1;
  }
  return iVar1;
}

