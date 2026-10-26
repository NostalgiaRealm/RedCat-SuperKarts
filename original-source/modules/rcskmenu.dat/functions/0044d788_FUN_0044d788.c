/*
 * FUN_0044d788 at 0044d788
 * undefined __register FUN_0044d788(void)
 * Address ranges: 0044d788-0044d7c3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044d788(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0044d7c4;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d884 = _DAT_0047d884 + 1;
  if (_DAT_0047d884 == 0) {
    FUN_004043f8((VARIANTARG *)&PTR_DAT_0047baf4,&DAT_004010b0,0x40);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

