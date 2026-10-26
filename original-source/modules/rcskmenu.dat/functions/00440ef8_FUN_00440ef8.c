/*
 * FUN_00440ef8 at 00440ef8
 * undefined FUN_00440ef8(void)
 * Address ranges: 00440ef8-00440f17
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440ef8(int *param_1)

{
  if ((char)param_1[0x14] != '\0') {
    if (param_1[9] != 0) {
      (**(code **)(*param_1 + 0x68))(param_1,*(undefined1 *)(param_1[9] + 0x4f));
    }
    *(undefined1 *)(param_1 + 0x14) = 1;
  }
  return;
}

