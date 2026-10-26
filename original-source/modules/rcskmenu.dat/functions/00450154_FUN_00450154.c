/*
 * FUN_00450154 at 00450154
 * undefined FUN_00450154(void)
 * Address ranges: 00450154-00450178
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00450154(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d8ec = _DAT_0047d8ec + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

