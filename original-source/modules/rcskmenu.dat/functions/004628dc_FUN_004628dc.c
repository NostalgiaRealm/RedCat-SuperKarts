/*
 * FUN_004628dc at 004628dc
 * undefined FUN_004628dc(void)
 * Address ranges: 004628dc-00462900
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004628dc(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e1e4 = _DAT_0047e1e4 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

