/*
 * FUN_0042215a at 0042215a
 * undefined4 __cdecl FUN_0042215a(int * param_1)
 * Address ranges: 0042215a-00422167
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0042215a(int *param_1)

{
  *param_1 = *param_1 + 4;
  return CONCAT22((short)((uint)*param_1 >> 0x10),*(undefined2 *)(*param_1 + -4));
}

