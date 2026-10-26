/*
 * FUN_004b3a80 at 004b3a80
 * undefined FUN_004b3a80(void)
 * Address ranges: 004b3a80-004b3a9c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b3a80(void)

{
  int iVar1;
  
  if (DAT_006ab7ac < DAT_006ab7a8) {
    iVar1 = DAT_006ab7ac;
    DAT_006ab7ac = DAT_006ab7ac + 1;
    return iVar1;
  }
  return -1;
}

