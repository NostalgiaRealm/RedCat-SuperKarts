/*
 * FUN_00458ea4 at 00458ea4
 * undefined __register FUN_00458ea4(int param_1, uint param_2, undefined4 param_3)
 * Address ranges: 00458ea4-00458eab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00458ea4(int param_1,uint param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 4 + (param_2 & 0x7f) * 4) = param_3;
  return;
}

