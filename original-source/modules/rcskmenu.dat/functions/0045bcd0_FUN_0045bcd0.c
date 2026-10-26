/*
 * FUN_0045bcd0 at 0045bcd0
 * undefined FUN_0045bcd0(void)
 * Address ranges: 0045bcd0-0045bd20
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045bcd0(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0045bd21;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e188 = _DAT_0047e188 + 1;
  if (_DAT_0047e188 == 0) {
    FUN_004043f8((VARIANTARG *)&PTR_s_SR320x200x8_0047c2c0,&DAT_004010b0,6);
    FUN_004043f8((VARIANTARG *)&PTR_s_KEYBOARD_0047c2b4,&DAT_004010b0,3);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

