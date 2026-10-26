/*
 * FUN_0045d080 at 0045d080
 * undefined FUN_0045d080(void)
 * Address ranges: 0045d080-0045d0b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045d080(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0045d0b1;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047e198 = _DAT_0047e198 + 1;
  if (_DAT_0047e198 == 0) {
    FUN_00403b50(&DAT_0047e194);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

