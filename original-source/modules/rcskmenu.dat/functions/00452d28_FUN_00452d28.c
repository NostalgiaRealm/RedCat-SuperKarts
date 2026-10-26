/*
 * FUN_00452d28 at 00452d28
 * undefined FUN_00452d28(void)
 * Address ranges: 00452d28-00452d4c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00452d28(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d8fc = _DAT_0047d8fc + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

