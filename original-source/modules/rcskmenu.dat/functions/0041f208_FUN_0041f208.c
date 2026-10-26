/*
 * FUN_0041f208 at 0041f208
 * undefined FUN_0041f208(void)
 * Address ranges: 0041f208-0041f22c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041f208(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d6fc = _DAT_0047d6fc + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

