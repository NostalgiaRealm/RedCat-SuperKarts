/*
 * FUN_00477340 at 00477340
 * undefined FUN_00477340(void)
 * Address ranges: 00477340-00477364
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477340(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e54c = _DAT_0047e54c + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

