/*
 * FUN_00440f30 at 00440f30
 * undefined __register FUN_00440f30(int param_1)
 * Address ranges: 00440f30-00440f54
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440f30(int param_1)

{
  if (*(char *)(param_1 + 0x8a) != '\0') {
    FUN_0043f790(param_1,*(char *)(*(int *)(param_1 + 0x24) + 0x89));
    *(undefined1 *)(param_1 + 0x8a) = 1;
  }
  return;
}

