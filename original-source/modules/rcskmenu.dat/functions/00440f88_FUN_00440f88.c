/*
 * FUN_00440f88 at 00440f88
 * undefined FUN_00440f88(void)
 * Address ranges: 00440f88-00440fa7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440f88(int param_1)

{
  if (*(char *)(param_1 + 0x46) != '\0') {
    FUN_0043f738(param_1);
    *(undefined1 *)(param_1 + 0x46) = 1;
  }
  return;
}

