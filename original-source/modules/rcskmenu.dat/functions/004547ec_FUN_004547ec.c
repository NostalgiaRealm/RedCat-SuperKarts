/*
 * FUN_004547ec at 004547ec
 * undefined __register FUN_004547ec(int param_1, uint param_2, uint param_3, undefined1 param_4)
 * Address ranges: 004547ec-00454804
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004547ec(int param_1,uint param_2,uint param_3,undefined1 param_4)

{
  *(undefined1 *)(param_1 + (param_2 & 0x7f) * 5 + 4 + (param_3 & 0x7f)) = param_4;
  return;
}

