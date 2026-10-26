/*
 * FUN_00457800 at 00457800
 * undefined FUN_00457800(void)
 * Address ranges: 00457800-0045783b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00457800(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0045783c;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e168 = _DAT_0047e168 + 1;
  if (_DAT_0047e168 == 0) {
    FUN_004043f8((VARIANTARG *)&PTR_s_REDCAT_0047c0a4,&DAT_004010b0,4);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

