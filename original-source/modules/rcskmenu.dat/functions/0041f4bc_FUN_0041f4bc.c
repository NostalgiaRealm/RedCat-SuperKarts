/*
 * FUN_0041f4bc at 0041f4bc
 * undefined FUN_0041f4bc(void)
 * Address ranges: 0041f4bc-0041f4ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041f4bc(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0041f4ed;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d720 = _DAT_0047d720 + 1;
  if (_DAT_0047d720 == 0) {
    FUN_00402eac(DAT_0047b628);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

