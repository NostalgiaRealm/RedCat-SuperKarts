/*
 * FUN_00477390 at 00477390
 * undefined FUN_00477390(void)
 * Address ranges: 00477390-004773cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477390(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_004773cc;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e550 = _DAT_0047e550 + 1;
  if (_DAT_0047e550 == 0) {
    FUN_004043f8((VARIANTARG *)&PTR_DAT_0047c514,&DAT_004010b0,2);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

