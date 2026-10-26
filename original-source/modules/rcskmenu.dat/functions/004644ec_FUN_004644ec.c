/*
 * FUN_004644ec at 004644ec
 * undefined __register FUN_004644ec(void)
 * Address ranges: 004644ec-00464510
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004644ec(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e1ec = _DAT_0047e1ec + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

