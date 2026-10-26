/*
 * FUN_00460f14 at 00460f14
 * undefined FUN_00460f14(void)
 * Address ranges: 00460f14-00460f38
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00460f14(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e1b8 = _DAT_0047e1b8 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

