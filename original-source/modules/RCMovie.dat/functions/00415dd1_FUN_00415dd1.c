/*
 * FUN_00415dd1 at 00415dd1
 * undefined __cdecl FUN_00415dd1(uint param_1)
 * Address ranges: 00415dd1-00415e00
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00415dd1(uint param_1)

{
  if (param_1 != *(uint *)(DAT_0043db88 + 0x70)) {
    FUN_00416d40(*(uint *)(DAT_0043db88 + 0x70),param_1);
    *(uint *)(DAT_0043db88 + 0x70) = param_1;
  }
  return;
}

