/*
 * FUN_004561ac at 004561ac
 * undefined __register FUN_004561ac(void)
 * Address ranges: 004561ac-004561d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004561ac(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d93c = _DAT_0047d93c + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

