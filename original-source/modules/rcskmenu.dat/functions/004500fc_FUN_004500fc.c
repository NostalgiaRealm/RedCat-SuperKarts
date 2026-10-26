/*
 * FUN_004500fc at 004500fc
 * undefined __register FUN_004500fc(void)
 * Address ranges: 004500fc-00450120
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004500fc(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d8e8 = _DAT_0047d8e8 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

