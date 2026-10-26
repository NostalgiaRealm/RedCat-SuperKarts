/*
 * FUN_00460f4c at 00460f4c
 * undefined FUN_00460f4c(void)
 * Address ranges: 00460f4c-00460f70
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00460f4c(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e1bc = _DAT_0047e1bc + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

