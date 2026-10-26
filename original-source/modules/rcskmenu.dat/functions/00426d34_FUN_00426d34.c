/*
 * FUN_00426d34 at 00426d34
 * undefined __register FUN_00426d34(void)
 * Address ranges: 00426d34-00426d58
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00426d34(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d76c = _DAT_0047d76c + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

