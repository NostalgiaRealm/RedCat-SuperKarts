/*
 * FUN_00470d78 at 00470d78
 * undefined __register FUN_00470d78(void)
 * Address ranges: 00470d78-00470d9c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00470d78(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e2d4 = _DAT_0047e2d4 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

