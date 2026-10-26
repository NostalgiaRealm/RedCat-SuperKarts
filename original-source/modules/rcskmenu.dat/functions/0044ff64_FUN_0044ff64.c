/*
 * FUN_0044ff64 at 0044ff64
 * undefined FUN_0044ff64(void)
 * Address ranges: 0044ff64-0044ff9f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044ff64(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0044ffa0;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d8dc = _DAT_0047d8dc + 1;
  if (_DAT_0047d8dc == 0) {
    FUN_004043f8((VARIANTARG *)&PTR_DAT_0047bc00,&DAT_004010b0,2);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

