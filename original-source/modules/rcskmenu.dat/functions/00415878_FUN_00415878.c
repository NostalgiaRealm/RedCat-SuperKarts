/*
 * FUN_00415878 at 00415878
 * undefined FUN_00415878(void)
 * Address ranges: 00415878-0041589c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415878(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d654 = _DAT_0047d654 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

