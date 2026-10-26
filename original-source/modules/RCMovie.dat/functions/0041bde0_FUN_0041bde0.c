/*
 * FUN_0041bde0 at 0041bde0
 * bool __cdecl FUN_0041bde0(int param_1, int param_2)
 * Address ranges: 0041bde0-0041be05
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __cdecl FUN_0041bde0(int param_1,int param_2)

{
  return *(char *)(*(int *)(param_1 + 0xc) + 0x10) == param_2;
}

