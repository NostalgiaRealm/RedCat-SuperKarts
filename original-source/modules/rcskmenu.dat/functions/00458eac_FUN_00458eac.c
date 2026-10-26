/*
 * FUN_00458eac at 00458eac
 * undefined4 __register FUN_00458eac(int param_1, uint param_2)
 * Address ranges: 00458eac-00458eb3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00458eac(int param_1,uint param_2)

{
  return *(undefined4 *)(param_1 + 4 + (param_2 & 0x7f) * 4);
}

