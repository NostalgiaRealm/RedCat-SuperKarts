/*
 * FUN_004581d0 at 004581d0
 * undefined __register FUN_004581d0(void)
 * Address ranges: 004581d0-004581f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004581d0(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e170 = _DAT_0047e170 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

