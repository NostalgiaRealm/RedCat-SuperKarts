/*
 * FUN_00415ab0 at 00415ab0
 * undefined FUN_00415ab0(void)
 * Address ranges: 00415ab0-00415ad4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415ab0(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d66c = _DAT_0047d66c + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

