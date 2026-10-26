/*
 * FUN_00415a78 at 00415a78
 * undefined FUN_00415a78(void)
 * Address ranges: 00415a78-00415a9c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415a78(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d668 = _DAT_0047d668 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

