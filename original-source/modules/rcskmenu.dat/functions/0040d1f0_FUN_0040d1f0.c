/*
 * FUN_0040d1f0 at 0040d1f0
 * undefined FUN_0040d1f0(void)
 * Address ranges: 0040d1f0-0040d214
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040d1f0(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d610 = _DAT_0047d610 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

