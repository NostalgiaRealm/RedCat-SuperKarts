/*
 * FUN_0046f060 at 0046f060
 * undefined __register FUN_0046f060(void)
 * Address ranges: 0046f060-0046f084
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046f060(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e234 = _DAT_0047e234 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

