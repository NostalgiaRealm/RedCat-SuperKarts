/*
 * FUN_004b8db0 at 004b8db0
 * undefined FUN_004b8db0(void)
 * Address ranges: 004b8db0-004b8dcc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b8db0(void)

{
  int iVar1;
  
  if (DAT_006ab920 < DAT_006ab91c) {
    iVar1 = DAT_006ab920;
    DAT_006ab920 = DAT_006ab920 + 1;
    return iVar1;
  }
  return -1;
}

