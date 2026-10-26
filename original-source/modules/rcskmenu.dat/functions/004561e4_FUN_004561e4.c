/*
 * FUN_004561e4 at 004561e4
 * undefined FUN_004561e4(void)
 * Address ranges: 004561e4-0045621e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004561e4(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_0045621f;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d948 = _DAT_0047d948 + 1;
  if (_DAT_0047d948 == 0) {
    FUN_00405490((int *)&DAT_0047d944);
    FUN_00405490((int *)&DAT_0047d940);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

