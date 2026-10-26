/*
 * FUN_004570c8 at 004570c8
 * undefined FUN_004570c8(void)
 * Address ranges: 004570c8-004570ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004570c8(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e164 = _DAT_0047e164 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

