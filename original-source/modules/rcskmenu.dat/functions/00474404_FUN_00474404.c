/*
 * FUN_00474404 at 00474404
 * undefined __register FUN_00474404(void)
 * Address ranges: 00474404-00474428
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00474404(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e46c = _DAT_0047e46c + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

