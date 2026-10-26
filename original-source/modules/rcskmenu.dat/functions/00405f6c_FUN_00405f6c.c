/*
 * FUN_00405f6c at 00405f6c
 * undefined __register FUN_00405f6c(void)
 * Address ranges: 00405f6c-00405fc9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00405f6c(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_00405fca;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d42c = _DAT_0047d42c + 1;
  if (_DAT_0047d42c == 0) {
    FUN_0040580c(&DAT_0047d050);
    FUN_0040580c(&DAT_0047d21c);
    FUN_00401b44();
    FUN_00404c68((VARIANTARG *)&DAT_0047d414);
    FUN_00404c68((VARIANTARG *)&DAT_0047d404);
    FUN_00404c68((VARIANTARG *)&DAT_0047d3f4);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

