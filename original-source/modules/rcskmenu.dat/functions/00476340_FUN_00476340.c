/*
 * FUN_00476340 at 00476340
 * undefined __register FUN_00476340(void)
 * Address ranges: 00476340-004763ba
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00476340(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_004763bb;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e474 = _DAT_0047e474 + 1;
  if (_DAT_0047e474 == 0) {
    FUN_004043f8((VARIANTARG *)&DAT_0047e4ac,&DAT_004010b0,5);
    FUN_004043f8((VARIANTARG *)&DAT_0047e498,&DAT_004010b0,5);
    FUN_004043f8((VARIANTARG *)&DAT_0047e488,&DAT_004010b0,4);
    FUN_004043f8((VARIANTARG *)&DAT_0047e478,&DAT_004010b0,4);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

