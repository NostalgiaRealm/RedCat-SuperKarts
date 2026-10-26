/*
 * FUN_00403b75 at 00403b75
 * undefined4 __cdecl FUN_00403b75(int * param_1)
 * Address ranges: 00403b75-00403b81
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00403b75(int *param_1)

{
  *param_1 = *param_1 + 4;
  return *(undefined4 *)(*param_1 + -4);
}

