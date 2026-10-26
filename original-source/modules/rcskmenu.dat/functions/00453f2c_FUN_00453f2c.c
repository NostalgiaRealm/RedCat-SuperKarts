/*
 * FUN_00453f2c at 00453f2c
 * undefined FUN_00453f2c(void)
 * Address ranges: 00453f2c-00453f67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00453f2c(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_00453f68;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d908 = _DAT_0047d908 + 1;
  if (_DAT_0047d908 == 0) {
    FUN_004043f8((VARIANTARG *)&PTR_s_TGS_NONE_0047bc58,&DAT_004010b0,4);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

