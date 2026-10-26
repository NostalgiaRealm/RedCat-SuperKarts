/*
 * FUN_00455028 at 00455028
 * undefined FUN_00455028(void)
 * Address ranges: 00455028-00455055
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00455028(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d91c = _DAT_0047d91c + 1;
  if (_DAT_0047d91c == 0) {
    DAT_0047d920 = 0;
  }
  *in_FS_OFFSET = uVar1;
  return;
}

