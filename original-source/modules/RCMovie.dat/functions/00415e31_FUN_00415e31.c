/*
 * FUN_00415e31 at 00415e31
 * undefined __cdecl FUN_00415e31(uint param_1)
 * Address ranges: 00415e31-00415e60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00415e31(uint param_1)

{
  if (param_1 != *(uint *)(DAT_0043db88 + 0x78)) {
    FUN_00416d40(*(uint *)(DAT_0043db88 + 0x78),param_1);
    *(uint *)(DAT_0043db88 + 0x78) = param_1;
  }
  return;
}

