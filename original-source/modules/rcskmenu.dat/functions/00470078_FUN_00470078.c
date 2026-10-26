/*
 * FUN_00470078 at 00470078
 * undefined __register FUN_00470078(void)
 * Address ranges: 00470078-004700b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00470078(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_004700b4;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e23c = _DAT_0047e23c + 1;
  if (_DAT_0047e23c == 0) {
    FUN_004043f8((VARIANTARG *)&DAT_0047e240,"\x0e\x0eTCountryImages\x10",6);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

