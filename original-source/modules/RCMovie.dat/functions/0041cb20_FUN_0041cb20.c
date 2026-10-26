/*
 * FUN_0041cb20 at 0041cb20
 * bool __cdecl FUN_0041cb20(int param_1, int param_2)
 * Address ranges: 0041cb20-0041cb45
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __cdecl FUN_0041cb20(int param_1,int param_2)

{
  return *(char *)(*(int *)(param_1 + 0xc) + 0xc) == param_2;
}

