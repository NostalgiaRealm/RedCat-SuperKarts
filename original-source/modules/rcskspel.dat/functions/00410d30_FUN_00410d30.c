/*
 * FUN_00410d30 at 00410d30
 * undefined FUN_00410d30(void)
 * Address ranges: 00410d30-00410d50
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00410d30(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_00505a30;
  do {
    if (*piVar2 < 0) break;
    piVar2 = piVar2 + 6;
    iVar1 = iVar1 + 1;
  } while ((int)piVar2 < 0x505af0);
  if (iVar1 == 8) {
    iVar1 = -1;
  }
  return iVar1;
}

