/*
 * FUN_0040d764 at 0040d764
 * undefined __register FUN_0040d764(void)
 * Address ranges: 0040d764-0040d7a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040d764(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0040d7aa;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d614 = _DAT_0047d614 + 1;
  if (_DAT_0047d614 == 0) {
    FUN_00403b50((int *)&PTR_DAT_0047b310);
    FUN_004043f8((VARIANTARG *)&PTR_s_False_0047b308,&DAT_004010b0,2);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

