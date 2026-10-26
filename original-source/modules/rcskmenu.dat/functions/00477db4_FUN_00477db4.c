/*
 * FUN_00477db4 at 00477db4
 * undefined FUN_00477db4(void)
 * Address ranges: 00477db4-00477dd8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477db4(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e560 = _DAT_0047e560 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

