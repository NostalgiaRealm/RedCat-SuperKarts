/*
 * FUN_00401ce8 at 00401ce8
 * undefined __register FUN_00401ce8(int param_1)
 * Address ranges: 00401ce8-00401d09
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401ce8(int param_1)

{
  _DAT_0047d424 = _DAT_0047d424 + 1;
  _DAT_0047d428 = _DAT_0047d428 + ((*(uint *)(param_1 + -4) & 0x7ffffffc) - 4);
  FUN_004022dc(param_1);
  return;
}

