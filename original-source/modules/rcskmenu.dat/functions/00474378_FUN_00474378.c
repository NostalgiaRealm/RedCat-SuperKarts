/*
 * FUN_00474378 at 00474378
 * undefined FUN_00474378(void)
 * Address ranges: 00474378-004743c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00474378(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_004743c9;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e448 = _DAT_0047e448 + 1;
  if (_DAT_0047e448 == 0) {
    FUN_004043f8((VARIANTARG *)&DAT_0047e45c,&DAT_004010b0,4);
    FUN_004043f8((VARIANTARG *)&DAT_0047e44c,&DAT_004010b0,4);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

