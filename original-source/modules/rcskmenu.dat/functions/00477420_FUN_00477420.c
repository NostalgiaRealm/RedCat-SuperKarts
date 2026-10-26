/*
 * FUN_00477420 at 00477420
 * undefined FUN_00477420(void)
 * Address ranges: 00477420-00477465
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477420(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_00477466;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e554 = _DAT_0047e554 + 1;
  if (_DAT_0047e554 == 0) {
    FUN_00403b50((int *)&DAT_0047e558);
    FUN_004043f8((VARIANTARG *)&PTR_DAT_0047c51c,&DAT_004010b0,4);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

