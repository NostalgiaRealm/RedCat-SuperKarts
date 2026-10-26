/*
 * FUN_0044cf74 at 0044cf74
 * undefined __register FUN_0044cf74(void)
 * Address ranges: 0044cf74-0044cf9f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044cf74(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0044cfa0;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d86c = _DAT_0047d86c + 1;
  if (_DAT_0047d86c == 0) {
    FUN_0044cf68();
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

