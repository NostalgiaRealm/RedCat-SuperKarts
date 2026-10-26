/*
 * FUN_0041ab80 at 0041ab80
 * bool __cdecl FUN_0041ab80(int param_1, int param_2)
 * Address ranges: 0041ab80-0041aba5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __cdecl FUN_0041ab80(int param_1,int param_2)

{
  return *(char *)(*(int *)(param_1 + 0xc) + 0xc) == param_2;
}

