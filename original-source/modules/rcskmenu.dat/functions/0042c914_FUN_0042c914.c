/*
 * FUN_0042c914 at 0042c914
 * undefined __register FUN_0042c914(int param_1, char param_2)
 * Address ranges: 0042c914-0042c92d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042c914(int param_1,char param_2)

{
  if ((param_2 != *(char *)(param_1 + 0x218)) &&
     (*(char *)(param_1 + 0x218) = param_2, (*(byte *)(param_1 + 0x20) & 0x10) == 0)) {
    FUN_00442cd4(param_1);
  }
  return;
}

