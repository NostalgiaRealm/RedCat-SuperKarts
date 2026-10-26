/*
 * FUN_00415e61 at 00415e61
 * undefined __cdecl FUN_00415e61(uint param_1)
 * Address ranges: 00415e61-00415e90
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00415e61(uint param_1)

{
  if (param_1 != *(uint *)(DAT_0043db88 + 0x7c)) {
    FUN_00416d40(*(uint *)(DAT_0043db88 + 0x7c),param_1);
    *(uint *)(DAT_0043db88 + 0x7c) = param_1;
  }
  return;
}

