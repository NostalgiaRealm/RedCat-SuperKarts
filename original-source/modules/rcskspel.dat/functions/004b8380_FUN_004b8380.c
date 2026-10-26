/*
 * FUN_004b8380 at 004b8380
 * undefined FUN_004b8380(void)
 * Address ranges: 004b8380-004b83ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b8380(void)

{
  int iVar1;
  
  if (DAT_006ab88c == 0) {
    return 0;
  }
  iVar1 = 0;
  if (0 < DAT_00501110) {
    do {
      FUN_004b7d60(iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_00501110);
  }
  return 0;
}

