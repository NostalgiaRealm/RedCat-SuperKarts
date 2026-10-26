/*
 * FUN_0044e854 at 0044e854
 * undefined FUN_0044e854(void)
 * Address ranges: 0044e854-0044e884
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044e854(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0044e885;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d8d4 = _DAT_0047d8d4 + 1;
  if (_DAT_0047d8d4 == 0) {
    FUN_0040bfec(&DAT_0047bbfc);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

