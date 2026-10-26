/*
 * FUN_0041c220 at 0041c220
 * bool __cdecl FUN_0041c220(int param_1, int param_2)
 * Address ranges: 0041c220-0041c245
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __cdecl FUN_0041c220(int param_1,int param_2)

{
  return *(char *)(*(int *)(param_1 + 0xc) + 0xc) == param_2;
}

