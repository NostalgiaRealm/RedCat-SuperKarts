/*
 * FUN_0045366c at 0045366c
 * undefined __register FUN_0045366c(void)
 * Address ranges: 0045366c-00453690
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045366c(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047d900 = _DAT_0047d900 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

