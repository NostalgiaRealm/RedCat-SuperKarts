/*
 * FUN_00457020 at 00457020
 * undefined FUN_00457020(void)
 * Address ranges: 00457020-00457060
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00457020(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_00457061;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d950 = _DAT_0047d950 + 1;
  if (_DAT_0047d950 == 0) {
    FUN_00456fdc();
    FUN_004043f8((VARIANTARG *)&DAT_0047bd34,"\x0e\x17TDirectDrawErrorMessage\b",0x6e);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

