/*
 * FUN_004622d4 at 004622d4
 * undefined __register FUN_004622d4(void)
 * Address ranges: 004622d4-0046230f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004622d4(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_00462310;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e1c0 = _DAT_0047e1c0 + 1;
  if (_DAT_0047e1c0 == 0) {
    FUN_004043f8((VARIANTARG *)&DAT_0047c33c,"\x0e\x0eTStringKeyName\b",9);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

