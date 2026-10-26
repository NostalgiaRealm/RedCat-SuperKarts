/*
 * FUN_00415e01 at 00415e01
 * undefined __cdecl FUN_00415e01(uint param_1)
 * Address ranges: 00415e01-00415e30
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00415e01(uint param_1)

{
  if (param_1 != *(uint *)(DAT_0043db88 + 0x74)) {
    FUN_00416d40(*(uint *)(DAT_0043db88 + 0x74),param_1);
    *(uint *)(DAT_0043db88 + 0x74) = param_1;
  }
  return;
}

