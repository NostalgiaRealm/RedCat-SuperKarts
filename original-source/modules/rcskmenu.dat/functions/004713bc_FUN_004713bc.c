/*
 * FUN_004713bc at 004713bc
 * undefined __register FUN_004713bc(void)
 * Address ranges: 004713bc-004713e0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004713bc(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e2d8 = _DAT_0047e2d8 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

