/*
 * FUN_004772dc at 004772dc
 * undefined __register FUN_004772dc(void)
 * Address ranges: 004772dc-0047732c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004772dc(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0047732d;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e4c0 = _DAT_0047e4c0 + 1;
  if (_DAT_0047e4c0 == 0) {
    FUN_004043f8((VARIANTARG *)&DAT_0047e524,&DAT_004010b0,10);
    FUN_004043f8((VARIANTARG *)&DAT_0047e4c4,"\x0e\x0eTCountryImages\x10",6);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

