/*
 * FUN_0045707c at 0045707c
 * undefined __register FUN_0045707c(void)
 * Address ranges: 0045707c-004570b6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045707c(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_004570b7;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e158 = _DAT_0047e158 + 1;
  if (_DAT_0047e158 == 0) {
    FUN_00402eac(DAT_0047e15c);
    FUN_00402eac(DAT_0047e160);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

