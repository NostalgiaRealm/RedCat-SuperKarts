/*
 * FUN_00454b04 at 00454b04
 * undefined FUN_00454b04(void)
 * Address ranges: 00454b04-00454b28
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00454b04(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d914 = _DAT_0047d914 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

