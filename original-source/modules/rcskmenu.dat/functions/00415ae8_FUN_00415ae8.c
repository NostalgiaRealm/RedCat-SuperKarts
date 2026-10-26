/*
 * FUN_00415ae8 at 00415ae8
 * undefined FUN_00415ae8(void)
 * Address ranges: 00415ae8-00415b0c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415ae8(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d670 = _DAT_0047d670 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

