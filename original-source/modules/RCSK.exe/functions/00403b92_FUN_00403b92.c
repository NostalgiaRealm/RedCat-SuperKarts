/*
 * FUN_00403b92 at 00403b92
 * undefined4 __cdecl FUN_00403b92(int * param_1)
 * Address ranges: 00403b92-00403b9f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00403b92(int *param_1)

{
  *param_1 = *param_1 + 4;
  return CONCAT22((short)((uint)*param_1 >> 0x10),*(undefined2 *)(*param_1 + -4));
}

