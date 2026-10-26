/*
 * FUN_00415b58 at 00415b58
 * undefined FUN_00415b58(void)
 * Address ranges: 00415b58-00415b7c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415b58(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d678 = _DAT_0047d678 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

