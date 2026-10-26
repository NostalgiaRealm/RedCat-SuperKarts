/*
 * FUN_00464524 at 00464524
 * undefined FUN_00464524(void)
 * Address ranges: 00464524-00464548
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00464524(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e1f0 = _DAT_0047e1f0 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

