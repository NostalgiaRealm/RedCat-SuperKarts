/*
 * FUN_00468ad4 at 00468ad4
 * undefined FUN_00468ad4(void)
 * Address ranges: 00468ad4-00468af8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00468ad4(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_10;
  _DAT_0047e208 = _DAT_0047e208 + 1;
  *in_FS_OFFSET = uVar1;
  return;
}

