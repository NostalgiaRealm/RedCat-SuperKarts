/*
 * FUN_0041b3a0 at 0041b3a0
 * bool __cdecl FUN_0041b3a0(int param_1, int param_2)
 * Address ranges: 0041b3a0-0041b3c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __cdecl FUN_0041b3a0(int param_1,int param_2)

{
  return *(char *)(*(int *)(param_1 + 0xc) + 0x1c) == param_2;
}

