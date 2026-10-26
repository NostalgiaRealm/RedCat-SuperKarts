/*
 * FUN_00479cf8 at 00479cf8
 * undefined __register FUN_00479cf8(void)
 * Address ranges: 00479cf8-00479d1c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479cf8(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e5b0 = _DAT_0047e5b0 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

