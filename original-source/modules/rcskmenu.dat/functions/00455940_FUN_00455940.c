/*
 * FUN_00455940 at 00455940
 * undefined __register FUN_00455940(void)
 * Address ranges: 00455940-00455964
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00455940(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d930 = _DAT_0047d930 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

