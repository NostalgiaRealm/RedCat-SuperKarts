/*
 * FUN_00454e18 at 00454e18
 * undefined FUN_00454e18(void)
 * Address ranges: 00454e18-00454e3c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00454e18(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d918 = _DAT_0047d918 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

