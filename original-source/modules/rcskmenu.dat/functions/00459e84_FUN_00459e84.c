/*
 * FUN_00459e84 at 00459e84
 * undefined FUN_00459e84(void)
 * Address ranges: 00459e84-00459ed4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00459e84(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_00459ed5;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e180 = _DAT_0047e180 + 1;
  if (_DAT_0047e180 == 0) {
    FUN_004043f8((VARIANTARG *)&PTR_s_RIS_DIFFICULTY_TEXT_0047c230,&DAT_004010b0,0x21);
    FUN_004043f8((VARIANTARG *)&PTR_s_RS_EMPTY_0047c0e4,&DAT_004010b0,0x53);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

