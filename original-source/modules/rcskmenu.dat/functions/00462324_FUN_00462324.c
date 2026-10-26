/*
 * FUN_00462324 at 00462324
 * undefined FUN_00462324(void)
 * Address ranges: 00462324-00462348
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00462324(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e1e0 = _DAT_0047e1e0 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

