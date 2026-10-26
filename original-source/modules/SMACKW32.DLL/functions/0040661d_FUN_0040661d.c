/*
 * FUN_0040661d at 0040661d
 * undefined __cdecl FUN_0040661d(byte * param_1, int param_2, int param_3)
 * Address ranges: 0040661d-0040663f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040661d(byte *param_1,int param_2,int param_3)

{
  do {
    *param_1 = *(byte *)(param_3 + (uint)*param_1);
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  return;
}

