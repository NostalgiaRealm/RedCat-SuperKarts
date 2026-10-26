/*
 * FUN_00451ed0 at 00451ed0
 * undefined __register FUN_00451ed0(int param_1)
 * Address ranges: 00451ed0-00451ef0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00451ed0(int param_1)

{
  if (*(char *)(param_1 + 0x88) == '\0') {
    FUN_00451efc(param_1,0,*(int *)(param_1 + 0x40) + -1);
    return;
  }
  FUN_00417210(*(uint *)(param_1 + 0x84));
  return;
}

