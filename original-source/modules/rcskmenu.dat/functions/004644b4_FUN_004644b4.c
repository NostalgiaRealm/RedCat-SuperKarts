/*
 * FUN_004644b4 at 004644b4
 * undefined FUN_004644b4(void)
 * Address ranges: 004644b4-004644d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004644b4(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e1e8 = _DAT_0047e1e8 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

