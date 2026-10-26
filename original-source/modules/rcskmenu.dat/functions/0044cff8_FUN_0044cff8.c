/*
 * FUN_0044cff8 at 0044cff8
 * undefined __register FUN_0044cff8(void)
 * Address ranges: 0044cff8-0044d023
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044cff8(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0044d024;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d874 = _DAT_0047d874 + 1;
  if (_DAT_0047d874 == 0) {
    FUN_0044cfec();
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

