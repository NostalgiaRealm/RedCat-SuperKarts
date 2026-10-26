/*
 * FUN_0040bfc8 at 0040bfc8
 * undefined __register FUN_0040bfc8(int param_1)
 * Address ranges: 0040bfc8-0040bfe9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040bfc8(int param_1)

{
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
  if (*(int *)(param_1 + 0x20) == 0) {
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined1 *)(param_1 + 0x34) = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}

