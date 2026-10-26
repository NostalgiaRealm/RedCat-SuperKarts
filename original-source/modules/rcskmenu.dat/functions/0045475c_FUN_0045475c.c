/*
 * FUN_0045475c at 0045475c
 * undefined FUN_0045475c(void)
 * Address ranges: 0045475c-00454780
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045475c(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d910 = _DAT_0047d910 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

