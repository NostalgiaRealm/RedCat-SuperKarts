/*
 * FUN_0044c9bc at 0044c9bc
 * undefined FUN_0044c9bc(void)
 * Address ranges: 0044c9bc-0044c9ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044c9bc(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0044c9ed;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d860 = _DAT_0047d860 + 1;
  if (_DAT_0047d860 == 0) {
    FUN_00405490((int *)&DAT_0047d864);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

