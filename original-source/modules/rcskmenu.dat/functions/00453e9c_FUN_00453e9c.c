/*
 * FUN_00453e9c at 00453e9c
 * undefined FUN_00453e9c(void)
 * Address ranges: 00453e9c-00453ec0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00453e9c(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d904 = _DAT_0047d904 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

