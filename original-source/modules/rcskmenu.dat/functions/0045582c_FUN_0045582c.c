/*
 * FUN_0045582c at 0045582c
 * undefined FUN_0045582c(void)
 * Address ranges: 0045582c-0045585c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045582c(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0045585d;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d924 = _DAT_0047d924 + 1;
  if (_DAT_0047d924 == 0) {
    FUN_00402eac(DAT_0047d928);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

