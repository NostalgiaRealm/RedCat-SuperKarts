/*
 * FUN_00440ec8 at 00440ec8
 * undefined FUN_00440ec8(void)
 * Address ranges: 00440ec8-00440ef5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440ec8(int param_1,int param_2)

{
  if (*(char *)(param_1 + 0x4a) != '\0') {
    if (*(int *)(param_2 + 4) == 0) {
      FUN_0043f7d8(param_1,*(int *)(*(int *)(param_1 + 0x24) + 0x60));
    }
    else {
      FUN_0043f7d8(param_1,*(int *)(param_2 + 8));
    }
    *(undefined1 *)(param_1 + 0x4a) = 1;
  }
  return;
}

