/*
 * FUN_00430ca9 at 00430ca9
 * int __register FUN_00430ca9(int param_1)
 * Address ranges: 00430ca6-00430cc2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00430ca9(int param_1)

{
  for (; (param_1 != 0 && (*(char *)(param_1 + 0x89) == '\0')); param_1 = *(int *)(param_1 + 0x24))
  {
  }
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0x20) & 0x10) != 0)) {
    param_1 = 0;
  }
  return param_1;
}

