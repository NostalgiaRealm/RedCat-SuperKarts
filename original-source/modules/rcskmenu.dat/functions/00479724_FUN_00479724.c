/*
 * FUN_00479724 at 00479724
 * undefined __register FUN_00479724(void)
 * Address ranges: 00479724-00479756
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479724(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_00479757;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e590 = _DAT_0047e590 + 1;
  if (_DAT_0047e590 == 0) {
    FUN_00402eac(*(int **)PTR_DAT_0047c740);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

