/*
 * FUN_00456230 at 00456230
 * undefined FUN_00456230(void)
 * Address ranges: 00456230-00456254
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00456230(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d94c = _DAT_0047d94c + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

