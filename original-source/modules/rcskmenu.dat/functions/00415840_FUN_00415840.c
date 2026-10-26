/*
 * FUN_00415840 at 00415840
 * undefined __register FUN_00415840(void)
 * Address ranges: 00415840-00415864
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415840(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d650 = _DAT_0047d650 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

